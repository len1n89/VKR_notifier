#ifndef MESSAGE_H
#define MESSAGE_H
#include<QObject>

//! \class Message
//! \brief Класс Message представляет сообщение

class Client;

class Message : public QObject
{
    Q_OBJECT

public:
    Message();
    virtual ~Message();

public:
    //! \brief Отправить данное сообщение на указанный адрес
    void send(const QString &addr);

    //! Getters
public:
    //! \brief Возвращает содержание письма
    QString getTitle() const;

    //! \brief Возвращает содержание письма
    QString getBody() const;

    //! Setters
public:
    //! \brief Установить тему письма
    void setTitle(const QString &text);

    //! \brief Установить содержание письма
    void setBody(const QString &text);

private:
    //! \brief Тема письма
    QString m_title;

    //! \brief Содержание письма
    QString m_body;
};
#endif // MESSAGE_H
