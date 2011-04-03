#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QDebug>

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
    };
};

#endif // UTIL_H
