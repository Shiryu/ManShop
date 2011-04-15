#ifndef STOCKCENTRALWIDGET_H
#define STOCKCENTRALWIDGET_H

#include <QtGui>
#include <QtSql>
#include <QDebug>
#include <qdjango/QDjangoQuerySet.h>

#include "core/stock.h"
#include "core/rproduitstock.h"

#include "util/util.h"

#include "ui_stockcentralwidget.h"

class StockCentralWidget : public QWidget, private Ui::StockCentralWidget
{
    Q_OBJECT

private:
    QSqlTableModel *stockModel;
    QSqlQueryModel *produitsModel;

signals:
    void stockSelectionne( bool );

private slots:
    void on_tvStock_clicked();
    void on_tvStock_activated();

public:
    explicit StockCentralWidget( QWidget *parent = 0 );

    void initStockModel();
    void initProduitsModel();
    void initComposants();

    QSqlTableModel* getStockModel() const;

    void afficherProduits();


};

#endif // STOCKCENTRALWIDGET_H
