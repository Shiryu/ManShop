#ifndef AJOUTERPRODUITSDIALOG_H
#define AJOUTERPRODUITSDIALOG_H

#include <QtSql>
#include <QMessageBox>
#include <qdjango/QDjangoQuerySet.h>

#include "core/typeproduit.h"
#include "core/produit.h"
#include "core/temp.h"
#include "util/util.h"

#include "ui_nouveauxproduitsdialog.h"

class NouveauxProduitsDialog : public QDialog, private Ui::NouveauxProduitsDialog
{
    Q_OBJECT

private:
    QSqlRelationalTableModel *produitsModel;

    QDjangoQuerySet< Core::TypeProduit > types;

private slots:
    void on_btAjouter_clicked();
    void on_btEffacer_clicked();
    void on_btValider_clicked();
    void on_btAnnuler_clicked();
    void on_btTerminer_clicked();

signals:
    void produitAjoute( bool );

public:
    explicit NouveauxProduitsDialog( QWidget *parent = 0 );

    int initLimite();
    void initModeles();
    void initComposants();

    void cacherProduitsExistants();
    bool existe( QString code );
    void effacerChamps();
};

#endif // AJOUTERPRODUITSDIALOG_H
