#include "connection.h"

Connection* Connection::instance = NULL;

Connection::Connection()
{

}

Connection* Connection::getInstance()
{
    if( instance == NULL )
        instance = new Connection();

    return instance;
}

bool Connection::connecter()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( nomDB );

    db.open();

    QDjango::setDatabase( db );

    QDjango::registerModel< Produit >();
    QDjango::registerModel< ProduitStock >();
    QDjango::registerModel< Stock >();
    QDjango::registerModel< RProduitStock >();
    QDjango::registerModel< Commande >();
    QDjango::registerModel< Fournisseur >();
    QDjango::registerModel< ProduitFournisseur >();
    QDjango::registerModel< ProduitCommande >();
    QDjango::registerModel< RProduitCommande >();
    QDjango::registerModel< Catalogue >();
    QDjango::registerModel< RProduitCatalogue >();
    QDjango::registerModel< Livraison >();
    QDjango::registerModel< Inventaire >();
    QDjango::registerModel< ProduitInventaire >();
    QDjango::registerModel< RProduitInventaire >();
    QDjango::registerModel< Vente >();
    QDjango::registerModel< ProduitVente >();

    if(!QDjango::createTables())
        return false;

    creerTablesSingletons();

    return true;
}

void Connection::creerTablesSingletons()
{
    QSqlQuery creationMagasin, creationCentraleAchat;

    creationMagasin.exec( "CREATE TABLE magasin ( "
                          "code TEXT PRIMARY KEY,"
                          "nom TEXT,"
                          "adresse TEXT )" );

    creationCentraleAchat.exec("CREATE TABLE centraleachat ("
                 "code TEXT PRIMARY KEY,"
                 "nom TEXT,"
                 "adresse TEXT )");
}

Connection::~Connection()
{
    delete instance;
}
