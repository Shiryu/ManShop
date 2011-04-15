#include "centraleachat.h"

namespace Core
{
    CentraleAchat* CentraleAchat::instance = NULL;

    CentraleAchat::CentraleAchat()
    {
    }

    CentraleAchat* CentraleAchat::getInstance()
    {
        if(instance == NULL)
            instance = new CentraleAchat();

        return instance;
    }

    QString CentraleAchat::getCode() const
    {
        return m_code;
    }

    QString CentraleAchat::getNom() const
    {
        return m_nom;
    }

    QString CentraleAchat::getAdresse() const
    {
        return m_adresse;
    }

    void CentraleAchat::setCode( QString code )
    {
        m_code = code;
    }

    void CentraleAchat::setNom( QString nom )
    {
        m_nom = nom;
    }

    void CentraleAchat::setAdresse( QString adresse )
    {
        m_adresse = adresse;
    }

    bool CentraleAchat::save()
    {
        QSqlQuery requete;

        requete.prepare( "INSERT INTO centraleachat (code, nom, adresse) "
                         "VALUES (:code, :nom, :adresse )" );

        requete.bindValue( ":code", getCode() );
        requete.bindValue( ":nom", getNom() );
        requete.bindValue( ":adresse", getAdresse() );

        return requete.exec();
    }
}
