#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <qdjango/QDjango.h>

#include "produit.h"
#include "rproduitstock.h"
#include "magasin.h"
#include "commande.h"
#include "centraleachat.h"
#include "fournisseur.h"
#include "rproduitcommande.h"
#include "catalogue.h"
#include "rproduitcatalogue.h"
#include "livraison.h"
#include "inventaire.h"
#include "produitinventaire.h"
#include "rproduitinventaire.h"
#include "vente.h"
#include "typeproduit.h"
#include "rproduitvente.h"
#include "etat.h"
#include "temp.h"

//const QString nomDB = "/home/feysal/ManShop/db/manshop.db";

const QString nomDB = "C:\\Documents and Settings\\Administrateur\\Mes documents\\ManShop\\db\\manshop.db";

namespace Core
{
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
};

#endif // CONNECTION_H
