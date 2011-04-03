#ifndef LIVRAISON_H
#define LIVRAISON_H

#include "commande.h"

namespace Core
{
    class Livraison : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
                Q_PROPERTY( QDate date READ getDate WRITE setDate )
                Q_PROPERTY( Commande* commande READ getCommande WRITE setCommande )

                Q_CLASSINFO( "code", "primary_key=true" )

    private:
                QString m_code;
        QDate m_date;

        Commande *commande;

    public:
        Livraison( QObject *parent = 0 );
        Livraison( QString code, QObject *parent = 0 );
        Livraison( QString code, QDate date, QObject *parent = 0 );

        QString getCode() const;
        QDate getDate() const;
        Commande* getCommande() const;

        void setCode( QString code );
        void setDate( QDate date );
        void setCommande( Commande *commande );

        Commande* getRelation() const { return getCommande(); }
    };
};

#endif // LIVRAISON_H
