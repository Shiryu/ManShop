#include <QtGui>
#include <QDebug>

#include "core/connection.h"
#include "model/mstablemodel.h"
#include "model/msrelationaltablemodel.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    Connection::getInstance()->connecter();

    /*QDjangoQuerySet< ProduitStock > produits;

    MSTableModel< ProduitStock > *model = new MSTableModel< ProduitStock >();
    model->setQuerySet( produits );

    QTableView *view = new QTableView();
    view->setModel( model );
    view->show();*/

    QDjangoQuerySet< Catalogue > catalogues;
    QDjangoQuerySet< Fournisseur > fournisseurs;

    MSRelationalTableModel< Catalogue, Fournisseur > *model = new MSRelationalTableModel< Catalogue, Fournisseur >;
    model->setSrcQuerySet( catalogues );
    model->setDestQuerySet( fournisseurs );
    model->setRelation( "nom" );

    QTableView *view = new QTableView();
    view->setModel( model );
    view->show();


    return a.exec();
}
