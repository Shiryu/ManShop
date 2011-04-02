#include "catalogue.h"
#include <QDebug>

Catalogue::Catalogue( QObject *parent ) : QDjangoModel( parent )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

Catalogue::Catalogue( QString code, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

Catalogue::Catalogue( QString code, QDate dateEnregistrement, QObject *parent ) :
        QDjangoModel( parent ),
        m_code( code ),
        m_dateEnregistrement( dateEnregistrement )
{
    setForeignKey( "fournisseur", new Fournisseur( this ) );
}

QString Catalogue::getCode() const
{
    return m_code;
}

QDate Catalogue::getDateEnregistrement() const
{
    return m_dateEnregistrement;
}

Fournisseur* Catalogue::getFournisseur() const
{
    return qobject_cast< Fournisseur* >( foreignKey( "fournisseur") );
}

void Catalogue::setCode( QString code )
{
    m_code = code;
}

void Catalogue::setDateEnregistrement( QDate dateEnregistrement )
{
    m_dateEnregistrement = dateEnregistrement;
}

void Catalogue::setFournisseur( Fournisseur* fournisseur )
{
    setForeignKey( "fournisseur", fournisseur );
}
