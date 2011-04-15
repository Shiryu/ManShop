#ifndef RPRODUITCATALOGUE_H
#define RPRODUITCATALOGUE_H

#include "produit.h"
#include "catalogue.h"

namespace Core
{
    class RProduitCatalogue : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString id READ getId WRITE setId )

        Q_PROPERTY( QString codeFournisseur READ getCodeFournisseur WRITE setCodeFournisseur )
        Q_PROPERTY( double prixFournisseur READ getPrixFournisseur WRITE setPrixFournisseur )

        Q_PROPERTY( Core::Catalogue* catalogue READ getCatalogue WRITE setCatalogue )
        Q_PROPERTY( Core::Produit* produit READ getProduit WRITE setProduit )

        Q_CLASSINFO( "id", "primary_key=true" )
        Q_CLASSINFO( "__meta__", "db_table=rproduitcatalogue" )

    private:
        QString m_id;

        QString m_codeFournisseur;
        double m_prixFournisseur;
        Catalogue *catalogue;
        Produit *produit;

        QString creerId();
        QString getId() const;
        void setId( QString id );

    public:
        RProduitCatalogue( QObject *parent = 0 );

        QString getCodeFournisseur() const;
        double getPrixFournisseur() const;
        Catalogue* getCatalogue() const;
        Produit* getProduit() const;

        void setCodeFournisseur( QString codeFournisseur );
        void setPrixFournisseur( double prixFournisseur );
        void setCatalogue( Catalogue* catalogue );
        void setProduit( Produit* produit );

        bool save();
    };
};

#endif // RPRODUITCATALOGUE_H
