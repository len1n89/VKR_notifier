#include "client.h"

#include <QTcpSocket>
#include <QDataStream>
#include <QTimer>
#include <QHostInfo>

#include <QDebug>

const static int TRY_COUNT = 5;

Client::Client()
    : QObject()
    , m_tryCount(TRY_COUNT)
    , m_status(false)
    , m_nNextBlockSize(0)
    , m_tcpSocket(new QTcpSocket())
    , m_timeoutTimer(new QTimer())
{
    m_timeoutTimer->setSingleShot(false);
    connect(m_timeoutTimer, &QTimer::timeout, this, &Client::connectionTimeout);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &Client::closeConnection);
}

void Client::connectToServer(const QString address, int port)
{
    m_timeoutTimer->start(1000); // передать интервал
    m_tcpSocket->connectToHost(address, port);

    connect(m_tcpSocket, &QTcpSocket::connected, this, &Client::connected);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &Client::readyRead);
}

void Client::setStatus(bool status)
{
    if(m_status == status)
        return;

    m_status = status;
    emit statusChanged(m_status);
}

void Client::closeConnection()
{
    disconnect(m_tcpSocket, &QTcpSocket::connected, 0, 0);
    disconnect(m_tcpSocket, &QTcpSocket::readyRead, 0, 0);

    if(m_tcpSocket->state() == QTcpSocket::UnconnectedState) {
        m_tcpSocket->disconnectFromHost();
        setStatus(false);
    }
    else if(m_tcpSocket->state() == QTcpSocket::ConnectingState) {
        m_tcpSocket->abort();
        setStatus(false);
    }
    else
        m_tcpSocket->abort();
}

qint64 Client::sendToServer(QTcpSocket *socket, const QString &str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    return socket->write(arrBlock);
}

void Client::readyRead()
{
    QDataStream in(m_tcpSocket);

    for (;;)
    {
        if (!m_nNextBlockSize)
        {
            if (m_tcpSocket->bytesAvailable() < sizeof(quint16))
                break;
            in >> m_nNextBlockSize;
        }

        if (m_tcpSocket->bytesAvailable() < m_nNextBlockSize)
            break;

        QString str;
        in >> str;

        if (str == "0")
        {
            str = "Connection closed";
            closeConnection();
        }

//        emit hasReadSome(str);
        qDebug()<<"FROM SERVER: "<<str;
        m_nNextBlockSize = 0;
    }
}

void Client::connected()
{
//    m_tryCount = TRY_COUNT;
    setStatus(true);
    sendToServer(m_tcpSocket, QHostInfo::localHostName());
}

void Client::connectionTimeout()
{
//    qDebug() <<"connectionTimeout = "<<m_tcpSocket->state();

    switch (m_tcpSocket->state()) {
    case QAbstractSocket::ConnectedState:
        qDebug()<<"ConnectedState";
        // Подключено
        m_timeoutTimer->stop();
        m_tryCount = TRY_COUNT;
        break;

    case QAbstractSocket::ConnectingState:
        // Если все еще подключается то отрубить
        qDebug()<<"...ConnectingState";
        m_timeoutTimer->stop();
        closeConnection();

        if(m_tryCount == 0){
            setStatus(false);
            m_tryCount = TRY_COUNT;
            emit connetionFailed();
        }
        else {
            m_tryCount--;
            connectToServer("localhost", 6547);
        }
//        m_tcpSocket->abort();
        emit m_tcpSocket->error(QAbstractSocket::SocketTimeoutError);
        break;

    case QAbstractSocket::UnconnectedState:
        // Если не удалось подключиться
        qDebug()<<"UnconnectedState";
        m_timeoutTimer->stop();
        closeConnection();

        if(m_tryCount == 0){
            setStatus(false);
            m_tryCount = TRY_COUNT;
            emit connetionFailed();
        }
        else {
            m_tryCount--;
            connectToServer("localhost", 6547);
        }

    default:
        break;
    }
}
