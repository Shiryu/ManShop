#include "catalogue.h"
#include <QDebug>

/*! \namespace Core
  * \brief Regroupe un ensemble de classes de base représentant les données manipulées par le programe
  */

namespace Core
{
    /*! \brief Crée un nouveau Catalogue
      * \param parent Un pointeur vers l'objet parent du Catalogue
      */
    Catalogue::Catalogue( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "fournisseur", new Fournisseur( this ) );
    }

    /*! \brief Crée un nouveau Catalogue
      * \param code Le code du Catalogue
      * \param parent Un pointeur vers l'objet parent du Catalogue
      */
    Catalogue::Catalogue( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {
        setForeignKey( "fournisseur", new Fournisseur( this ) );
    }

    /*! \brief Crée un nouveau Catalogue
      * \param code Le code du Catalogue
      * \param dateEnregistrement La date à laquelle le catalogue a été reçu
      */
    Catalogue::Catalogue( QString code, QDate dateEnregistrement, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code ),
            m_dateEnregistrement( dateEnregistrement )
    {
        setForeignKey( "fournisseur", new Fournisseur( this ) );
    }

    /*! \brief Renvoie le code du catalogue
      * \return code Le code du catalogue
      */
    QString Catalogue::getCode() const
    {
        return m_code;
    }

    /*! \brief Renvoie la date à laquelle le catalogue a été enregistré
      * \return dateEnregistrement La date d'enregistrement du catalogue
      */
    QDate Catalogue::getDateEnregistrement() const
    {
        return m_dateEnregistrement;
    }

    /*! \brief Renvoie l'objet Fournisseur correspondant au fournisseur dont émane le catalogue
      * \return fournisseur Le fournisseur associé au catalogue
      */
    Fournisseur* Catalogue::getFournisseur() const
    {
        return qobject_cast< Fournisseur* >( foreignKey( "fournisseur") );
    }

    /*! \brief Modifie le code du catalogue
      * \param code Le nouveau code du catalogue
      */
    void Catalogue::setCode( QString code )
    {
        m_code = code;
    }

    /*! \brief Modifie la date d'enregistrement du catalogue
      * \param dateEnregistrement La nouvelle date d'enregistrement
      */
    void Catalogue::setDateEnregistrement( QDate dateEnregistrement )
    {
        m_dateEnregistrement = dateEnregistrement;
    }

    /*! \brief Modifie le fournisseur associé au catalogue
      * \param fournisseur Le fournisseur qui sera associé au catalogue
      */
    void Catalogue::setFournisseur( Fournisseur* fournisseur )
    {
        setForeignKey( "fournisseur", fournisseur );
    }
}
