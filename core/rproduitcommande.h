#ifndef RPRODUITCOMMANDE_H
#define RPRODUITCOMMANDE_H

#include "produit.h"
#include "commande.h"

namespace Core
{
    class RProduitCommande : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )

        Q_PROPERTY( Core::Commande* commande READ getCommande WRITE setCommande )
        Q_PROPERTY( Core::Produit* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "__meta__", "db_table=rproduitcommande" )
        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        int m_quantite;
        Commande *commande;
        Produit *produit;

        QString getId() const;
        void setId( QString id );

    public:
        RProduitCommande( QObject *parent = 0 );

        int getQuantite() const;
        Commande* getCommande() const;
        Produit* getProduit() const;

        void setQuantite( int quantite );
        void setCommande( Commande* commande );
        void setProduit( Produit* produit);

        bool save();
    };
};

#endif // RPRODUITCOMMANDE_H
