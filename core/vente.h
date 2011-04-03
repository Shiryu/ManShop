#ifndef VENTE_H
#define VENTE_H

#include <QDate>
#include "objet.h"

namespace Core
{
    class Vente: public Objet
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( double montant READ getMontant WRITE setMontant )
        Q_PROPERTY( QDate date READ getDate WRITE setDate )

        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        double m_montant;
        QDate m_date;

    public:

        Vente();
        Vente( QString code );
        Vente( QString code, double montant, QDate date );

        QString getCode() const;
        double getMontant() const;
        QDate getDate() const;

        void setCode( QString code );
        void setMontant( double montant );
        void setDate( QDate date );
    };
};

#endif // VENTE_H
