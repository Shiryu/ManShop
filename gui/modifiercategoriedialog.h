#ifndef MODIFIERCATEGORIEDIALOG_H
#define MODIFIERCATEGORIEDIALOG_H

#include <QtSql>
#include <QTableView>
#include <QMessageBox>
#include <qdjango/QDjangoQuerySet.h>

#include "core/typeproduit.h"
#include "util/util.h"

#include "ui_modifiercategoriedialog.h"

class ModifierCategorieDialog : public QDialog, private Ui::ModifierCategorieDialog
{
    Q_OBJECT

private:
    QTableView *m_vue;
    QSqlTableModel *m_model;

private slots:
    void modifierProduit();

public:
    explicit ModifierCategorieDialog( QTableView *vue, QSqlTableModel *model, QWidget *parent = 0 );

    void initComposants();
};

#endif // MODIFIERCATEGORIEDIALOG_H
