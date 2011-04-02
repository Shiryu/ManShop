#ifndef PRODUITVENTE_H
#define PRODUITVENTE_H

#include "produit.h"

class ProduitVente : public Produit
{
    Q_OBJECT

    Q_PROPERTY( int quantiteVendue READ getQuantiteVendue WRITE setQuantiteVendue );
    Q_PROPERTY( double prixUnitaire READ getPrixUnitaire WRITE setPrixUnitaire );

private:
    int m_quantiteVendue;
    double m_prixUnitaire;

public:
    ProduitVente( QObject *parent = 0 );
    ProduitVente( QString code, QObject *parent = 0 );

    double getPrixUnitaire() const;
    int getQuantiteVendue() const;

    void setPrixUnitaire( double prixUnitaire );
    void setQuantiteVendue( int quantiteVendue );

};

#endif // PRODUITVENTE_H
