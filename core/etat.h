#ifndef ETAT_H
#define ETAT_H

#include <qdjango/QDjangoModel.h>

namespace Core
{
    class Etat : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
        Q_PROPERTY( QString libelle READ getLibelle WRITE setLibelle )

        Q_CLASSINFO( "__meta__", "db_table=etat" )
        Q_CLASSINFO( "code", "primary_key=true" )

    private:
        QString m_code;
        QString m_libelle;

    public:
        Etat( QObject *parent = 0 );
        Etat( QString code, QObject *parent = 0 );

        QString getCode() const;
        QString getLibelle() const;

        void setCode( QString code );
        void setLibelle( QString libelle );
    };
};

#endif // ETAT_H
