#include "magasin.h"

namespace Core
{
    Magasin* Magasin::instance = NULL;

    Magasin::Magasin()
    {
    }

    Magasin* Magasin::getInstance()
    {
        if( instance == NULL )
            instance = new Magasin();

        return instance;
    }

    QString Magasin::getCode() const
    {
        return m_code;
    }

    QString Magasin::getNom() const
    {
        return m_nom;
    }

    QString Magasin::getAdresse() const
    {
        return m_adresse;
    }

    void Magasin::setCode( QString code )
    {
        m_code = code;
    }

    void Magasin::setNom( QString nom )
    {
        m_nom = nom;
    }

    void Magasin::setAdresse( QString adresse )
    {
        m_adresse = adresse;
    }

    bool Magasin::save()
    {
        QSqlQuery requete;
        requete.prepare( "INSERT INTO magasin (code, nom, adresse)"
                         "VALUES (:code, :nom, :adresse) ");

        requete.bindValue( ":code", getCode() );
        requete.bindValue( ":nom", getNom() );
        requete.bindValue( ":adresse", getAdresse() );

        return requete.exec();
    }

    Magasin::~Magasin()
    {
        delete instance;
    }
}
