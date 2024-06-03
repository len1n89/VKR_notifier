#include "incident.h"
#include "subject.h"

#include <QDebug>
#include <QDate>
#include <QTime>

Incident::Incident(IncidentType type)
    : m_confirmed(false)
    , m_type(type)
    , m_message(Message())
    , m_watchers(QList<Watcher*>())
    , m_sendTimer(new QTimer())
{
    m_sendTimer->setSingleShot(false);
    connect(m_sendTimer, &QTimer::timeout, this, &Incident::onSendTimer);
    connect(this, &Incident::incidentOpenned, this, &Incident::onIncidentOpenned);
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
    text.append(m_type); //to STRING!!!!!
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

void Incident::setWatchers(const QList<Watcher *> list)
{
    m_watchers = list;
}

void Incident::onIncidentOpenned()
{
    // запустить таймер отправки
     m_sendTimer->start(5000);
}

void Incident::onSendTimer()
{
    qDebug()<<"---onSendTimer";
    //! Если инцидент подтвержден, то не отправлять сообщения
     if(confirmed())
        return;

     //Для каждого наблюдателя данного инцидента
     for(int i = 0; i < m_watchers.size(); i++) {
         QHashIterator<Watcher::ContactType, QString> contactsIter(m_watchers.at(i)->getContacts());

         // для каждого контакта наблюдателя вызываем метод отправки
         while (contactsIter.hasNext()) {
             contactsIter.next();
             QString address = contactsIter.value();
             m_message.send(address);
         }
     }

     // если будет несколько классов сообщений, то нужно будет выбирать определенный объект
     // сообщения по типу контакта
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
