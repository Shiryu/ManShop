#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "fournisseur.h"

namespace Core
{
    /*! \class Catalogue
      * \brief Classe représentant un catalogue
      */
    class Catalogue : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QDate dateEnregistrement READ getDateEnregistrement WRITE setDateEnregistrement )
        Q_PROPERTY( Core::Fournisseur* fournisseur READ getFournisseur WRITE setFournisseur )

        Q_CLASSINFO( "__meta__", "db_table=catalogue" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QDate m_dateEnregistrement;

        Fournisseur *fournisseur;

    public:
        Catalogue( QObject *parent = 0 );
        Catalogue( QString code, QObject *parent = 0 );
        Catalogue( QString code, QDate dateEnregistrement, QObject *parent = 0 );

        QString getCode() const;
        QDate getDateEnregistrement() const;
        Fournisseur* getFournisseur() const;

        void setCode( QString code );
        void setDateEnregistrement( QDate dateEnregistrement );
        void setFournisseur( Fournisseur* fournisseur );

        Fournisseur* getRelation() const { return getFournisseur(); }
    };
};

#endif // CATALOGUE_H
