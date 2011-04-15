#include "mswindow.h"
#include <QDebug>

MSWindow::MSWindow( QWidget *parent ) : QMainWindow( parent )
{
    setupUi( this );
    initComposants();

    setCentralWidget( produitsWidget );
    showMaximized();

    connect( sWidget, SIGNAL( stockSelectionne( bool ) ), btSupprimerStock, SLOT( setEnabled( bool ) ) );
    connect( produitsWidget, SIGNAL( categorieSelectionne( bool ) ), btSupprimerCategorie, SLOT( setEnabled( bool ) ) );
}

void MSWindow::initComposants()
{
    sWidget = new StockCentralWidget();
    produitsWidget = new ProduitsCentralWidget();
//    produitsWidget = 0;

    //btSupprimerStock->setEnabled( false );
}

void MSWindow::on_tbControle_currentChanged( int page )
{
    QString nom = tbControle->itemText( page );

    if( nom == "Produits" )
    {
        produitsWidget = new ProduitsCentralWidget();
//        btModifierCategorie->setEnabled( false );
        setCentralWidget( produitsWidget );
    }
    else if( nom == "Stock" )
    {
        sWidget = new StockCentralWidget();
        setCentralWidget( sWidget );
    }
}

void MSWindow::on_btNouveauStock_clicked()
{
    NouveauStockDialog *dialog = new NouveauStockDialog( sWidget->getStockModel(), this );
    dialog->show();
}

void MSWindow::on_btSupprimerStock_clicked()
{

}

void MSWindow::on_btAjouterProduit_clicked()
{
    AjouterProduitDialog *dialog = new AjouterProduitDialog( this );
    dialog->show();
}

void MSWindow::on_btNouvelleCategorie_clicked()
{
    NouvelleCategorieDialog *dialog = new NouvelleCategorieDialog( produitsWidget->getCategoriesModel(), this );
    dialog->show();
}

void MSWindow::on_btNouveauProduit_clicked()
{
    NouveauProduitDialog *dialog = new NouveauProduitDialog( this );
    dialog->show();
}

void MSWindow::on_btNouveauxProduits_clicked()
{
    NouveauxProduitsDialog *dialog = new NouveauxProduitsDialog( this );
    dialog->show();
}
