#include "rproduitinventaire.h"

namespace Core
{
    RProduitInventaire::RProduitInventaire( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "inventaire", new Inventaire( this ) );
        setForeignKey( "produit", new ProduitInventaire( this ) );
    }

    QString RProduitInventaire::getId() const
    {
        return m_id;
    }

    Inventaire* RProduitInventaire::getInventaire() const
    {
        return qobject_cast< Inventaire* >( ( foreignKey( "inventaire" ) ) );
    }

    ProduitInventaire* RProduitInventaire::getProduit() const
    {
        return qobject_cast< ProduitInventaire* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitInventaire::setId( QString id )
    {
        m_id = id;
    }

    void RProduitInventaire::setInventaire( Inventaire* inventaire )
    {
        setForeignKey( "inventaire", inventaire );
    }

    void RProduitInventaire::setProduit( ProduitInventaire* produit )
    {
        setForeignKey( "produit", produit );
    }

    bool RProduitInventaire::save()
    {
        setId( getInventaire()->getCode() + getProduit()->getCode() );
        return QDjangoModel::save();
    }
}
