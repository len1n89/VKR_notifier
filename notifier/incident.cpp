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
    //m_tgMessage
    //m_mailMessage
    //m_phoneMessage

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

void Incident::onIncidentOpenned() // Messenger *mesr, Contacts
{
    // запустить таймер отправки

    // по таймеру
    // if(!confirmed)
    //  m_messenger->sendMessage(m_message, contacts)
    //
    //
    //Для каждого наблюдателя данного иныидента
    // для каждого контакта наблюдателя вызываем метод отправки
//    foreach(watcher in m_watchers) {
//        foreach (m_watcher.contacts()) {
//          switch (contact.type()) {
//              case TelegramType:
//                  m_tgMessage.send(watcher.telegramAddr())
//                  break;
//              case MailType:
//                  m_mailMessage.send(watcher.mailAddr())
//                  break;
//              default:
//                  break;
//          }
//        }
//    }
}
