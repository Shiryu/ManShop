#ifndef RPRODUITINVENTAIRE_H
#define RPRODUITINVENTAIRE_H

#include "produit.h"
#include "inventaire.h"
#include "etat.h"

namespace Core
{
    class RProduitInventaire : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )
        Q_PROPERTY( Core::Etat* etat READ getEtat WRITE setEtat )
        Q_PROPERTY( Core::Inventaire* inventaire READ getInventaire WRITE setInventaire )
        Q_PROPERTY( Core::Produit* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "__meta__", "db_table=rproduitinventaire" )
        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        int m_quantite;

        Inventaire *inventaire;
        Produit *produit;

        QString getId() const;
        void setId( QString id );

    public:
        RProduitInventaire( QObject *parent = 0 );

        int getQuantite() const;
        Etat* getEtat() const;
        Inventaire* getInventaire() const;
        Produit* getProduit() const;

        void setQuantite( int quantite );
        void setEtat( Etat* etat );
        void setInventaire( Inventaire* inventaire );
        void setProduit( Produit* produit );

        bool save();
    };
};

#endif // RPRODUITINVENTAIRE_H
