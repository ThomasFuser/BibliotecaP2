#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <QString>


class info
{
private:
    QString titolo;
    QString stato;
    QString ID;
    QString dettaglio;
    QString consultabile;
public:
    info(QString, QString, QString, QString, QString); //costruttore 4 parametri. non  metto volutamente altri costruttori
    QString get_titolo() const;
    QString get_stato() const;
    QString get_ID() const;
    QString get_dettaglio() const;
    QString is_consultabile() const;
};

#endif // INFO_H
