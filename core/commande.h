#ifndef COMMANDE_H
#define COMMANDE_H

#include "objet.h"
#include "fournisseur.h"

namespace Core
{
    class Commande : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QDate date READ getDate WRITE setDate )
        Q_PROPERTY( int etat READ getEtat WRITE setEtat )
        Q_PROPERTY( Fournisseur* fournisseur READ getFournisseur WRITE setFournisseur )

        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QDate m_date;
        int m_etat;

        Fournisseur *fournisseur;

    public:
        enum Etat
        {
            EnAttente,
            EnAttenteLivraison,
            LivraisonPartielle,
            LivraisonTotale
        };

        Commande( QObject *parent = 0 );
        Commande( QString code, QObject *parent = 0 );
        Commande( QString code, QDate date, QObject *parent = 0 );

        QString getCode() const;
        QDate getDate() const;
        int getEtat() const;
        Fournisseur* getFournisseur() const;

        void setCode( QString code );
        void setDate( QDate date );
        void setEtat( int etat );
        void setFournisseur( Fournisseur* fournisseur );

        Fournisseur* getRelation() const { return getFournisseur(); }
    };
};

#endif // COMMANDE_H
