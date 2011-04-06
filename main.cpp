#include <QtGui>
#include <QDebug>

#include "core/connection.h"
#include "model/mstablemodel.h"
#include "model/msrelationaltablemodel.h"
#include "util/util.h"


using namespace Core;
using namespace Model;

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    Connection::getInstance()->connecter();


    QDjangoQuerySet< Stock > stocks;
    Stock *s = stocks.get( QDjangoWhere( "code", QDjangoWhere::Equals, "S1" ) );

    QDjangoQuerySet< ProduitStock > produits = Util::Util::listeProduits< ProduitStock, RProduitStock, Stock >( s );
    QDjangoQuerySet< TypeProduit > types;

    MSRelationalTableModel< ProduitStock, TypeProduit > *model = new MSRelationalTableModel< ProduitStock, TypeProduit >;
    model->setSrcQuerySet( produits );
    model->setDestQuerySet( types );
    model->setRelation( "type", "libelle" );

    QTableView *view = new QTableView;
    view->setModel( model );
    view->show();

    return a.exec();
}
