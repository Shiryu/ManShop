#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "objet.h"

namespace Core
{
    class Inventaire : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString nom READ getNom WRITE setNom )
        Q_PROPERTY( QDate date READ getDate WRITE setDate )

        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_nom;
        QDate m_date;

    public:
        Inventaire( QObject *parent = 0 );
        Inventaire( QString code, QObject *parent = 0 );
        Inventaire( QString code, QString nom, QDate date, QObject *parent = 0 );

        QString getCode() const;
        QString getNom() const;
        QDate getDate() const;

        void setCode( QString code );
        void setNom( QString nom );
        void setDate( QDate date );
    };
};

#endif // INVENTAIRE_H
