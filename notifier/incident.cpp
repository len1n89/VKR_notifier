#include "incident.h"
#include "subject.h"

Incident::Incident(IncidentType type)
    : m_type(type)
    , m_confirmed(false)
{

}

Incident::~Incident()
{

}

int Incident::getId() const
{

}

bool Incident::confirmed() const
{
    return m_confirmed;
}

Incident::IncidentType Incident::type() const
{
    return m_type;
}

void Incident::setId(int id)
{

}

void Incident::confirm()
{
    m_confirmed = true;
    emit confirmedChanged();
}
