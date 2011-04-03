#include <QtGui>
#include <QDebug>

#include "core/connection.h"
#include "model/mstablemodel.h"
#include "model/msrelationaltablemodel.h"

using namespace Core;
using namespace Model;

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    Connection::getInstance()->connecter();

    ProduitStock *p = new ProduitStock();
    p->setCode( "hp1" );
    p->setConstructeur( "hp" );
    p->setNom( "laptop 6510b" );
    p->setDescription( "ordinateur portable hp" );
    p->setPrixUnitaire( 2650.25 );
    p->setQuantite( 6 );
    p->save();

    QDjangoQuerySet< ProduitStock > produits;

    MSTableModel< ProduitStock > *model = new MSTableModel< ProduitStock >();
    model->setQuerySet( produits );

    QTableView *view = new QTableView();
    view->setModel( model );
    view->show();

    /*QDjangoQuerySet< Catalogue > catalogues;
    QDjangoQuerySet< Fournisseur > fournisseurs;

    MSRelationalTableModel< Catalogue, Fournisseur > *model = new MSRelationalTableModel< Catalogue, Fournisseur >;
    model->setSrcQuerySet( catalogues );
    model->setDestQuerySet( fournisseurs );
    model->setRelation( "nom" );

    QTableView *view = new QTableView();
    view->setModel( model );
    view->show();*/


    return a.exec();
}
