#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <qdjango/QDjango.h>

#include "produit.h"
#include "produitstock.h"
#include "rproduitstock.h"
#include "magasin.h"
#include "commande.h"
#include "centraleachat.h"
#include "fournisseur.h"
#include "produitcommande.h"
#include "rproduitcommande.h"
#include "catalogue.h"
#include "rproduitcatalogue.h"
#include "livraison.h"
#include "inventaire.h"
#include "produitinventaire.h"
#include "rproduitinventaire.h"
#include "vente.h"
#include "produitvente.h"

const QString nomDB = "../Manshop/db/manshop.db";

class Connection
{
private:
    Connection();
    static Connection* instance;

public:
    static Connection* getInstance();

    bool connecter();
    void creerTablesSingletons();

    ~Connection();
};

#endif // CONNECTION_H
