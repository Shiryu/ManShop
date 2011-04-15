#include "nouvellecategoriedialog.h"

NouvelleCategorieDialog::NouvelleCategorieDialog( QSqlTableModel *model, QWidget *parent ) :
        QDialog( parent ),
        m_model( model )
{
    setupUi( this );

    connect( this, SIGNAL( accepted() ), this, SLOT( nouvelleCategorie() ) );
}

bool NouvelleCategorieDialog::existe( QString code )
{
    QDjangoQuerySet< Core::TypeProduit > types;
    int l = types.size();

    for( int i = 0; i < l; ++i )
    {
        if( types.at( i )->getCode() == code )
            return true;
    }

    return false;
}

void NouvelleCategorieDialog::nouvelleCategorie()
{
    QString code = edCode->text();
    QString libelle = edNom->text();

    if( code == QString("") || libelle == QString("") )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez fournir toutes les informations" );
        show();
    }
    else if( existe( code ) )
    {
        QMessageBox::warning( this, "Informations dupliquées", "Une catégorie portant le code " + code + " existe déjà\n"
                              "Veuillez en choisir un autre" );
        edCode->setFocus();
        edCode->selectAll();
        show();
    }
    else
    {
        Core::TypeProduit *t = new Core::TypeProduit();
        t->setCode( code );
        t->setLibelle( libelle );
        t->save();

        m_model->select();
    }
}

