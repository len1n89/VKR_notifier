#ifndef INCIDENT_H
#define INCIDENT_H

#include<QObject>

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

signals:
    void confirmedChanged();

private:
    //! \brief Идентификатор инцидента
    int m_id;

    //! \brief Инцидент подтвержден. Админ увидел и подтвердил
    bool m_confirmed;

    //! \brief Тип инцидента
    IncidentType m_type;

    //! \brief Описание
    QString m_discription;
};
#endif // INCIDENT_H
