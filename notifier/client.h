#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QTcpSocket;
class QTimer;

const static int TRY_COUNT = 5;

//! \class Client
//! \brief Класс для подключения к серверу
//! Один клиент - одно подключение
//! Содержит в себе экземпляр субъекта к которому нужно подключаться

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    ~Client(){}

public:
    void connectToServer(const QString address, int port);

public:
    void setStatus(bool status);

public slots:
    void closeConnection();
    qint64 sendToServer(QTcpSocket *socket, const QString &str);

signals:
    void statusChanged(bool status);
    void connectionError();
    void connetionFailed();

private slots:
    void readyRead();
    void connected();
    void connectionTimeout();

private:
    int m_tryCount;
    bool m_status;
    quint16 m_nNextBlockSize;
    QTcpSocket *m_tcpSocket;
    QTimer *m_timeoutTimer;
};

#endif // CLIENT_H
