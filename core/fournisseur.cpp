#include "fournisseur.h"

Fournisseur::Fournisseur( QObject *parent ) : QDjangoModel( parent )
{
}

Fournisseur::Fournisseur( QString code, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code )
{

}

Fournisseur::Fournisseur( QString code, QString nom, QString adresse, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code ),
        m_nom( nom ),
        m_adresse( adresse )
{

}

QString Fournisseur::getCode() const
{
    return m_code;
}

QString Fournisseur::getNom() const
{
    return m_nom;
}

QString Fournisseur::getAdresse() const
{
    return m_adresse;
}

void Fournisseur::setCode( QString code )
{
    m_code = code;
}

void Fournisseur::setNom( QString nom )
{
    m_nom = nom;
}

void Fournisseur::setAdresse( QString adresse )
{
    m_adresse = adresse;
}
