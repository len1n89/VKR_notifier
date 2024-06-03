#include "incident.h"
#include "subject.h"

#include <QDebug>
#include <QDate>
#include <QTime>

Incident::Incident(IncidentType type)
    : m_type(type)
    , m_confirmed(false)
    , m_message(Message())
{

}

Incident::~Incident()
{
    qDebug()<<"~Incident";
}

bool Incident::createMessage(const QString &name, const QString &ip)
{
    QString text = "Alert! Subject ";
    text.append(name);
    text.append(" : ");
    text.append(ip);
    m_message.setTitle(text);

    QTime qtime;
    QString time = qtime.currentTime().toString();
    text = "Alert! Subject ";
    text.append(name);
    text.append(" : ");
    text.append(ip);
    text.append("; Status: ");
    text.append(m_type); //to STRING!!
    text.append(" : ");
    text.append(time);

    m_message.setBody(text);
    qDebug()<<"NEW MESSAGE: "<<m_message.getTitle();
    qDebug()<<"BODY: "<<m_message.getBody();
}

int Incident::getId() const
{

}

bool Incident::confirmed() const
{
    return m_confirmed;
}

Incident::IncidentType Incident::type() const
{
    return m_type;
}

void Incident::setId(int id)
{

}

void Incident::confirm()
{
    m_confirmed = true;
    emit confirmedChanged();
}
