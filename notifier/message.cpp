#include "message.h"
#include <QDebug>
#include <QTime>

Message::Message()
    : m_title("")
    , m_body("")
{

}

Message::~Message()
{
//    qDebug()<<"~Message";
}

void Message::send(const QString &addr)
{
    QTime qtime;
    QString time = qtime.currentTime().toString();

    qDebug()<<time<<"Message::send************************************";
    qDebug()<<addr;
    qDebug()<<m_title;
    qDebug()<<m_body;
    qDebug()<<"*******************************************************";
}

QString Message::getTitle() const
{
    return m_title;
}

QString Message::getBody() const
{
    return m_body;
}

void Message::setTitle(const QString &text)
{
    m_title = text;
}

void Message::setBody(const QString &text)
{
    m_body = text;
}
