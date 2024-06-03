#ifndef INCIDENT_H
#define INCIDENT_H

#include<QObject>
#include<QTimer>

#include "message.h"
#include "watcher.h"

//! \class Incident
//! \brief Класс представляющий инцидент. Это экземпляр конкретной проблемы

class Incident : public QObject
{
    Q_OBJECT

public:
    enum IncidentType {
        ServerNotConnected       = 0,
        DBNotConnectedToServer   = 1,
    };
    Q_ENUM(IncidentType)


    Incident(IncidentType type);
    virtual ~Incident();

    //! Public functions
public:
    //! \brief Создать новое сообщение
    bool createMessage(const QString &name, const QString &ip);

    //! Getters
public:
    //! \brief Возвращает Идентификатор инцидента
    int getId() const;

    //! \brief Возвращает статус подтверждения
    bool confirmed() const;

    //! \brief Возвращает тип инцидента
    Incident::IncidentType type() const;

    //! Setters
public:
    //! \brief Установить Идентификатор инцидента
    void setId(int id);

    //! \brief Установить подтверждение инцидента
    void confirm();

    //! \brief Установить наблюдателей инцидента
    void setWatchers(const QList<Watcher*> list);

public slots:
    //! \brief Запускает таймер и вызывает отправку сообщений
    void onIncidentOpenned();

    //! \brief Таймер отправки сообщений
    void onSendTimer();

signals:
    void confirmedChanged();
    void incidentOpenned();

private:
    //! \brief Идентификатор инцидента
//    int m_id;

    //! \brief Инцидент подтвержден. Админ увидел и подтвердил
    bool m_confirmed;

    //! \brief Тип инцидента
    IncidentType m_type;

    //! \brief Сообщение для отправки
    Message m_message;

    //! \brief Наблюдатели инцидента
    //! При открытии инцидента отправлять сообшение всем наблюдателям
    //! пока инц не закрыт или не подтвержден
     QList<Watcher*> m_watchers;

     //! \brief Таймер отправки сообщений
     QTimer *m_sendTimer;
};
#endif // INCIDENT_H
