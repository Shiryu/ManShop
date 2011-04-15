#include "rproduitvente.h"

namespace Core
{
    RProduitVente::RProduitVente( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "vente", new Vente( this ) );
        setForeignKey( "produit", new Produit( this ) );
    }

    QString RProduitVente::getId() const
    {
        return m_id;
    }

    int RProduitVente::getQuantite() const
    {
        return m_quantite;
    }

    Vente* RProduitVente::getVente() const
    {
        return qobject_cast< Vente* >( ( foreignKey( "vente" ) ) );
    }

    Produit* RProduitVente::getProduit() const
    {
        return qobject_cast< Produit* >( ( foreignKey( "produit"  ) ) );
    }

    void RProduitVente::setId( QString id )
    {
        m_id = id;
    }

    void RProduitVente::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    void RProduitVente::setVente( Vente* vente )
    {
        setForeignKey( "vente", vente );
    }

    void RProduitVente::setProduit( Produit* produit )
    {
        setForeignKey( "produit", produit );
    }

    bool RProduitVente::save()
    {
        setId( getVente()->getCode() + getProduit()->getCode() );
        return QDjangoModel::save();
    }
}
