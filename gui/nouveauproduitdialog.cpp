#include "nouveauproduitdialog.h"

NouveauProduitDialog::NouveauProduitDialog( QWidget *parent ) : QDialog( parent )
{
    setupUi( this );

    initComposants();
    connect( this, SIGNAL( accepted() ), this, SLOT( nouveauProduit() ) );
}

void NouveauProduitDialog::initComposants()
{
    QDjangoQuerySet< Core::TypeProduit > types;
    int l = types.size();

    for( int i = 0; i < l; ++i )
    {
        Core::TypeProduit *t = types.at( i );
        cbCategorie->insertItem( i, t->getLibelle() );
    }
}

bool NouveauProduitDialog::existe( QString code )
{
    QDjangoQuerySet< Core::Produit > produits;
    int l = produits.size();

    for( int i = 0; i < l; ++i )
    {
        Core::Produit *p = produits.at( i );

        if( p->getCode() == code )
            return true;
    }

    return false;
}

void NouveauProduitDialog::nouveauProduit()
{
    QString code = edCode->text();
    QString constructeur = edConstructeur->text();
    QString nom = edNom->text();
    QString categorie = cbCategorie->currentText();
    QString description = edDescription->toPlainText();
    double prixUnitaire = sbPrixUnitaire->value();

    if( code == "" || constructeur == "" || nom == "" || description == "" )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez fournir toutes les informations" );
        show();
    }
    else if( existe( code ) )
    {
        QMessageBox::warning( this, "Informations dupliquées", "Un produit portant le code " + code + " existe déjà\n"
                              "Veuillez en fournir un autre" );
        edCode->setFocus();
        edCode->selectAll();
        show();
    }
    else
    {
        QDjangoQuerySet< Core::TypeProduit > types;
        Core::TypeProduit *t = types.get( QDjangoWhere( "libelle", QDjangoWhere::Equals, categorie ) );


        Core::Produit *p = new Core::Produit();
        p->setCode( code );
        p->setConstructeur( constructeur );
        p->setNom( nom );
        p->setType( t );
        p->setDescription( description );
        p->setPrixUnitaire( prixUnitaire );
        p->save();
    }
}
