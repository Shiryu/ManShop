#ifndef AJOUTERPRODUITDIALOG_H
#define AJOUTERPRODUITDIALOG_H

#include <QMessageBox>
#include <qdjango/QDjangoModel.h>

#include "core/produit.h"
#include "core/stock.h"
#include "core/rproduitstock.h"

#include "ui_ajouterproduitdialog.h"

class AjouterProduitDialog : public QDialog, private Ui::AjouterProduitDialog
{
    Q_OBJECT

private slots:
    void ajouterProduit();

public:
    explicit AjouterProduitDialog(QWidget *parent = 0);

    void initComposants();
    bool existe( QString codeStock, QString codeProduit );
};

#endif // AJOUTERPRODUITDIALOG_H
