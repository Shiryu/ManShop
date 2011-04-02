#include "produitcommande.h"

ProduitCommande::ProduitCommande( QObject *parent ) : ProduitFournisseur( parent )
{
}

int ProduitCommande::getQuantiteCommandee() const
{
    return m_quantiteCommandee;
}

void ProduitCommande::setQuantiteCommandee( int quantite )
{
    m_quantiteCommandee = quantite;
}
