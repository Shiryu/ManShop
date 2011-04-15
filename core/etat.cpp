#include "etat.h"

namespace Core
{
    Etat::Etat( QObject *parent ) : QDjangoModel( parent )
    {

    }

    Etat::Etat( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {

    }

    QString Etat::getCode() const
    {
       return m_code;
    }

    QString Etat::getLibelle() const
    {
        return m_libelle;
    }

    void Etat::setCode( QString code )
    {
        m_code = code;
    }

    void Etat::setLibelle( QString libelle )
    {
        m_libelle = libelle;
    }
}
