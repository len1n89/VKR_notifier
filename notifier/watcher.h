#ifndef WATCHER_H
#define WATCHER_H
#include<QObject>
#include<QHash>

//! \class Watcher
//! \brief Класс представляющий наблюдателя(подписчик) инцидента
//! Если этот инцидент произошел, то для каждого Watcher отправить сообщение для каждого контакта

class Watcher : public QObject
{
    Q_OBJECT

public:
    enum ContactType {
        Telegram    = 0,
        Phone       = 1,
        Mail        = 2
    };
    Q_ENUM(ContactType)

    Watcher();
    virtual ~Watcher();

    //! Public functions
public:
    //! \brief Добавить новый контакт
    void addContact(ContactType type, const QString address);

private:
    //! \brief Таблица контактов. Тип : Контакт
    QHash<ContactType, QString> m_contacs;
};
#endif // WATCHER_H
