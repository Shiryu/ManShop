#include "nouveaustockdialog.h"

using namespace Core;

NouveauStockDialog::NouveauStockDialog( QSqlTableModel *model, QWidget *parent ) : QDialog( parent), m_model( model )
{
    setupUi(this);

    initComposants();

    connect( this, SIGNAL(accepted()), this, SLOT(ajouterNouveauStock()));
}

void NouveauStockDialog::initComposants()
{
    edDate->setDate( QDate::currentDate() );
    edDate->setEnabled( false );
}

bool NouveauStockDialog::existe( QString code )
{
    QDjangoQuerySet< Stock > *stocks = new QDjangoQuerySet< Stock >;
    int l = stocks->size();

    for( int i = 0; i < l; ++i )
    {
        Stock *temp = stocks->at( i );

        if( temp->getCode() == code )
            return true;
    }

    return false;
}

void NouveauStockDialog::ajouterNouveauStock()
{
    QString code = edCode->text();
    QString nom = edNom->text();
    QDate date = edDate->date();

    if( code == QString("") || nom == QString("") )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez renseigner toutes les informations" );
        show();
    }
    else if( existe( code ) )
    {
        QMessageBox::warning( this, "Informations dupliquées", "Un stock portant le code " + code + " existe déjà\nVeuillez en choisir un autre" );
        edCode->setFocus();
        edCode->selectAll();
        show();
    }
    else
    {
        Stock *nouveau = new Stock();
        nouveau->setCode( code );
        nouveau->setNom( nom );
        nouveau->setDateCreation( date );

        nouveau->save();

        m_model->select();
    }
}
