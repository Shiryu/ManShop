#include "rproduitcommande.h"

namespace Core
{
    RProduitCommande::RProduitCommande( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "commande", new Commande( this ) );
        setForeignKey( "produit", new ProduitCommande( this ) );
    }

    QString RProduitCommande::getId() const
    {
        return m_id;
    }

    Commande* RProduitCommande::getCommande() const
    {
        return qobject_cast< Commande* >( ( foreignKey( "commande" ) ) );
    }

    ProduitCommande* RProduitCommande::getProduit() const
    {
        return qobject_cast< ProduitCommande* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitCommande::setId( QString id )
    {
        m_id = id;
    }

    void RProduitCommande::setCommande( Commande* commande )
    {
        setForeignKey( "commande", commande );
    }

    void RProduitCommande::setProduit( ProduitCommande* produit )
    {
        setForeignKey( "produit", produit );
    }

    bool RProduitCommande::save()
    {
        setId( getCommande()->getCode() + getProduit()->getCode() );
        return QDjangoModel::save();
    }
}
