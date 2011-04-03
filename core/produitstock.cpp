#include "produitstock.h"

namespace Core
{
    ProduitStock::ProduitStock( QObject *parent ) : Produit( parent )
    {
    }

    ProduitStock::ProduitStock( QString code )
    {
        setCode( code );
    }

    int ProduitStock::getQuantite() const
    {
        return m_quantite;
    }

    double ProduitStock::getPrixUnitaire() const
    {
        return m_prixUnitaire;
    }

    void ProduitStock::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    void ProduitStock::setPrixUnitaire( double prixUnitaire )
    {
        m_prixUnitaire = prixUnitaire;
    }
}
