#ifndef NOUVELLECATEGORIEDIALOG_H
#define NOUVELLECATEGORIEDIALOG_H

#include <QtSql>
#include <QMessageBox>

#include <qdjango/QDjangoQuerySet.h>

#include "core/produit.h"
#include "core/typeproduit.h"
#include "produitscentralwidget.h"

#include "ui_nouvellecategoriedialog.h"

class NouvelleCategorieDialog : public QDialog, private Ui::NouvelleCategorieDialog
{
    Q_OBJECT

private:
    QSqlTableModel *m_model;

private slots:
    void nouvelleCategorie();

public:
    explicit NouvelleCategorieDialog( QSqlTableModel *model, QWidget *parent = 0 );

    bool existe( QString code );
};

#endif // NOUVELLECATEGORIEDIALOG_H
