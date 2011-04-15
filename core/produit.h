#ifndef PRODUIT_H
#define PRODUIT_H

#include "objet.h"
#include "typeproduit.h"

namespace Core
{
    /*! \class Produit
      * \brief Cette classe représente la classe de base pour tous les produits de l'application. Chaque autre
      *        type de produit hérite de cette classe
      */
    class Produit : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString constructeur READ getConstructeur WRITE setConstructeur )
        Q_PROPERTY( QString nom READ getNom WRITE setNom )
        Q_PROPERTY( QString description READ getDescription WRITE setDescription )
        Q_PROPERTY( Core::TypeProduit* type READ getType WRITE setType )
        Q_PROPERTY( double prixUnitaire READ getPrixUnitaire WRITE setPrixUnitaire )

        Q_CLASSINFO( "__meta__", "db_table=produit" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_constructeur;
        QString m_nom;
        QString m_description;
        TypeProduit *type;
        double m_prixUnitaire;

    public:
        Produit( QObject *parent = 0 );
        Produit( QString code, QObject *parent = 0 );
        Produit( QString code, QString constructeur, QString nom, QString description, QObject *parent = 0 );

        QString getCode() const;
        QString getConstructeur() const;
        QString getNom() const;
        QString getDescription() const;
        TypeProduit* getType() const;
        double getPrixUnitaire() const;

        void setCode( QString code );
        void setConstructeur( QString constructeur );
        void setNom( QString nom );
        void setDescription( QString description );
        void setType( TypeProduit *type );
        void setPrixUnitaire( double prixUnitaire );
    };
};

#endif // PRODUIT_H
