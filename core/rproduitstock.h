#ifndef RPRODUITSTOCK_H
#define RPRODUITSTOCK_H

#include "produitstock.h"
#include "stock.h"

namespace Core
{
    class RProduitStock : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )
        Q_PROPERTY( Stock* stock READ getStock WRITE setStock )
        Q_PROPERTY( ProduitStock* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        Stock *stock;
        ProduitStock *produit;

        QString creerId();
        QString getId() const;
        void setId( QString id );

    public:
        RProduitStock( QObject *parent = 0 );

        Stock* getStock() const;
        ProduitStock* getProduit() const;

        void setStock( Stock* stock );
        void setProduit( ProduitStock* produit );

        bool save();

    };
};

#endif // RPRODUITSTOCK_H
