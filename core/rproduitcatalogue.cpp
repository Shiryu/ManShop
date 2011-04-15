#include "rproduitcatalogue.h"

namespace Core
{
    RProduitCatalogue::RProduitCatalogue( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "catalogue", new Catalogue( this ) );
        setForeignKey( "produit", new Produit( this ) );
    }

    QString RProduitCatalogue::getId() const
    {
        return m_id;
    }

    QString RProduitCatalogue::getCodeFournisseur() const
    {
        return m_codeFournisseur;
    }

    double RProduitCatalogue::getPrixFournisseur() const
    {
        return m_prixFournisseur;
    }

    Catalogue* RProduitCatalogue::getCatalogue() const
    {
        return qobject_cast< Catalogue* >( ( foreignKey( "catalogue" ) ) );
    }

    Produit* RProduitCatalogue::getProduit() const
    {
        return qobject_cast< Produit* >( ( foreignKey( "produit" ) ) );
    }

    void RProduitCatalogue::setId( QString id )
    {
        m_id = id;
    }

    void RProduitCatalogue::setCodeFournisseur( QString codeFournisseur )
    {
        m_codeFournisseur = codeFournisseur;
    }

    void RProduitCatalogue::setPrixFournisseur( double prixFournisseur )
    {
        m_prixFournisseur = prixFournisseur;
    }

    void RProduitCatalogue::setCatalogue( Catalogue* catalogue )
    {
        setForeignKey( "catalogue", catalogue );
    }

    void RProduitCatalogue::setProduit( Produit* produit )
    {
        setForeignKey( "produit", produit );
    }

    QString RProduitCatalogue::creerId()
    {
        return getCatalogue()->getCode() + getProduit()->getCode();
    }

    bool RProduitCatalogue::save()
    {
        setId( creerId() );
        return QDjangoModel::save();
    }
}
