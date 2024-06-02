#ifndef SUBJECT_H
#define SUBJECT_H

#include<QObject>

//! \class Subject
//! \brief Наблюдаемый субъект, т.е. сервер за которым наблюдает notifier

class Client;

class Subject : public QObject
{
    Q_OBJECT

    enum Status {
        // изменить
        Connected       = 0,
        Disconnected    = 1,
        Error           = 2
    };

    enum Error {
        NoError         = 0,
        DBDisconnected  = 1,
        DBError         = 2,
        OtherError      = 3
    };

public:
    Subject();
    virtual ~Subject();

public:
    //! \brief Попытка подключиться к субъекту
    bool tryToConnect();

    //! \brief возвращает статус подключения
    bool connected();

    //! Getters
public:

    //! Setters
public:
    //! \brief Установить попытоки подключения
    void setTryTimeout(int time);

    //! \brief Установить имя сервера
    void setName(const QString &name);

    //! \brief Установить ip адрес сервера
    void setIpAddress(const QString &ip);

    //! \brief Установить порт сервера
    void setPort(int port);

    //! \brief Установить статус сервера
    void setStatus(Status status);

signals:
    void tryTimeoutChanged();
    void nameChanged();
    void ipAddressChanged();
    void portChanged();
    void statusChanged();

public slots:
    //! \brief Установка статуса подключения сервера
    void onConnectionStatusChanged(bool status);

private:
    //! \brief Интервал попытоки подключения, после которого считать попытку неудачной
    int m_tryTimeout;

    //! \brief порт сервера
    int m_port;

    //! \brief Имя сервера
    QString m_name;

    //! \brief ip адрес сервера
    QString m_ipAddress;

    //! \brief Client Создает сокет и подключается к серверу
    Client *m_tcpClient;

    //! \brief Статус сервера
    //! Может уже готовые темы есть QTcpSocket например
    enum Status m_status;

    //! \brief Ошибка
    enum Error m_error;
};

#endif // SUBJECT_H
