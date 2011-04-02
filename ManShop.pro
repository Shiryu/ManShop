#-------------------------------------------------
#
# Project created by QtCreator 2011-03-19T13:14:57
#
#-------------------------------------------------

QT       += core gui sql

TARGET = ManShop
TEMPLATE = app

LIBS += /usr/local/lib/libqdjango.a

SOURCES += main.cpp \
    core/produit.cpp \
    core/connection.cpp \
    core/produitstock.cpp \
    core/stock.cpp \
    core/rproduitstock.cpp \
    core/magasin.cpp \
    core/commande.cpp \
    core/centraleachat.cpp \
    core/fournisseur.cpp \
    core/produitfournisseur.cpp \
    core/produitcommande.cpp \
    core/rproduitcommande.cpp \
    core/catalogue.cpp \
    core/rproduitcatalogue.cpp \
    core/livraison.cpp \
    core/inventaire.cpp \
    core/produitinventaire.cpp \
    core/rproduitinventaire.cpp \
    core/vente.cpp \
    core/produitvente.cpp \
    model/mstablemodel.cpp \
    model/msrelationaltablemodel.cpp


HEADERS  += \
    core/objet.h \
    core/produit.h \
    core/connection.h \
    core/produitstock.h \
    core/stock.h \
    core/rproduitstock.h \
    core/magasin.h \
    core/commande.h \
    core/centraleachat.h \
    core/fournisseur.h \
    core/produitfournisseur.h \
    core/produitcommande.h \
    core/rproduitcommande.h \
    core/catalogue.h \
    core/rproduitcatalogue.h \
    core/livraison.h \
    core/inventaire.h \
    core/produitinventaire.h \
    core/rproduitinventaire.h \
    core/vente.h \
    core/produitvente.h \
    model/mstablemodel.h \
    util/util.h \
    model/msrelationaltablemodel.h
