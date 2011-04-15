
#include "produitcommande.h"

namespace Core
{
    /*! \brief Crée un nouveau produit
      * \param parent L'objet parent
      */
    ProduitCommande::ProduitCommande( QObject *parent ) : ProduitFournisseur( parent )
    {
    }

    /*! \brief Renvoie la quantite commandée pour ce produit
      * \return quantite La quantite de produit commandée
      */
    int ProduitCommande::getQuantiteCommandee() const
    {
        return m_quantiteCommandee;
    }

    /*! \brief Modifie la quantité de produit commandée
      * \param quantite La quantité de produit à commander
      */
    void ProduitCommande::setQuantiteCommandee( int quantite )
    {
        m_quantiteCommandee = quantite;
    }
}
