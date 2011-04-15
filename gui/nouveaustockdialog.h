#ifndef NOUVEAUSTOCKDIALOG_H
#define NOUVEAUSTOCKDIALOG_H

#include "ui_nouveaustockdialog.h"

#include <QtSql>
#include <QMessageBox>
#include <qdjango/QDjangoQuerySet.h>

#include "core/stock.h"

class NouveauStockDialog : public QDialog, private Ui::NouveauStockDialog
{
    Q_OBJECT

private:
    QSqlTableModel *m_model;

private slots:
    void ajouterNouveauStock();

public:
    explicit NouveauStockDialog( QSqlTableModel *model, QWidget *parent = 0 );

    void initComposants();
    bool existe( QString code );
};

#endif // NOUVEAUSTOCKDIALOG_H
