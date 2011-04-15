#ifndef PRODUITSCENTRALWIDGET_H
#define PRODUITSCENTRALWIDGET_H

#include <QtSql>
#include <QMessageBox>

#include <qdjango/QDjangoQuerySet.h>

#include "core/produit.h"
#include "core/typeproduit.h"
#include "util/util.h"

#include "modifiercategoriedialog.h"

#include "ui_produitscentralwidget.h"

class ProduitsCentralWidget : public QWidget, private Ui::ProduitsCentralWidget
{
    Q_OBJECT

private:
    QSqlTableModel *categoriesModel;
    QSqlRelationalTableModel *produitsModel;

private slots:
    void on_tvCategories_clicked();
    void on_tvCategories_doubleClicked();

    void on_chBAfficherTout_stateChanged( int state );

signals:
    void categorieSelectionne( bool );
    void produitSelectionne( bool );

public:
    explicit ProduitsCentralWidget(QWidget *parent = 0);

    void initModeles();
    void initComposants();

    QSqlTableModel* getCategoriesModel() { return categoriesModel; }
    QSqlRelationalTableModel* getProduitsModel() { return produitsModel; }

    QTableView* getCategoriesVue() { return tvCategories; }
};

#endif // PRODUITSCENTRALWIDGET_H
