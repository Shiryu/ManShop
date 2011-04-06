#ifndef MSETABLEMODEL_H
#define MSETABLEMODEL_H

#include <QMetaProperty>
#include <qdjango/QDjangoQuerySet.h>

#include "model/mstablemodel.h"
#include "util/util.h"

namespace Model
{
    template < typename S >
    class MSETableModel : public MSTableModel
    {

    public:
        MSETableModel( QObject *parent = 0 );

        Qt::ItemFlags flags( const QModelIndex &index ) const;
        bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole ) const;

    };

    template < typename S >
    MSETableModel< S >::MSETableModel( QObject *parent ) : MSTableModel( parent )
    {

    }

    template < typename S >
    Qt::ItemFlags MSETableModel< S >::flags( const QModelIndex &index ) const
    {
        if( !index.isValid() )
            return Qt::ItemIsEnabled;

        return QAbstractTableModel::flags( index ) | Qt::ItemIsEditable;
    }

    template < typename S >
    bool MSETableModel< S >::setData( const QModelIndex &index, const QVariant &value, int role ) const
    {
        if( index.isValid() && role == Qt::EditRole )
        {

        }
    }
};


#endif // MSETABLEMODEL_H
