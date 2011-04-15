#include "produitfournisseur.h"

namespace Core
{
    /*! \brief Crée un nouveau produit
      * \param parent L'objet parent (optionnel)
      */
    ProduitFournisseur::ProduitFournisseur( QObject *parent ) : Produit( parent )
    {
    }

    /*! \brief Crée un nouveau produit
      * \param codeFournisseur Le code fournisseur du produit (différent du code donné dans le stock)
      * \param parent L'objet parent (optionnel)
      */
    ProduitFournisseur::ProduitFournisseur( QString codeFournisseur, QObject *parent ) :
            Produit( parent ),
            m_codeFournisseur( codeFournisseur )
    {

    }

    /*! \brief Renvoie le code fournisseur du produit
      * \return codeFournisseur Le code fournisseur du produit
      */
    QString ProduitFournisseur::getCodeFournisseur() const
    {
        return m_codeFournisseur;
    }

    /*! \brief Renvoie le prix fournisseur du produit
      * \return prix Le prix fournisseur du produit
      */
    double ProduitFournisseur::getPrixFournisseur() const
    {
        return m_prixFournisseur;
    }

    /*! \brief Modifie le code fournisseur du produit
      * \param codeFournisseur Le nouveau code fournisseur du produit
      */
    void ProduitFournisseur::setCodeFournisseur( QString codeFournisseur )
    {
        m_codeFournisseur = codeFournisseur;
    }

    /*! \brief Modifie le prix fournisseur du produit
      * \param prixFournisseur Le nouveau prix fournisseur du produit
      */
    void ProduitFournisseur::setPrixFournisseur( double prixFournisseur )
    {
        m_prixFournisseur = prixFournisseur;
    }
}
