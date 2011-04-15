#include "produitinventaire.h"

namespace Core
{
    /*! \brief Crée un nouveau produit d'un inventaire
      * \param parent  L'objet parent (optionnel)
      */
    ProduitInventaire::ProduitInventaire( QObject *parent ) : Produit( parent )
    {
    }

    /*! \brief Renvoie la quantité du produit dans l'inventaire
      * \return quantite La quantité du produit
      */
    int ProduitInventaire::getQuantite() const
    {
        return m_quantite;
    }

    /*! \brief Renvoie l'état du produit dans l'inventaire
      * \return etat L'état du produit (Doit être une des valeurs de l'enumération Etat)
      */
    int ProduitInventaire::getEtat() const
    {
        return m_etat;
    }

    /*! \brief Modifie la quantité du produit dans l'inventaire
      * \param quantite  La nouvelle quantité du produit
      */
    void ProduitInventaire::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    /*! \brief Modifie l'état du produit dans l'inventaire
      * \param etat Une des valeurs de l'enumération Etat
      */
    void ProduitInventaire::setEtat( int etat )
    {
        m_etat = etat;
    }
}
