#include "subject.h"
#include "client.h"
//#include "incident.h"

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
    connect(m_tcpClient, &Client::connetionFailed, this, &Subject::onConnectionFailed);
}

Subject::~Subject()
{

}

bool Subject::tryToConnect()
{
    m_tcpClient->connectToServer(m_ipAddress, m_port);

    return true;
}

bool Subject::connected()
{

}

bool Subject::containsIncident(Incident::IncidentType type)
{
    Incident *incident;
    for(int i = 0; i < m_incidentList.size(); i++) {
        incident = m_incidentList.at(i);
        if(incident->type() == type)
            return true;
    }

    return false;
}

void Subject::openIncident(Incident::IncidentType type)
{
    qDebug()<<"***openIncident";
    Incident *inc = new Incident(type);

    // Передать соответствующий список наблюдателей в инцидент
    inc->setWatchers(m_watchers.value(type));

    // new message
    inc->createMessage(m_name, m_ipAddress);

    //! создавать сообщение для каждого типа отправки
    //! inc->createMailMessage(m_name, m_ipAddress);
    //! inc->createTelegramMessage(m_name, m_ipAddress);
    //! inc->createPhone(m_name, m_ipAddress);

    m_incidentList.append(inc);

    emit inc->incidentOpenned();
}

void Subject::closeIncident(Incident::IncidentType type)
{
    qDebug()<<"***closeIncident";
    Incident *incident;
    for(int i = 0; i < m_incidentList.size(); i++) {
        incident = m_incidentList.at(i);
        if(incident->type() == type) {
            m_incidentList.removeAt(i);
            incident->~Incident();

            emit incidentClosed();
            return;
        }
    }
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

void Subject::setWatchers(Incident::IncidentType type, QList<Watcher*> watchers)
{
    m_watchers.insert(type, watchers);
}

void Subject::onConnectionStatusChanged(bool status)
{
    if(status){
        qDebug()<<"Subject connected!";
        setStatus(Connected);
        // TODO запрос остояния сервера/ а потом проверка DBNotConnectedToServer

        // Если инцидент есть - то закрыть его
        if(this->containsIncident(Incident::ServerNotConnected)) {
            qDebug()<<"onConnectionFailed containsIncident";
            closeIncident(Incident::ServerNotConnected);


        }
    }
    else {
        qDebug()<<"Subject Disconnected!";
        setStatus(Disconnected);

        // Если отрубило - попытка подключить
        tryToConnect();
    }
}

void Subject::onConnectionFailed()
{
    //! Не удачная попытка подключиться
    setStatus(Disconnected);

    //! Открыть или не открыть инцидент
    if(!this->containsIncident(Incident::ServerNotConnected)) {
        qDebug()<<"onConnectionFailed !containsIncident";
        // если в списке нет инц-та с типом ServerNotConnected - создать новый и добавить в список
        openIncident(Incident::ServerNotConnected);
        tryToConnect();
    }
    else
        //! Если инцидент уже есть - то просто продолжать попытки подключения
        tryToConnect();
}
