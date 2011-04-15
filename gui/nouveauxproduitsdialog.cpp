#include "nouveauxproduitsdialog.h"

NouveauxProduitsDialog::NouveauxProduitsDialog( QWidget *parent ) : QDialog( parent )
{
    setupUi( this );

    initComposants();

    connect( this, SIGNAL( produitAjoute( bool ) ), btValider, SLOT( setEnabled( bool ) ) );
}

void NouveauxProduitsDialog::initModeles()
{
    produitsModel = new QSqlRelationalTableModel();
    produitsModel->setTable( MS::Temp );

    produitsModel->setRelation( 4, QSqlRelation( MS::TypeProduit, "code", "libelle" ) );

    produitsModel->setHeaderData( 0, Qt::Horizontal, tr( "Code" ) );
    produitsModel->setHeaderData( 1, Qt::Horizontal, tr( "Constructeur" ) );
    produitsModel->setHeaderData( 2, Qt::Horizontal, tr( "Nom" ) );
    produitsModel->setHeaderData( 3, Qt::Horizontal, tr( "Description") );
    produitsModel->setHeaderData( 4, Qt::Horizontal, tr( "Catégorie" ) );
    produitsModel->setHeaderData( 5, Qt::Horizontal, tr( "Prix unitaire" ) );

    produitsModel->select();
}

void NouveauxProduitsDialog::initComposants()
{
    initModeles();

    tvProduits->setModel( produitsModel );

    tvProduits->resizeColumnsToContents();
    tvProduits->resizeRowsToContents();
    tvProduits->setItemDelegate( new QSqlRelationalDelegate( tvProduits ) );

    int l = types.size();

    for( int i = 0; i < l; ++i )
    {
        Core::TypeProduit *t = types.at( i );
        cbCategorie->insertItem( i, t->getLibelle() );
    }
}

bool NouveauxProduitsDialog::existe( QString code )
{
    QDjangoQuerySet< Core::Produit > produits;
    int l = produits.size();

    for(  int i = 0; i < l; ++i )
    {
        Core::Produit *p = produits.at( i );
        if( p->getCode() == code )
            return true;
    }

    return false;
}

void NouveauxProduitsDialog::on_btAjouter_clicked()
{
    QString code = edCode->text();
    QString constructeur = edConstructeur->text();
    QString nom = edNom->text();
    QString description = edDescription->text();
    QString categorie = cbCategorie->currentText();
    double prixUnitaire = sbPrixUnitaire->value();

    if( code == "" || constructeur == "" || nom == "" || description == "" )
    {
        QMessageBox::warning( this, "Informations incomplètes", "Vous devez renseigner toutes les informations" );
        show();
    }
    else if( existe( code ) )
    {
        QMessageBox::warning( this, "Informations dupliquées", "Un produit portant le code " + code + " existe déjà\n"
                              "Veuillez en renseigner un autre" );
        edCode->setFocus();
        edCode->selectAll();
        show();
    }
    else
    {
        emit produitAjoute( true );

        Core::TypeProduit *t = types.get( QDjangoWhere( "libelle", QDjangoWhere::Equals, categorie ) );

        Core::Temp *p = new Core::Temp();
        p->setCode( code );
        p->setConstructeur( constructeur );
        p->setNom( nom );
        p->setDescription( description );
        p->setType( t );
        p->setPrixUnitaire( prixUnitaire );
        p->save();


        produitsModel->select();

        effacerChamps();
    }
}

void NouveauxProduitsDialog::on_btEffacer_clicked()
{
    effacerChamps();
}

void NouveauxProduitsDialog::on_btValider_clicked()
{
    QDjangoQuerySet< Core::Temp > produits;
    int l = produits.size();

    for( int i = 0; i < l; ++i )
    {
        Core::Temp *t = produits.at( i );

        Core::Produit *p = new Core::Produit();
        p->setCode( t->getCode() );
        p->setConstructeur( t->getConstructeur() );
        p->setNom( t->getNom() );
        p->setDescription( t->getDescription() );
        p->setType( t->getType() );
        p->setPrixUnitaire( t->getPrixUnitaire() );
        p->save();
    }

    produits.remove();

}

void NouveauxProduitsDialog::on_btAnnuler_clicked()
{
    QDjangoQuerySet< Core::Temp > produits;
    produits.remove();
    produitsModel->select();

    effacerChamps();

    btValider->setEnabled( false );
}

void NouveauxProduitsDialog::on_btTerminer_clicked()
{
    if( QMessageBox::question( this, "Question", "Voulez-vous vraiment fermer cette boîte de dialogue ?\n"
                               "Toutes les modifications non enregistrées seront perdues",
                               QMessageBox::Yes | QMessageBox::No ) == QMessageBox::No )
        show();
    else
    {
        QDjangoQuerySet< Core::Temp > produits;
        produits.remove();

        close();
    }
}

void NouveauxProduitsDialog::effacerChamps()
{
    edCode->clear();
    edConstructeur->clear();
    edDescription->clear();
    edNom->clear();
    cbCategorie->setCurrentIndex( 0 );
    sbPrixUnitaire->setValue( 0.0 );

    edCode->setFocus();
}
