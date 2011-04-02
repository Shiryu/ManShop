#include "livraison.h"

Livraison::Livraison( QObject *parent ) : QDjangoModel( parent )
{
    setForeignKey( "commande", new Commande( this ) );
}

Livraison::Livraison( QString code, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code )
{
    setForeignKey( "commande", new Commande( this ) );
}

Livraison::Livraison( QString code, QDate date, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code ),
        m_date( date)
{
    setForeignKey( "commande", new Commande( this ) );
}

QString Livraison::getCode() const
{
    return m_code;
}

QDate Livraison::getDate() const
{
    return m_date;
}

Commande* Livraison::getCommande() const
{
    return qobject_cast< Commande* >( ( foreignKey( "commande" ) ) );
}

void Livraison::setCode( QString code )
{
    m_code = code;
}

void Livraison::setDate( QDate date )
{
    m_date = date;
}

void Livraison::setCommande( Commande* commande )
{
    setForeignKey( "commande", commande);
}
