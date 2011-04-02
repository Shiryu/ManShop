/*
 * Produit
 */
#ifndef PRODUIT_H
#define PRODUIT_H

#include "objet.h"

class Produit : public QDjangoModel
{
    Q_OBJECT

    Q_PROPERTY( QString code READ getCode WRITE setCode )
    Q_PROPERTY( QString constructeur READ getConstructeur WRITE setConstructeur )
    Q_PROPERTY( QString nom READ getNom WRITE setNom )
    Q_PROPERTY( QString description READ getDescription WRITE setDescription )

    Q_CLASSINFO( "code", "primary_key=true" )

private:
    QString m_code;
    QString m_constructeur;
    QString m_nom;
    QString m_description;

public:
    Produit( QObject *parent = 0 );
    Produit( QString code, QObject *parent = 0 );
    Produit( QString code, QString constructeur, QString nom, QString description, QObject *parent = 0 );

    QString getCode() const;
    QString getConstructeur() const;
    QString getNom() const;
    QString getDescription() const;

    void setCode( QString code );
    void setConstructeur( QString constructeur );
    void setNom( QString nom );
    void setDescription( QString description );
};

#endif // PRODUIT_H
