#include "produitscentralwidget.h"

ProduitsCentralWidget::ProduitsCentralWidget( QWidget *parent ) : QWidget( parent )
{
    setupUi(this);

    initComposants();

}

void ProduitsCentralWidget::initModeles()
{
    categoriesModel = new QSqlTableModel();
    categoriesModel->setTable( MS::TypeProduit );
    categoriesModel->setHeaderData( 0, Qt::Horizontal, tr( "Code" ) );
    categoriesModel->setHeaderData( 1, Qt::Horizontal, tr( "Nom" ) );
    categoriesModel->select();

    produitsModel = new QSqlRelationalTableModel();
    produitsModel->setTable( MS::Produit );
    produitsModel->setRelation( 4, QSqlRelation(  MS::TypeProduit, "code", "libelle" ) );
    produitsModel->setHeaderData( 0, Qt::Horizontal, tr( "Code" ) );
    produitsModel->setHeaderData( 1, Qt::Horizontal, tr( "Constructeur"  ) );
    produitsModel->setHeaderData( 2, Qt::Horizontal, tr( "Nom" ) );
    produitsModel->setHeaderData( 3, Qt::Horizontal, tr( "Description" ) );
    produitsModel->setHeaderData( 4, Qt::Horizontal, tr( "Catégorie" ) );
    produitsModel->setHeaderData( 5, Qt::Horizontal, tr( "Prix unitaire" ) );
    produitsModel->select();
}

void ProduitsCentralWidget::initComposants()
{
    initModeles();

    tvCategories->setModel( categoriesModel );
    tvCategories->resizeRowsToContents();
    tvCategories->resizeColumnsToContents();

    tvProduits->setModel( produitsModel );
    tvProduits->resizeRowsToContents();
    tvProduits->resizeColumnsToContents();
}

void ProduitsCentralWidget::on_tvCategories_clicked()
{
    emit categorieSelectionne( true );

    chBAfficherTout->setChecked( false );
    QModelIndexList indexes = tvCategories->selectionModel()->selection().indexes();
    QModelIndex codeIndex = indexes.at( 0 );
    QString code = codeIndex.data().toString();

    produitsModel->setFilter( "produit.type_id = '" + code + "'");

}

void ProduitsCentralWidget::on_tvCategories_doubleClicked()
{
    ModifierCategorieDialog *dialog = new ModifierCategorieDialog( tvCategories, categoriesModel, this );
    dialog->show();
}

void ProduitsCentralWidget::on_chBAfficherTout_stateChanged( int state )
{
    if( chBAfficherTout->isChecked() )
    {
        produitsModel->setFilter( "produit.type_id IS NOT NULL" );
        produitsModel->select();
    }
}
