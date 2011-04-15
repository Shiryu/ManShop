#include "modifiercategoriedialog.h"

#include <QDebug>

ModifierCategorieDialog::ModifierCategorieDialog( QTableView *vue, QSqlTableModel *model, QWidget *parent ) :
        QDialog( parent ),
        m_vue( vue ),
        m_model( model )
{
    setupUi( this );

    initComposants();

    connect( this, SIGNAL( accepted() ), this, SLOT( modifierProduit() ) );
}

void ModifierCategorieDialog::initComposants()
{
    QModelIndexList indexes = m_vue->selectionModel()->selection().indexes();
    QModelIndex codeIndex = indexes.at( 0 );
    QModelIndex nomIndex = indexes.at( 1 );

    QString code = codeIndex.data().toString();
    QString nom = nomIndex.data().toString();

    edCode->setText( code );
    edNom->setText( nom );

    edNom->setFocus();
    edNom->selectAll();
}

void ModifierCategorieDialog::modifierProduit()
{
    QString code = edCode->text();
    QString nom = edNom->text();

    QDjangoQuerySet< Core::TypeProduit > types;
    Core::TypeProduit *t = types.get( QDjangoWhere( "code", QDjangoWhere::Equals, code ) );

    if( code == "" || nom == "" )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez fournir toutes les informations" );
        show();
    }
    else
    {
        t->setLibelle( nom );
        t->save();
    }

    m_model->select();
}
