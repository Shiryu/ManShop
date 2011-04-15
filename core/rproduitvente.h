#ifndef RPRODUITVENTE_H
#define RPRODUITVENTE_H

#include "produit.h"
#include "vente.h"

namespace Core
{
    class RProduitVente : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )

        Q_PROPERTY( Core::Vente* vente READ getVente WRITE setVente )
        Q_PROPERTY( Core::Produit* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "__meta__", "db_table=rproduitvente" )
        Q_CLASSINFO( "id", "primary_key=true" )

    private:
        QString m_id;

        int m_quantite;
        Vente *vente;
        Produit *produit;

        QString getId() const;
        void setId( QString id );

    public:
        RProduitVente( QObject *parent = 0 );

        int getQuantite() const;
        Vente* getVente() const;
        Produit* getProduit() const;

        void setQuantite( int quantite );
        void setVente( Vente* vente );
        void setProduit( Produit* produit );

        bool save();
    };
};

#endif // RPRODUITVENTE_H
