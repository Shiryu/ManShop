#ifndef CENTRALEACHAT_H
#define CENTRALEACHAT_H

#include <QtSql>

class CentraleAchat
{

private:
    QString m_code;
    QString m_nom;
    QString m_adresse;

    CentraleAchat();
    static CentraleAchat* instance;

public:
    static CentraleAchat* getInstance();

    QString getCode() const;
    QString getNom() const;
    QString getAdresse() const;

    void setCode( QString code );
    void setNom( QString nom );
    void setAdresse( QString adresse );

    bool save();
};

#endif // CENTRALEACHAT_H
