#ifndef VENTE_H
#define VENTE_H

#include <QDate>
#include "objet.h"

namespace Core
{
    class Vente: public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( double montant READ getMontant WRITE setMontant )
        Q_PROPERTY( QDate date READ getDate WRITE setDate )

        Q_CLASSINFO( "__meta__", "db_table=vente" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        double m_montant;
        QDate m_date;

    public:

        Vente( QObject *parent = 0 );
        Vente( QString code, QObject *parent = 0 );
        Vente( QString code, double montant, QDate date, QObject *parent = 0 );

        QString getCode() const;
        double getMontant() const;
        QDate getDate() const;

        void setCode( QString code );
        void setMontant( double montant );
        void setDate( QDate date );
    };
};

#endif // VENTE_H
