#ifndef STOCK_H
#define STOCK_H

#include "objet.h"

namespace Core
{
    class Stock : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString nom READ getNom WRITE setNom )
        Q_PROPERTY( QDate dateCreation READ getDateCreation WRITE setDateCreation )

        Q_CLASSINFO( "__meta__", "db_table=stock" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_nom;
        QDate m_dateCreation;

    public:
        Stock( QObject *parent = 0 );
        Stock( QString code, QObject *parent = 0 );

        QString getCode() const;
        QString getNom() const;
        QDate getDateCreation() const;

        void setCode( QString code );
        void setNom( QString nom );
        void setDateCreation( QDate dateCreation );
    };
};

#endif // STOCK_H
