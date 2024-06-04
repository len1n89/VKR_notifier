#include "incident.h"
#include "subject.h"

#include <QDebug>
#include <QDate>
#include <QTime>
#include<QMetaEnum>

const static int SEND_TIMOUT = 5000;

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
    QString text = "Alert! ";
    text.append(name);
    text.append(": ");
    text.append(ip);
    m_message.setTitle(text);
    //m_tgMessage
    //m_mailMessage
    //m_phoneMessage

    QTime qtime;
    QString time = qtime.currentTime().toString();

    QMetaEnum metaEnum = QMetaEnum::fromType<Incident::IncidentType>();
    text = metaEnum.valueToKey(Incident::m_type);
    text.append(": ");
    text.append(name);
    text.append(": ");
    text.append(ip);
    text.append(": ");
    text.append(time);

    m_message.setBody(text);
    qDebug()<<"NEW MESSAGE: "<<m_message.getTitle();
    qDebug()<<"BODY: "<<m_message.getBody();
}

void Incident::resolve()
{

    // Формировка сообщения
    QString title =  m_message.getTitle();
    title.prepend("RESOLVED: ");
    QString body =  m_message.getBody();
    QTime qtime;
    QString time = qtime.currentTime().toString();
    body.prepend("Incident has been RESOLVED at " + time + " ");

    m_message.setTitle(title);
    m_message.setBody(body);

    //Для каждого наблюдателя данного инцидента
    for(int i = 0; i < m_watchers.size(); i++) {
        QHashIterator<Watcher::ContactType, QString> contactsIter(m_watchers.at(i)->getContacts());

        // для каждого контакта наблюдателя отправляем сообщение о разрешении
        while (contactsIter.hasNext()) {
            contactsIter.next();
            QString address = contactsIter.value();
            m_message.send(address);
        }
    }
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
     m_sendTimer->start(SEND_TIMOUT);
}

void Incident::onSendTimer()
{
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
     // сообщения по типу контакта из списка QList<Message> m_messages

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
}
