#ifndef MSTABLEMODEL_H
#define MSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMetaProperty>
#include <qdjango/QDjangoQuerySet.h>
#include <QDebug>

#include "util/util.h"

template < typename S >
class MSTableModel : public QAbstractTableModel
{

private:
    QDjangoQuerySet< S > m_table;

public:
    const static int NB_CHAMPS_PAR_DEFAUT = 2; // objectName et pk

    MSTableModel( QObject *parent = 0 );
    MSTableModel( const QDjangoQuerySet< S > &table, QObject *parent = 0 );

    void setQuerySet( QDjangoQuerySet< S > &table );

    int rowCount( const QModelIndex &parent = QModelIndex() ) const;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const;
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
};

template < typename S >
MSTableModel< S >::MSTableModel( QObject *parent ) : QAbstractTableModel( parent )
{

}

template < typename S >
MSTableModel< S >::MSTableModel( const QDjangoQuerySet< S > &table, QObject *parent ) :
        QAbstractTableModel( parent ),
        m_table( table )
{

}

template < typename S >
void MSTableModel< S >::setQuerySet( QDjangoQuerySet< S > &table)
{
    m_table = table;
}

template < typename S >
int MSTableModel< S >::rowCount( const QModelIndex &parent ) const
{
    return m_table.count();
}

template < typename S >
int MSTableModel< S >::columnCount( const QModelIndex &parent ) const
{
    S *objet = new S();

    const QMetaObject *metaobjet = objet->metaObject();
    int n = metaobjet->propertyCount();

    return n - NB_CHAMPS_PAR_DEFAUT;
}

template < typename S >
QVariant MSTableModel< S >::data( const QModelIndex &index, int role ) const
{
    if( !index.isValid() )
        return QVariant();

    if( index.row() < 0 || index.row() >= rowCount() || index.column() < 0 || index.column() >= columnCount() )
        return QVariant();

    if( role == Qt::DisplayRole )
    {
        QDjangoQuerySet< S > data = m_table; // !!! Important, il faut copier m_table dans un autre query_set pour que çà marche

        S *objet = data.at( index.row() );

        const QMetaObject *metaobjet = objet->metaObject();
        QMetaProperty metaprop = metaobjet->property( index.column() + NB_CHAMPS_PAR_DEFAUT );

        const char *nomColonne = metaprop.name();

        return objet->property( nomColonne );
    }

    return QVariant();
}

template < typename S >
QVariant MSTableModel< S >::headerData( int section, Qt::Orientation orientation, int role ) const
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

    return QVariant();
}

#endif // MSTABLEMODEL_H
