#ifndef MESSENGER_H
#define MESSENGER_H

#include<QObject>

//! \class Messenger
//! \brief Класс Messenger занимается отправкой сообщений


class Messenger : public QObject
{
    Q_OBJECT

public:
    Messenger();
    virtual ~Messenger();

    //! Public functions
public:
    //! \brief Отправить сообщение
//    void sendMessage();

private:
};

#endif // MESSENGER_H
