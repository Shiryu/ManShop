#ifndef TEMP_H
#define TEMP_H

#include "objet.h"
#include "typeproduit.h"

namespace Core
{
    class Temp : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString constructeur READ getConstructeur WRITE setConstructeur )
        Q_PROPERTY( QString nom READ getNom WRITE setNom )
        Q_PROPERTY( QString description READ getDescription WRITE setDescription )
        Q_PROPERTY( Core::TypeProduit* type READ getType WRITE setType )
        Q_PROPERTY( double prixUnitaire READ getPrixUnitaire WRITE setPrixUnitaire )

        Q_CLASSINFO( "__meta__", "db_table=temp" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_constructeur;
        QString m_nom;
        QString m_description;
        TypeProduit *type;
        double m_prixUnitaire;

    public:
        Temp( QObject *parent = 0 ) : QDjangoModel( parent )
        {
            setForeignKey( "type", new TypeProduit( this ) );
        }

        QString getCode() const { return m_code; }
        QString getConstructeur() const { return m_constructeur; }
        QString getNom() const { return m_nom; }
        QString getDescription() const { return m_description; }
        TypeProduit* getType() const { return qobject_cast< TypeProduit* >( foreignKey( "type" ) ); }
        double getPrixUnitaire() const { return m_prixUnitaire; }

        void setCode( QString code ) { m_code = code; }
        void setConstructeur( QString constructeur ) { m_constructeur = constructeur; }
        void setNom( QString nom ) { m_nom = nom; }
        void setDescription( QString description ) { m_description = description; }
        void setType( TypeProduit *type ) { setForeignKey( "type", type ); }
        void setPrixUnitaire( double prixUnitaire ) { m_prixUnitaire = prixUnitaire; }
    };
};

#endif // TEMP_H
