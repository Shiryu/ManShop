#include "rproduitcatalogue.h"

namespace Core
{
    RProduitCatalogue::RProduitCatalogue( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "catalogue", new Catalogue( this ) );
        setForeignKey( "produit", new ProduitFournisseur( this ) );
    }

    QString RProduitCatalogue::getId() const
    {
        return m_id;
    }

    Catalogue* RProduitCatalogue::getCatalogue() const
    {
        return qobject_cast< Catalogue* >( ( foreignKey( "catalogue" ) ) );
    }

    ProduitFournisseur* RProduitCatalogue::getProduit() const
    {
        return qobject_cast< ProduitFournisseur* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitCatalogue::setId( QString id )
    {
        m_id = id;
    }

    void RProduitCatalogue::setCatalogue( Catalogue* catalogue )
    {
        setForeignKey( "catalogue", catalogue );
    }

    void RProduitCatalogue::setProduit( ProduitFournisseur* produit )
    {
        setForeignKey( "produit", produit );
    }

    QString RProduitCatalogue::creerId()
    {
        return getCatalogue()->getCode() + getProduit()->getCode();
    }

    bool RProduitCatalogue::save()
    {
        setId( creerId() );
        return QDjangoModel::save();
    }
}
