#ifndef PRODUITINVENTAIRE_H
#define PRODUITINVENTAIRE_H

#include "produit.h"

namespace Core
{
    /*! \class ProduitInventaire
      * \brief Représente un produit d'un inventaire
      */
    class ProduitInventaire : public Produit
    {
        Q_OBJECT

        Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )
        Q_PROPERTY( int etat READ getEtat WRITE setEtat )

        Q_CLASSINFO( "__meta__", "db_table=produitinventaire" )

    private:
        int m_quantite;
        int m_etat;

    public:
        /*! \enum Etat
          * \brief Représente l'état d'un produit dans un inventaire
          * \param BonEtat Le produit est en bon état
          * \param Deteriore Le produit est détérioré
          * \param Vole Le produit est volé
          */
        enum Etat
        {
            BonEtat,
            Deteriore,
            Vole
        };

        ProduitInventaire( QObject *parent = 0 );

        int getQuantite() const;
        int getEtat() const;

        void setQuantite( int quantite );
        void setEtat( int etat );
    };
};

#endif // PRODUITINVENTAIRE_H
