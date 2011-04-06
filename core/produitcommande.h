#ifndef PRODUITCOMMANDE_H
#define PRODUITCOMMANDE_H

#include "produitfournisseur.h"

namespace Core
{
    /*! \class ProduitCommande
      * \brief Représente un produit d'une commande
      */
    class ProduitCommande : public ProduitFournisseur
    {
        Q_OBJECT

        Q_PROPERTY( int quantiteCommandee READ getQuantiteCommandee WRITE setQuantiteCommandee )

    private:
        int m_quantiteCommandee;

    public:
        ProduitCommande( QObject *parent = 0 );

        int getQuantiteCommandee() const;

        void setQuantiteCommandee( int quantite );
    };
};

#endif // PRODUITCOMMANDE_H
