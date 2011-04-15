#include "inventaire.h"

namespace Core
{
    Inventaire::Inventaire( QObject *parent ) : QDjangoModel( parent )
    {

    }

    Inventaire::Inventaire( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {

    }

    Inventaire::Inventaire( QString code, QString nom, QDate date, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code ),
            m_nom( nom ),
            m_date( date )
    {

    }


    QString Inventaire::getCode() const
    {
        return m_code;
    }

    QString Inventaire::getNom() const
    {
        return m_nom;
    }

    QDate Inventaire::getDate() const
    {
        return m_date;
    }

    void Inventaire::setCode( QString code )
    {
        m_code = code;
    }

    void Inventaire::setNom( QString nom )
    {
        m_nom = nom;
    }

    void Inventaire::setDate( QDate date )
    {
        m_date = date;
    }
}
