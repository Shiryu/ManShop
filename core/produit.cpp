#include "produit.h"

namespace Core
{
    Produit::Produit( QObject *parent ) : QDjangoModel( parent )
    {

    }

    Produit::Produit( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {

    }

    Produit::Produit( QString code, QString constructeur, QString nom, QString description, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code ),
            m_constructeur( constructeur ),
            m_nom( nom ),
            m_description( description )
    {

    }

    QString Produit::getCode() const
    {
        return m_code;
    }

    QString Produit::getConstructeur() const
    {
        return m_constructeur;
    }

    QString Produit::getNom() const
    {
        return m_nom;
    }

    QString Produit::getDescription() const
    {
        return m_description;
    }

    void Produit::setCode( QString code )
    {
        m_code = code;
    }

    void Produit::setConstructeur( QString constructeur )
    {
        m_constructeur = constructeur;
    }

    void Produit::setNom( QString nom )
    {
        m_nom = nom;
    }

    void Produit::setDescription( QString description )
    {
        m_description = description;
    }
}
