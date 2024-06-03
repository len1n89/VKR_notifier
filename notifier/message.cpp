#include "message.h"
#include <QDebug>

Message::Message()
    : m_title("")
    , m_body("")
{

}

Message::~Message()
{
    qDebug()<<"~Message";
}

void Message::send(const QString &addr)
{
    qDebug()<<"Message::send : "<<addr<<" : "<<m_title<<" :: "<<m_body;
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
