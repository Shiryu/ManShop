#include "connection.h"

namespace Core
{
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

        QDjango::registerModel< Core::Produit >();
        QDjango::registerModel< Core::ProduitStock >();
        QDjango::registerModel< Core::Stock >();
        QDjango::registerModel< Core::RProduitStock >();
        QDjango::registerModel< Core::Commande >();
        QDjango::registerModel< Core::Fournisseur >();
        QDjango::registerModel< Core::ProduitFournisseur >();
        QDjango::registerModel< Core::ProduitCommande >();
        QDjango::registerModel< Core::RProduitCommande >();
        QDjango::registerModel< Core::Catalogue >();
        QDjango::registerModel< Core::RProduitCatalogue >();
        QDjango::registerModel< Core::Livraison >();
        QDjango::registerModel< Core::Inventaire >();
        QDjango::registerModel< Core::ProduitInventaire >();
        QDjango::registerModel< Core::RProduitInventaire >();
        QDjango::registerModel< Core::Vente >();
        QDjango::registerModel< Core::ProduitVente >();

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

}
