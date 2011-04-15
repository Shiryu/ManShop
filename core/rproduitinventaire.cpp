#include "rproduitinventaire.h"

namespace Core
{
    RProduitInventaire::RProduitInventaire( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "etat", new Etat( this ) );
        setForeignKey( "inventaire", new Inventaire( this ) );
        setForeignKey( "produit", new Produit( this ) );
    }

    QString RProduitInventaire::getId() const
    {
        return m_id;
    }

    int RProduitInventaire::getQuantite() const
    {
        return m_quantite;

    }

    Etat* RProduitInventaire::getEtat() const
    {
        return qobject_cast< Etat* >( ( foreignKey( "etat" ) ) );
    }

    Inventaire* RProduitInventaire::getInventaire() const
    {
        return qobject_cast< Inventaire* >( ( foreignKey( "inventaire" ) ) );
    }

    Produit* RProduitInventaire::getProduit() const
    {
        return qobject_cast< Produit* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitInventaire::setId( QString id )
    {
        m_id = id;
    }

    void RProduitInventaire::setQuantite( int quantite )
    {
        m_quantite = quantite;
    }

    void RProduitInventaire::setEtat( Etat* etat )
    {
        setForeignKey( "etat", etat );
    }

    void RProduitInventaire::setInventaire( Inventaire* inventaire )
    {
        setForeignKey( "inventaire", inventaire );
    }

    void RProduitInventaire::setProduit( Produit* produit )
    {
        setForeignKey( "produit", produit );
    }

    bool RProduitInventaire::save()
    {
        setId( getInventaire()->getCode() + getProduit()->getCode() );
        return QDjangoModel::save();
    }
}
