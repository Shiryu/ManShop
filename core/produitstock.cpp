#include "produitstock.h"

namespace Core
{
    /*! \brief Crée un nouveau produit d'un stock
      * \param parent L'objet parent (optionnel)
      */
    ProduitStock::ProduitStock( QObject *parent ) : Produit( parent )
    {
    }

    /*! \brief Crée un nouveau produit d'un stock
      * \param code Le code du produit
      * \param objet L'objet parent (optionnel)
      */
    ProduitStock::ProduitStock( QString code, QObject *parent ) : Produit( parent )
    {
        setCode( code );
    }

    /*! \brief Renvoie la quantité du produit en stock
      * \return quantite La quantité du produit en stock
      */
    int ProduitStock::getQuantite() const
    {
        return m_quantite;
    }

    /*! \brief Renvoie le prix unitaire du produit
      * \return prixUnitaire Le prix unitaire du produit
      */
    double ProduitStock::getPrixUnitaire() const
    {
        return m_prixUnitaire;
    }

    /*! \brief Modifie la quantité du produit dans un stock
      * \param quantite La nouvelle quantité du produit dans le stock
      */
    void ProduitStock::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    /*! \brief Modifie le prix unitaire du produit
      * \param prixUnitaire Le nouveau prix unitaire du produit
      */
    void ProduitStock::setPrixUnitaire( double prixUnitaire )
    {
        m_prixUnitaire = prixUnitaire;
    }
}
