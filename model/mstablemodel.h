#ifndef MSTABLEMODEL_H
#define MSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMetaProperty>
#include <qdjango/QDjangoQuerySet.h>
#include <QDebug>

#include "util/util.h"

/*! \namespace Model
  * \brief Regroupe un ensemble de modèles permettant d'utiliser les données de Core avec le framework Modèle/Vue de Qt
  */
namespace Model
{
    /*! \class MSTableModel
      * \brief Classe représentant un modèle dérivant de QAbstractTableModel
      */
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

    /*! \brief Crée un nouveau MSTableModel
      * \param parent L'objet parent
      */
    template < typename S >
    MSTableModel< S >::MSTableModel( QObject *parent ) : QAbstractTableModel( parent )
    {

    }

    /*! \brief Crée un nouveau MSTableModel
      * \param table Le QDjangoQuerySet représentant la structure sous-jacente du modèle
      * \param parent L'objet parent
      */
    template < typename S >
    MSTableModel< S >::MSTableModel( const QDjangoQuerySet< S > &table, QObject *parent ) :
            QAbstractTableModel( parent ),
            m_table( table )
    {

    }

    /*! \brief Modifie le QDjangoQuerySet associé au modèle
      * \param table Le QDjangoQuerySet qui sera associé au modèle
      */
    template < typename S >
    void MSTableModel< S >::setQuerySet( QDjangoQuerySet< S > &table)
    {
        m_table = table;
    }

    /*! \brief Méthode virtuelle de la classe QAbstractTableModel redéfinie ici pour donner le nombre de lignes
      *        du modèle
      * \param parent Le QModelIndex parent (dans ce cas, c'est un QModelIndex invalide)
      */
    template < typename S >
    int MSTableModel< S >::rowCount( const QModelIndex &parent ) const
    {
        return m_table.count();
    }

    /*! \brief Méthode virtuelle de la classe QAbstractTableModel redéfinie qui donne le nombre de colonnes du modèle
      * \param parent Le QModelIndex parent (un QModelIndex invalide)
      */
    template < typename S >
    int MSTableModel< S >::columnCount( const QModelIndex &parent ) const
    {
        S *objet = new S();

        const QMetaObject *metaobjet = objet->metaObject();
        int n = metaobjet->propertyCount();

        return n - NB_CHAMPS_PAR_DEFAUT;
    }

    /*! \brief Renvoie la donnée située à une ligne et une colonne précise du modèle. Le numero de ligne
      * est représenté par index.row() et le numero de colonne par index.column()
      * \param index Le QModelIndex permettant d'avoir accès aux numeros de ligne et colonne de la donnée à récupérer
      * \return QVariant La donnée située à l'index ou un QVariant invalide si la donnée ne peut être trouvée
      */
    template < typename S >
    QVariant MSTableModel< S >::data( const QModelIndex &index, int role ) const
    {
        int m = rowCount();
        int n = columnCount();

        if( !index.isValid() )
            return QVariant();

        if( index.row() < 0 || index.row() >= m || index.column() < 0 || index.column() >= n )
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

    /*! \brief Renvoie la chaîne de caractères qui sera affichée en entête de la table à une section donnée
      * \param section La section de la table dont on cherche l'entête
      * \param orientation L'orientation de la table (Qt::Vertical ou Qt::Horizontal)
      * \parm role Le rôle de la chaîne, sera-t-elle affichée en entête (Qt::DisplayRole) ou en tooltip (Qt::Tooltip), etc.
      */
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

            return Util::Util::formater( QString( metaprop.name() ) );
        }

        return QVariant();
    }
};

#endif // MSTABLEMODEL_H
