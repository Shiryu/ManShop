#ifndef RPRODUITCATALOGUE_H
#define RPRODUITCATALOGUE_H

#include "produitcommande.h"
#include "catalogue.h"

class RProduitCatalogue : public QDjangoModel
{
    Q_OBJECT

    Q_PROPERTY( QString id READ getId WRITE setId )
    Q_PROPERTY( Catalogue* catalogue READ getCatalogue WRITE setCatalogue )
    Q_PROPERTY( ProduitFournisseur* produit READ getProduit WRITE setProduit )

    Q_CLASSINFO( "id", "primary_key=true" )

private:
    QString m_id;

    QString creerId();
    QString getId() const;
    void setId( QString id );

public:
    RProduitCatalogue( QObject *parent = 0 );

    Catalogue* getCatalogue() const;
    ProduitFournisseur* getProduit() const;

    void setCatalogue( Catalogue* catalogue );
    void setProduit( ProduitFournisseur* produit );

    bool save();
};

#endif // RPRODUITCATALOGUE_H