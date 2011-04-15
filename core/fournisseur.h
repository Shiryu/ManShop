#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include "objet.h"

namespace Core
{
    class Fournisseur : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString nom READ getNom WRITE setNom )
        Q_PROPERTY( QString adresse READ getAdresse WRITE setAdresse )

        Q_CLASSINFO( "__meta__", "db_table=fournisseur" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_nom;
        QString m_adresse;

    public:
        Fournisseur( QObject *parent = 0 );
        Fournisseur( QString code, QObject *parent = 0 );
        Fournisseur( QString code, QString nom, QString adresse, QObject *parent = 0 );

        QString getCode() const;
        QString getNom() const;
        QString getAdresse() const;

        void setCode( QString code );
        void setNom( QString nom );
        void setAdresse( QString adresse );
    };
};

#endif // FOURNISSEUR_H
