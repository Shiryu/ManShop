#include "rproduitcommande.h"

namespace Core
{
    RProduitCommande::RProduitCommande( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "commande", new Commande( this ) );
        setForeignKey( "produit", new Produit( this ) );
    }

    QString RProduitCommande::getId() const
    {
        return m_id;
    }

    int RProduitCommande::getQuantite() const
    {
        return m_quantite;
    }

    Commande* RProduitCommande::getCommande() const
    {
        return qobject_cast< Commande* >( ( foreignKey( "commande" ) ) );
    }

    Produit* RProduitCommande::getProduit() const
    {
        return qobject_cast< Produit* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitCommande::setId( QString id )
    {
        m_id = id;
    }

    void RProduitCommande::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    void RProduitCommande::setCommande( Commande* commande )
    {
        setForeignKey( "commande", commande );
    }

    void RProduitCommande::setProduit( Produit* produit )
    {
        setForeignKey( "produit", produit );
    }

    bool RProduitCommande::save()
    {
        setId( getCommande()->getCode() + getProduit()->getCode() );
        return QDjangoModel::save();
    }
}
