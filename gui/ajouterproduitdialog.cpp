#include "ajouterproduitdialog.h"

using namespace Core;

AjouterProduitDialog::AjouterProduitDialog( QWidget *parent ) : QDialog( parent )
{
    setupUi( this );

    initComposants();

    connect( this, SIGNAL( accepted() ), this, SLOT( ajouterProduit() ) );
}

void AjouterProduitDialog::initComposants()
{
    QDjangoQuerySet< Core::Stock > stocks;
    int l = stocks.size();

    for( int i = 0; i < l; ++i )
    {
        Core::Stock *s = stocks.at( i );
        cbNomStock->insertItem( i, s->getNom() );
    }

    QDjangoQuerySet< Core::TypeProduit > types;
    int m = types.size();

    for( int i = 0; i < m; ++i )
    {
        Core::TypeProduit *t = types.at( i );
        cbCategorie->insertItem( i, t->getLibelle() );
    }
}

bool AjouterProduitDialog::existe( QString codeStock, QString codeProduit )
{
    QDjangoQuerySet< RProduitStock > relations;
    relations = relations.filter( QDjangoWhere( "id", QDjangoWhere::Contains, codeStock ) );

    int l = relations.size();

    for( int i = 0; i < l; ++i )
    {
        RProduitStock *r = relations.at( i );

        if( r->getProduit()->getCode() == codeProduit )
            return true;
    }

    return false;
}

void AjouterProduitDialog::ajouterProduit()
{
    QString nomStock = cbNomStock->currentText();
    QString code = edCode->text();
    QString constructeur = edConstructeur->text();
    QString nom = edNom->text();
    QString description = edDescription->toPlainText();
    int quantite = sbQuantite->value();
    double prixUnitaire = sbPrixUnitaire->value();

    QDjangoQuerySet< Core::Stock > stocks;
    Core::Stock *s = stocks.get( QDjangoWhere( "nom", QDjangoWhere::Equals, nomStock ) );

    QDjangoQuerySet< Core::TypeProduit > types;
    Core::TypeProduit *t = types.get( QDjangoWhere( "libelle", QDjangoWhere::Equals, cbCategorie->currentText() ) );

    if( code == QString("") || constructeur == QString("") || nom == QString("") || description == QString("") )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez renseigner toutes les informations" );
        show();
    }
    else if( existe( s->getCode(), code ) )
    {
        QMessageBox::warning( this, "Informations dupliquées", "Un produit portant le code " + code + " existe déjà dans le stock " + nomStock );
        show();
    }
    else
    {
        Core::Produit *p = new Core::Produit();
        p->setCode( code );
        p->setConstructeur( constructeur );
        p->setNom( nom );
        p->setDescription( description );
        p->setPrixUnitaire( prixUnitaire );
        p->setType( t );
        p->save();

        Core::RProduitStock *r = new Core::RProduitStock;
        r->setProduit( p );
        r->setStock( s );
        r->setQuantite( quantite );
        r->save();
    }
}
