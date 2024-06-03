#ifndef MESSENGER_H
#define MESSENGER_H

#include<QObject>

//! \class Messenger
//! \brief Класс Messenger занимается отправкой сообщений
//! Ему передается сообщение и список контактов наблюдателей

class Messenger : public QObject
{
    Q_OBJECT

public:
    Messenger();
    virtual ~Messenger();

    //! Public functions
public:
    //! \brief Отправить сообщение
//    void sendMessage(const Message &message, const Contacts &contacts);

private:
};

#endif // MESSENGER_H
