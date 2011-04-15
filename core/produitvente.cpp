#include "produitvente.h"

namespace Core
{
    ProduitVente::ProduitVente( QObject *parent ) : Produit( parent )
    {
    }

    ProduitVente::ProduitVente( QString code, QObject *parent ) : Produit( parent )
    {
        setCode( code );
    }

    double  ProduitVente::getPrixUnitaire() const
    {
        return m_prixUnitaire;
    }

    int ProduitVente::getQuantiteVendue() const
    {
        return m_quantiteVendue;
    }

    void ProduitVente::setPrixUnitaire( double prixUnitaire )
    {
        m_prixUnitaire = prixUnitaire;
    }


    void ProduitVente::setQuantiteVendue( int quantiteVendue )
    {
        m_quantiteVendue = quantiteVendue;
    }
}
