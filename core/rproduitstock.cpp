#include "rproduitstock.h"

namespace Core
{
    RProduitStock::RProduitStock( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "stock", new Stock( this ) );
        setForeignKey( "produit", new Produit( this ) );
    }

    QString RProduitStock::getId() const
    {
        return m_id;
    }

    void RProduitStock::setId( QString id )
    {
        m_id = id;
    }

    int RProduitStock::getQuantite() const
    {
        return m_quantite;
    }

    void RProduitStock::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    Stock* RProduitStock::getStock() const
    {
        return qobject_cast< Stock* >( foreignKey("stock") );
    }

    Produit* RProduitStock::getProduit() const
    {
        return qobject_cast< Produit* >( foreignKey("produit") );
    }

    void RProduitStock::setStock( Stock* stock )
    {
        setForeignKey( "stock", stock );
    }

    void RProduitStock::setProduit( Produit* produit )
    {
        setForeignKey( "produit", produit );
    }

    QString RProduitStock::creerId()
    {
        return getStock()->getCode() + getProduit()->getCode();
    }

    bool RProduitStock::save()
    {
        setId( creerId() );
        return QDjangoModel::save();
    }
}
