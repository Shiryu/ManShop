#ifndef NOUVEAUPRODUITDIALOG_H
#define NOUVEAUPRODUITDIALOG_H

#include <QtSql>
#include <QMessageBox>
#include <qdjango/QDjangoQuerySet.h>

#include "core/typeproduit.h"
#include "core/produit.h"

#include "ui_nouveauproduitdialog.h"

class NouveauProduitDialog : public QDialog, private Ui::NouveauProduitDialog
{
    Q_OBJECT

private slots:
    void nouveauProduit();

public:
    explicit NouveauProduitDialog(QWidget *parent = 0);

    void initComposants();
    bool existe( QString code );
};

#endif // NOUVEAUPRODUITDIALOG_H
