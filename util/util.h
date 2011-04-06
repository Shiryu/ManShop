#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QDebug>
#include <qdjango/QDjangoQuerySet.h>

namespace Util
{
    class Util
    {
    private:
        Util() { }

    public:
        inline static QString formater( QString chaine )
        {
            QString resultat;

            resultat[ 0 ] = chaine[ 0 ].toUpper();

            int position_espace = -1;

            for( int i = 1; i < chaine.size(); ++i )
            {
                resultat[ i ] = chaine[ i ];

                if( chaine[ i ].isUpper() )
                    position_espace = i;
            }

            if( position_espace != -1 )
                resultat.insert( position_espace, QString( " " ) );

            return resultat;
        }

        template < typename S, typename T, typename U >
        inline static QDjangoQuerySet< S > listeProduits( U *u )
        {
            QDjangoQuerySet< T > relations;
            relations = relations.filter( QDjangoWhere( "id", QDjangoWhere::Contains, u->getCode() ) );

            QStringList listeCodes;
            for( int i = 0; i < relations.size(); ++i )
            {
                T *t = relations.at( i );
                listeCodes.append( t->getProduit()->getCode() );
            }

            QDjangoQuerySet< S > resultat;
            resultat = resultat.filter( QDjangoWhere( "code", QDjangoWhere::IsIn, listeCodes ) );

            return resultat;
        }
    };
};

#endif // UTIL_H
