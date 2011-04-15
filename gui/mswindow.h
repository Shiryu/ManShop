#ifndef MSWINDOW_H
#define MSWINDOW_H

#include "ui_mswindow.h"

#include "nouveaustockdialog.h"
#include "stockcentralwidget.h"
#include "ajouterproduitdialog.h"
#include "produitscentralwidget.h"
#include "nouvellecategoriedialog.h"
#include "nouveauproduitdialog.h"
#include "nouveauxproduitsdialog.h"
#include "modifiercategoriedialog.h"

class MSWindow : public QMainWindow, private Ui::MSWindow
{
    Q_OBJECT

private:
    StockCentralWidget *sWidget;
    ProduitsCentralWidget *produitsWidget;

private slots:
    void on_tbControle_currentChanged( int page );

    void on_btNouveauStock_clicked();
    void on_btSupprimerStock_clicked();
    void on_btAjouterProduit_clicked();
    void on_btNouvelleCategorie_clicked();
    void on_btNouveauProduit_clicked();
    void on_btNouveauxProduits_clicked();

public:
    enum
    {
        Produits = 1,
        Stock,
        Commande,
        Inventaire,
        Vente
    };

    explicit MSWindow( QWidget *parent = 0 );

    void initComposants();

};

#endif // MSWINDOW_H
