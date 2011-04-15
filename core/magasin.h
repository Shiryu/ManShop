#ifndef MAGASIN_H
#define MAGASIN_H

#include <QtSql>

namespace Core
{
    class Magasin
    {

    private:
        QString m_code;
        QString m_nom;
        QString m_adresse;

        Magasin();
        static Magasin* instance;

    public:
        static Magasin* getInstance();

        QString getCode() const;
        QString getNom() const;
        QString getAdresse() const;

        void setCode( QString code );
        void setNom( QString nom );
        void setAdresse( QString description );


        bool save();

        ~Magasin();
    };
};

#endif // MAGASIN_H
