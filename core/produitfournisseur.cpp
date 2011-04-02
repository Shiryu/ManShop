#include "produitfournisseur.h"

ProduitFournisseur::ProduitFournisseur( QObject *parent ) : Produit( parent )
{
}

ProduitFournisseur::ProduitFournisseur( QString codeFournisseur, QObject *parent ) :
        Produit( parent ),
        m_codeFournisseur( codeFournisseur )
{

}

QString ProduitFournisseur::getCodeFournisseur() const
{
    return m_codeFournisseur;
}

double ProduitFournisseur::getPrixFournisseur() const
{
    return m_prixFournisseur;
}

void ProduitFournisseur::setCodeFournisseur( QString codeFournisseur )
{
    m_codeFournisseur = codeFournisseur;
}

void ProduitFournisseur::setPrixFournisseur( double prixFournisseur )
{
    m_prixFournisseur = prixFournisseur;
}
