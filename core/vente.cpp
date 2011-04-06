#include "vente.h"

namespace Core
{
    Vente::Vente( QObject *parent ) : QDjangoModel( parent )
    {
    }

    Vente::Vente( QString code, QObject *parent ) :
            QDjangoModel( parent ),
            m_code(code)
    {

    }

    Vente::Vente( QString code, double montant, QDate date, QObject *parent ):
            QDjangoModel( parent ),
            m_code(code),
            m_montant(montant),
            m_date(date)
    {

    }

    QString Vente::getCode() const
    {
        return m_code;
    }

    double Vente::getMontant() const
    {
        return m_montant;
    }

    QDate Vente::getDate() const
    {
        return m_date;
    }

    void Vente::setCode( QString code )
    {
        m_code=code;
    }

    void Vente::setMontant( double montant )
    {
        m_montant=montant;
    }

    void Vente::setDate( QDate date )
    {
        m_date=date;
    }
}
