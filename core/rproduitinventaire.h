#ifndef RPRODUITINVENTAIRE_H
#define RPRODUITINVENTAIRE_H

#include "produitinventaire.h"
#include "inventaire.h"

namespace Core
{
    class RProduitInventaire : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )
        Q_PROPERTY( Core::Inventaire* inventaire READ getInventaire WRITE setInventaire )
        Q_PROPERTY( Core::ProduitInventaire* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        Inventaire *inventaire;
        ProduitInventaire *produit;

        QString getId() const;
        void setId( QString id );

    public:
        RProduitInventaire( QObject *parent = 0 );

        Inventaire* getInventaire() const;
        ProduitInventaire* getProduit() const;

        void setInventaire( Inventaire* inventaire );
        void setProduit( ProduitInventaire* produit );

        bool save();
    };
};

#endif // RPRODUITINVENTAIRE_H
