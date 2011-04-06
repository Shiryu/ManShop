#ifndef MSRELATIONALTABLEMODEL_H
#define MSRELATIONALTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMetaProperty>
#include <qdjango/QDjangoQuerySet.h>
#include <QDebug>

#include "util/util.h"

namespace Model
{
    template < typename S, typename T >
    class MSRelationalTableModel : public QAbstractTableModel
    {

    private:
        QDjangoQuerySet< S > m_source;
        QDjangoQuerySet< T > m_cible;
        const char *m_src;
        const char *m_dest;

    public:
        const static int NB_CHAMPS_PAR_DEFAUT = 2;

        MSRelationalTableModel( QObject *parent = 0 );
        MSRelationalTableModel( const QDjangoQuerySet< S > &source, const QDjangoQuerySet< T > &cible, QObject *parent = 0 );

        void setSrcQuerySet( QDjangoQuerySet< S > &source );
        void setDestQuerySet( QDjangoQuerySet< T > &cible );

        void setRelation( const char *src, const char *dest );

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
    void MSRelationalTableModel< S, T >::setRelation( const char *src, const char *dest )
    {
        m_src = src;
        m_dest = dest;
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
        int m = rowCount();
        int n = columnCount();

        if( !index.isValid() )
            return QVariant();

        if( index.row() < 0 || index.row() >= m || index.column() < 0 || index.column() >= n )
            return QVariant();

        if( role == Qt::DisplayRole )
        {
            QDjangoQuerySet< S > dataSource = m_source;

            S *objet = dataSource.at( index. row() );

            const QMetaObject *metaobjet = objet->metaObject();
            QMetaProperty metaprop = metaobjet->property( index.column() + NB_CHAMPS_PAR_DEFAUT );

            if( strcmp( metaprop.name(), m_src ) == 0 )
            {
                T *objetCible = objet->getRelation();
                return objetCible->property( m_dest );
            }

            return objet->property( metaprop.name() );
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

            return Util::Util::formater( QString( metaprop.name() ) );
        }
    }
};

#endif // MSRELATIONALTABLEMODEL_H
