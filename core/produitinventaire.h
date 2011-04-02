#ifndef PRODUITINVENTAIRE_H
#define PRODUITINVENTAIRE_H

#include "produit.h"

class ProduitInventaire : public Produit
{
    Q_OBJECT

    Q_PROPERTY( int quantite READ getQuantite WRITE setQuantite )
    Q_PROPERTY( int etat READ getEtat WRITE setEtat )

private:
    int m_quantite;
    int m_etat;

public:
    enum Etat
    {
        BonEtat,
        Deteriore,
        Vole
    };

    ProduitInventaire( QObject *parent = 0 );

    int getQuantite() const;
    int getEtat() const;

    void setQuantite( int quantite );
    void setEtat( int etat );
};

#endif // PRODUITINVENTAIRE_H
