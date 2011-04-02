#ifndef MSRELATIONALTABLEMODEL_H
#define MSRELATIONALTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMetaProperty>
#include <qdjango/QDjangoQuerySet.h>
#include <QDebug>
#include "core/fournisseur.h"
#include "util/util.h"

template < typename S, typename T >
class MSRelationalTableModel : public QAbstractTableModel
{

private:
    QDjangoQuerySet< S > m_source;
    QDjangoQuerySet< T > m_cible;
    const char *m_liaison;

public:
    const static int NB_CHAMPS_PAR_DEFAUT = 2;

    MSRelationalTableModel( QObject *parent = 0 );
    MSRelationalTableModel( const QDjangoQuerySet< S > &source, const QDjangoQuerySet< T > &cible, QObject *parent = 0 );
    MSRelationalTableModel( const QDjangoQuerySet< S > &source, const QDjangoQuerySet< T > &cible, const char *liaison, QObject *parent = 0 );

    void setSrcQuerySet( QDjangoQuerySet< S > &source );
    void setDestQuerySet( QDjangoQuerySet< T > &cible );
    void setRelation( const char *liaison );

    int rowCount( const QModelIndex &parent = QModelIndex() ) const;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const;
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
};

template < typename S, typename T >
MSRelationalTableModel< S, T >::MSRelationalTableModel( QObject *parent ) : QAbstractTableModel( parent )
{

}

template < typename S, typename T >
MSRelationalTableModel< S, T >::MSRelationalTableModel( const QDjangoQuerySet<S> &source, const QDjangoQuerySet<T> &cible, QObject *parent ) :
        QAbstractTableModel( parent ),
        m_source( source ),
        m_cible( cible )
{

}

template < typename S, typename T >
MSRelationalTableModel< S, T >::MSRelationalTableModel( const QDjangoQuerySet<S> &source, const QDjangoQuerySet<T> &cible, const char *liaison, QObject *parent ) :
        QAbstractTableModel( parent ),
        m_source( source ),
        m_cible( cible ),
        m_liaison( liaison )
{

}

template < typename S, typename T >
void MSRelationalTableModel< S, T >::setSrcQuerySet( QDjangoQuerySet<S> &source )
{
    m_source = source;
}

template < typename S, typename T >
void MSRelationalTableModel< S, T >::setDestQuerySet( QDjangoQuerySet< T > &cible )
{
    m_cible = cible;
}

template < typename S, typename T >
void MSRelationalTableModel< S, T >::setRelation( const char *liaison )
{
    m_liaison = liaison;
}

template < typename S, typename T >
int MSRelationalTableModel< S, T >::rowCount( const QModelIndex &parent ) const
{
    return m_source.count();
}

template < typename S, typename T >
int MSRelationalTableModel< S, T >::columnCount( const QModelIndex &parent ) const
{
    S *objet = new S();

    const QMetaObject *metaobjet = objet->metaObject();
    int n = metaobjet->propertyCount();

    return n - NB_CHAMPS_PAR_DEFAUT;
}

template < typename S, typename T >
QVariant MSRelationalTableModel< S, T >::data( const QModelIndex &index, int role ) const
{
    if( !index.isValid() )
        return QVariant();

    if( index.row() < 0 || index.row() >= rowCount() || index.column() < 0 || index.column() >= columnCount () )
        return QVariant();

    if( role == Qt::DisplayRole )
    {
        QDjangoQuerySet< S > dataSource = m_source;

        S *objet = dataSource.at( index. row() );

        if( index.column() < columnCount() - 1)
        {
            const QMetaObject *metaobjet = objet->metaObject();
            QMetaProperty metaprop = metaobjet->property( index.column() + NB_CHAMPS_PAR_DEFAUT );

            return objet->property( metaprop.name() );
        }
        else
        {
            T *objetCible = objet->getRelation();

            return objetCible->property( m_liaison );
        }
    }

    return QVariant();
}

template < typename S, typename T >
QVariant MSRelationalTableModel< S, T >::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole )
        return QVariant();

    if( orientation == Qt::Vertical )
        return section + 1;

    if( orientation == Qt::Horizontal )
    {
        S *objet = new S();
        const QMetaObject *metaobjet = objet->metaObject();
        QMetaProperty metaprop = metaobjet->property( section + NB_CHAMPS_PAR_DEFAUT );

        return Util::formater( QString( metaprop.name() ) );
    }
}

#endif // MSRELATIONALTABLEMODEL_H
