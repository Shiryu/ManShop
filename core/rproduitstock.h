#ifndef RPRODUITSTOCK_H
#define RPRODUITSTOCK_H

#include <qdjango/QDjangoQuerySet.h>

#include "produit.h"
#include "stock.h"

namespace Core
{
    class RProduitStock : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )

        Q_PROPERTY( Core::Stock* stock READ getStock WRITE setStock )
        Q_PROPERTY( Core::Produit* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "__meta__", "db_table=rproduitstock" )
        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        int m_quantite;
        Stock *stock;
        Produit *produit;

        QString creerId();
        QString getId() const;
        void setId( QString id );

    public:
        RProduitStock( QObject *parent = 0 );

        int getQuantite() const;
        Stock* getStock() const;
        Produit* getProduit() const;

        void setQuantite( int quantite );
        void setStock( Stock* stock );
        void setProduit( Produit* produit );

        bool save();

    };
};

#endif // RPRODUITSTOCK_H
