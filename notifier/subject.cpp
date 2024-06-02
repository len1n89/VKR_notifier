#include "subject.h"
#include "client.h"

#include <QDebug>

Subject::Subject()
    : m_tryTimeout(1000)
    , m_port(0)
    , m_name("")
    , m_ipAddress("")
    , m_tcpClient(new Client())
    , m_status(Disconnected)
    , m_error(NoError)
{
    connect(m_tcpClient, &Client::statusChanged, this, &Subject::onConnectionStatusChanged);
}

Subject::~Subject()
{

}

bool Subject::tryToConnect()
{
    // пытается подключиться пока не вышло время
    // если не получилось то фолс

    m_tcpClient->connectToServer(m_ipAddress, m_port);

    return true;
}

void Subject::setTryTimeout(int time)
{
    if(m_tryTimeout == time)
        return;

    m_tryTimeout = time;
    emit tryTimeoutChanged();
}

void Subject::setName(const QString &name)
{
    if(m_name == name)
        return;

    m_name = name;
    emit nameChanged();
}

void Subject::setIpAddress(const QString &ip)
{
    if(m_ipAddress == ip)
        return;

    m_ipAddress = ip;
    emit ipAddressChanged();
}

void Subject::setPort(int port)
{
    if(m_port == port)
        return;

    m_port = port;
    emit portChanged();
}

void Subject::setStatus(Subject::Status status)
{
    if(m_status == status)
        return;

    m_status = status;
    emit statusChanged();
}

void Subject::onConnectionStatusChanged(bool status)
{
    if(status){
        qDebug()<<"Subject connected!";
        setStatus(Connected);
    }
    else {
        qDebug()<<"Subject NOT connected!";
        setStatus(Disconnected);
    //
    }
}
