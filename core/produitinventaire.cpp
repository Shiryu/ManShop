#include "produitinventaire.h"

ProduitInventaire::ProduitInventaire( QObject *parent ) : Produit( parent )
{
}

int ProduitInventaire::getQuantite() const
{
    return m_quantite;
}

int ProduitInventaire::getEtat() const
{
    return m_etat;
}

void ProduitInventaire::setQuantite( int quantite )
{
    m_quantite = quantite;
}

void ProduitInventaire::setEtat( int etat )
{
    m_etat = etat;
}
