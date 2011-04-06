#ifndef PRODUITSTOCK_H
#define PRODUITSTOCK_H

#include "produit.h"

namespace Core
{
    /*! \class ProduitStock
      * \brief Représente un produit d'un stock du magasin
      */
    class ProduitStock : public Produit
    {
        Q_OBJECT

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )
        Q_PROPERTY( double prixUnitaire READ getPrixUnitaire WRITE setPrixUnitaire )

    private:
        int m_quantite;
        double m_prixUnitaire;

    public:
        ProduitStock( QObject *parent = 0 );
        ProduitStock( QString code, QObject *parent = 0 );

        int getQuantite() const;
        double getPrixUnitaire() const;

        void setQuantite( int quantite );
        void setPrixUnitaire( double prixUnitaire );
    };
};

#endif // PRODUITSTOCK_H
