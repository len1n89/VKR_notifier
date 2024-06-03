#ifndef USER_H
#define USER_H

#include<QObject>

//! \class Subject
//! \brief Класс представляет пользователя

class User : public QObject
{
    Q_OBJECT

public:
    User();
    virtual ~User();

private:
    //! \brief
    QString m_name;

    //! \brief
    QString m_mailAddress;

    //! \brief
    QString m_telegramAddress;

    //! \brief
    QString m_phoneAddress;

};
#endif // USER_H
