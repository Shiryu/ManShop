#include "stock.h"

namespace Core
{
    Stock::Stock( QObject *parent ) : QDjangoModel( parent )
    {
    }

    Stock::Stock( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code(code)
    {

    }

    QString Stock::getCode() const
    {
        return m_code;
    }

    QString Stock::getNom() const
    {
        return m_nom;
    }

    QDate Stock::getDateCreation() const
    {
        return m_dateCreation;
    }

    void Stock::setCode( QString code )
    {
        m_code = code;
    }

    void Stock::setNom( QString nom )
    {
        m_nom = nom;
    }

    void Stock::setDateCreation( QDate dateCreation )
    {
        m_dateCreation = dateCreation;
    }
}
