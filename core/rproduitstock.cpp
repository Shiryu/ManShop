#include "rproduitstock.h"

namespace Core
{
    RProduitStock::RProduitStock( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "stock", new Stock( this ) );
        setForeignKey( "produit", new ProduitStock( this ) );
    }

    QString RProduitStock::getId() const
    {
        return m_id;
    }

    void RProduitStock::setId( QString id )
    {
        m_id = id;
    }

    Stock* RProduitStock::getStock() const
    {
        return qobject_cast< Stock* >( foreignKey("stock") );
    }

    ProduitStock* RProduitStock::getProduit() const
    {
        return qobject_cast< ProduitStock* >( foreignKey("produit") );
    }

    void RProduitStock::setStock( Stock* stock )
    {
        setForeignKey( "stock", stock );
    }

    void RProduitStock::setProduit( ProduitStock* produit )
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
