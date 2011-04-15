#include "produit.h"

namespace Core
{
    /*! \brief Crée un nouvel objet de type Produit
      * \param parent L'objet parent (optionnel)
      */
    Produit::Produit( QObject *parent ) : QDjangoModel( parent )
    {
        setForeignKey( "type", new TypeProduit( this ) );
    }

    /*! \brief Crée un nouvel objet de type Produit
      * \param code Le code du produit en cours de création
      * \param parent L'objet parent (optionnel)
      */
    Produit::Produit( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code )
    {
        setForeignKey( "type", new TypeProduit( this ) );
    }

    /*! \brief Crée un nouvel objet de type Produit
      * \param code Le code du produit
      * \param constructeur Le nom du constructeur ( la société qui fabrique ) du produit
      * \param description Une courte description du produit
      * \param parent L'objet parent (optionnel)
      */
    Produit::Produit( QString code, QString constructeur, QString nom, QString description, QObject *parent ) :
            QDjangoModel( parent ),
            m_code( code ),
            m_constructeur( constructeur ),
            m_nom( nom ),
            m_description( description )
    {
        setForeignKey( "type", new TypeProduit( this ) );
    }

    /*! \brief Renvoie le code du produit
      * \return code Le code du produit
      */
    QString Produit::getCode() const
    {
        return m_code;
    }

    /*! \brief Renvoie le constructeur du produit
      * \return constructeur Le constructeur du produit
      */
    QString Produit::getConstructeur() const
    {
        return m_constructeur;
    }

    /*! \brief Renvoie le nom du produit
      * \return nom Le nom du produit
      */
    QString Produit::getNom() const
    {
        return m_nom;
    }

    /*! \brief Renvoie la description du produit
      * \return description La description du produit
      */
    QString Produit::getDescription() const
    {
        return m_description;
    }

    /*! \brief Renvoie le type de produit associé �  ce produit
      * \return type Un pointeur TypeProduit représentant le type du produit
      */
    TypeProduit* Produit::getType() const
    {
        return qobject_cast< TypeProduit* >( foreignKey( "type" ) );
    }

    double Produit::getPrixUnitaire() const
    {
        return m_prixUnitaire;
    }

    /*! \brief Modifie le code du produit
      * \param code Le nouveau code du produit
      */
    void Produit::setCode( QString code )
    {
        m_code = code;
    }

    /*! \brief Modifie le constructeur du produit
      * \param constructeur Le nouveau constructeur du produit
      */
    void Produit::setConstructeur( QString constructeur )
    {
        m_constructeur = constructeur;
    }

    /*! \brief Modifie le nom du produit
      * \param nom Le nouveau nom du produit
      */
    void Produit::setNom( QString nom )
    {
        m_nom = nom;
    }

    /*! \brief Modifie la description du produit
      * \param description La description du produit
      */
    void Produit::setDescription( QString description )
    {
        m_description = description;
    }

    /*! \brief Modifie le type du produit
      * \param type Un pointeur TypeProduit représentant le type du produit
      */
    void Produit::setType( TypeProduit *type )
    {
        setForeignKey( "type", type );
    }

    void Produit::setPrixUnitaire( double prixUnitaire )
    {
        m_prixUnitaire = prixUnitaire;
    }
}
