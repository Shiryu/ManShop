#ifndef RPRODUITCOMMANDE_H
#define RPRODUITCOMMANDE_H

#include "produitcommande.h"
#include "commande.h"

class RProduitCommande : public QDjangoModel
{
    Q_OBJECT

    Q_PROPERTY( QString id READ getId WRITE setId )
    Q_PROPERTY( Commande* commande READ getCommande WRITE setCommande )
    Q_PROPERTY( ProduitCommande* produit READ getProduit WRITE setProduit )

    Q_CLASSINFO( "id", "primary_key=true" )

private:
    QString m_id;

    QString getId() const;
    void setId( QString id );

public:
    RProduitCommande( QObject *parent = 0 );

    Commande* getCommande() const;
    ProduitCommande* getProduit() const;

    void setCommande( Commande* commande );
    void setProduit( ProduitCommande* produit);

    bool save();
};

#endif // RPRODUITCOMMANDE_H
