#include "watcher.h"

Watcher::Watcher()
    : m_contacs(QHash<ContactType, QString>())
{

}

Watcher::~Watcher()
{

}

void Watcher::addContact(Watcher::ContactType type, const QString address)
{
    m_contacs.insert(type, address);
}

QHash<Watcher::ContactType, QString> Watcher::getContacts() const
{
    return m_contacs;
}
