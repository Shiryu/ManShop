#include "typeproduit.h"

namespace Core
{
    TypeProduit::TypeProduit( QObject *parent ) : QDjangoModel( parent )
    {

    }

    TypeProduit::TypeProduit( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {

    }

    TypeProduit::TypeProduit( QString code, QString libelle, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code ),
            m_libelle( libelle )
    {

    }

    QString TypeProduit::getCode() const
    {
        return m_code;
    }

    QString TypeProduit::getLibelle() const
    {
        return m_libelle;
    }

    void TypeProduit::setCode( QString code )
    {
        m_code = code;
    }

    void TypeProduit::setLibelle( QString libelle )
    {
        m_libelle = libelle;
    }
}
