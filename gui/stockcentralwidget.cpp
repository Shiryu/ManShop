#include "stockcentralwidget.h"

StockCentralWidget::StockCentralWidget( QWidget *parent ) : QWidget(parent)
{
    setupUi( this );
    initComposants();

//    connect( stockSelection, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(afficherProduits(QItemSelection,QItemSelection)));
}

void StockCentralWidget::initStockModel()
{
    stockModel = new QSqlTableModel();
    stockModel->setTable( MS::Stock );

    stockModel->setHeaderData( 0, Qt::Horizontal, tr( "Code" ) );
    stockModel->setHeaderData( 1, Qt::Horizontal, tr( "Désignation" ) );
    stockModel->setHeaderData( 2, Qt::Horizontal, tr( "Date Création" ) );
    stockModel->setEditStrategy( QSqlTableModel::OnManualSubmit );

    stockModel->select();
}

void StockCentralWidget::initProduitsModel()
{
    produitsModel = new QSqlQueryModel();
}

void StockCentralWidget::initComposants()
{
    initStockModel();
    initProduitsModel();

    tvStock->setModel( stockModel );
    tvStock->resizeRowsToContents();
    tvStock->resizeColumnsToContents();

    tvStock->sortByColumn( 0, Qt::AscendingOrder );
}

QSqlTableModel* StockCentralWidget::getStockModel() const
{
    return stockModel;
}

void StockCentralWidget::on_tvStock_clicked()
{
    emit stockSelectionne( true );
    afficherProduits();
}

void StockCentralWidget::on_tvStock_activated()
{
    emit stockSelectionne( true );
    afficherProduits();
}

void StockCentralWidget::afficherProduits( )
{
    QModelIndexList indexes = tvStock->selectionModel()->selection().indexes();

    QModelIndex indexCode = indexes.at( 0 );
    QString code = indexCode.data().toString();

    QSqlQuery requete;
//    QSqlQuery requete( "SELECT "
//                       "produit.code, "
//                       "produit.constructeur,"
//                       "produit.nom,"
//                       "produit.description,"
//                       "typeproduit.libelle,"
//                       "rproduitstock.quantite,"
//                       "produit.prixUnitaire "
//                       "FROM rproduitstock, produit, stock, typeproduit "
//                       "WHERE rproduitstock.stock_id = \"S1\" "
//                       "AND produit.code = rproduitstock.produit_id "
//                       "AND produit.type_id = typeproduit.code ");

    requete.prepare( "SELECT DISTINCT "
                     "produit.code, "
                     "produit.constructeur,"
                     "produit.nom,"
                     "produit.description,"
                     "typeproduit.libelle,"
                     "rproduitstock.quantite,"
                     "produit.prixUnitaire "
                     "FROM rproduitstock, produit, stock, typeproduit "
                     "WHERE rproduitstock.stock_id = :code "
                     "AND produit.code = rproduitstock.produit_id "
                     "AND produit.type_id = typeproduit.code " );

    requete.bindValue( ":code", code );
    requete.exec();
    produitsModel->setQuery( requete );

    qDebug() << produitsModel->lastError().text();

    produitsModel->setHeaderData( 0, Qt::Horizontal, tr( "Code" ) );
    produitsModel->setHeaderData( 1, Qt::Horizontal, tr( "Constructeur" ) );
    produitsModel->setHeaderData( 2, Qt::Horizontal, tr( "Nom" ) );
    produitsModel->setHeaderData( 3, Qt::Horizontal, tr( "Description" ) );
    produitsModel->setHeaderData( 4, Qt::Horizontal, tr( "Catégorie" ) );
    produitsModel->setHeaderData( 5, Qt::Horizontal, tr( "Quantité" ) );
    produitsModel->setHeaderData( 6, Qt::Horizontal, tr( "Prix unitaire" ) );

    tvProduits->setModel( produitsModel );

}
