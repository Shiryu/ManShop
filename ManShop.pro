#-------------------------------------------------
#
# Project created by QtCreator 2011-03-19T13:14:57
#
#-------------------------------------------------

QT       += core gui sql

TARGET = ManShop
TEMPLATE = app

#INCLUDEPATH += /opt/kdreports/include
#INCLUDEPATH += /opt/kdchart/include

LIBS += C:\Qt\2010.05\mingw\lib\libqdjango.a

#LIBS += /usr/local/lib/libqdjango.a

#LIBS += /opt/kdreports/lib/*
#LIBS += /opt/kdchart/lib/libkdchart.so

SOURCES += main.cpp \
    core/produit.cpp \
    core/connection.cpp \
    #core/produitstock.cpp \
    core/stock.cpp \
    core/rproduitstock.cpp \
    core/magasin.cpp \
    core/commande.cpp \
    core/centraleachat.cpp \
    core/fournisseur.cpp \
    #core/produitfournisseur.cpp \
    #core/produitcommande.cpp \
    core/rproduitcommande.cpp \
    core/catalogue.cpp \
    core/rproduitcatalogue.cpp \
    core/livraison.cpp \
    core/inventaire.cpp \
    #core/produitinventaire.cpp \
    core/rproduitinventaire.cpp \
    core/vente.cpp \
    #core/produitvente.cpp \
    core/typeproduit.cpp \
    gui/mswindow.cpp \
    gui/stockcentralwidget.cpp \
    gui/nouveaustockdialog.cpp \
    core/rproduitvente.cpp \
    core/etat.cpp \
    gui/ajouterproduitdialog.cpp \
    gui/produitscentralwidget.cpp \
    gui/nouvellecategoriedialog.cpp \
    gui/nouveauproduitdialog.cpp \
    gui/nouveauxproduitsdialog.cpp \
    core/temp.cpp \
    gui/modifiercategoriedialog.cpp
    #model/mstablemodel_.cpp


HEADERS  += \
    core/objet.h \
    core/produit.h \
    core/connection.h \
    #core/produitstock.h \
    core/stock.h \
    core/rproduitstock.h \
    core/magasin.h \
    core/commande.h \
    core/centraleachat.h \
    core/fournisseur.h \
    #core/produitfournisseur.h \
    #core/produitcommande.h \
    core/rproduitcommande.h \
    core/catalogue.h \
    core/rproduitcatalogue.h \
    core/livraison.h \
    core/inventaire.h \
    #core/produitinventaire.h \
    core/rproduitinventaire.h \
    core/vente.h \
    #core/produitvente.h \
    #model/mstablemodel.h \
    util/util.h \
    #model/msrelationaltablemodel.h \
    core/typeproduit.h \
    gui/mswindow.h \
    gui/stockcentralwidget.h \
    gui/nouveaustockdialog.h \
    core/rproduitvente.h \
    core/etat.h \
    gui/ajouterproduitdialog.h \
    gui/produitscentralwidget.h \
    gui/nouvellecategoriedialog.h \
    gui/nouveauproduitdialog.h \
    gui/nouveauxproduitsdialog.h \
    core/temp.h \
    gui/modifiercategoriedialog.h
    #model/mstablemodel_.h

FORMS += \
    gui/mswindow.ui \
    gui/stockcentralwidget.ui \
    gui/nouveaustockdialog.ui \
    gui/ajouterproduitdialog.ui \
    gui/produitscentralwidget.ui \
    gui/nouvellecategoriedialog.ui \
    gui/nouveauproduitdialog.ui \
    gui/nouveauxproduitsdialog.ui \
    gui/modifiercategoriedialog.ui

RESOURCES += \
    gui/ressources.qrc
