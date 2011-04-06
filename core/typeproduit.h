#ifndef TYPEPRODUIT_H
#define TYPEPRODUIT_H

#include "objet.h"

namespace Core
{
    class TypeProduit : public QDjangoModel
    {
        Q_OBJECT

        Q_PROPERTY( QString code READ getCode WRITE setCode )
                Q_PROPERTY( QString libelle READ getLibelle WRITE setLibelle )

                Q_CLASSINFO( "code", "primary_key=true" )

    private:
                QString m_code;
        QString m_libelle;

    public:
        TypeProduit( QObject *parent = 0 );
        TypeProduit( QString code, QObject *parent = 0 );
        TypeProduit( QString code, QString libelle, QObject *parent = 0 );

        QString getCode() const;
        QString getLibelle() const;

        void setCode( QString code );
        void setLibelle( QString libelle );
    };
};

#endif // TYPEPRODUIT_H
