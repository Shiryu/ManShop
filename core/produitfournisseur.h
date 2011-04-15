#ifndef PRODUITFOURNISSEUR_H
#define PRODUITFOURNISSEUR_H

#include "produit.h"

namespace Core
{
    /*! \class ProduitFournisseur
      * \brief Représente un produit d'un catalogue d'un fournisseur
      */
    class ProduitFournisseur : public Produit
    {
        Q_OBJECT

        Q_PROPERTY( QString codeFournisseur READ getCodeFournisseur WRITE setCodeFournisseur )
        Q_PROPERTY( double prixFournisseur READ getPrixFournisseur WRITE setPrixFournisseur )

        Q_CLASSINFO( "__meta__", "db_table=produitfournisseur" )

    private:
        QString m_codeFournisseur;
        double m_prixFournisseur;

    public:
        ProduitFournisseur( QObject *parent = 0 );
        ProduitFournisseur( QString codeFournisseur, QObject *parent = 0 );

        QString getCodeFournisseur() const;
        double getPrixFournisseur() const;

        void setCodeFournisseur( QString codeFournisseur );
        void setPrixFournisseur( double prixFournisseur );
    };
};

#endif // PRODUITFOURNISSEUR_H
