#include "commande.h"

Commande::Commande( QObject *parent ) : QDjangoModel( parent )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

Commande::Commande( QString code, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

Commande::Commande( QString code, QDate date, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code ),
        m_date( date )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

QString Commande::getCode() const
{
    return m_code;
}

QDate Commande::getDate() const
{
    return m_date;
}

int Commande::getEtat() const
{
    return m_etat;
}

Fournisseur* Commande::getFournisseur() const
{
    return qobject_cast< Fournisseur* >((foreignKey("fournisseur")));
}

void Commande::setCode( QString code )
{
    m_code = code;
}

void Commande::setDate( QDate date )
{
    m_date = date;
}

void Commande::setEtat( int etat )
{
    m_etat = etat;
}

void Commande::setFournisseur( Fournisseur* fournisseur )
{
    setForeignKey("fournisseur", fournisseur);
}
