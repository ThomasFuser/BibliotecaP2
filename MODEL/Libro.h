#ifndef LIBRO_H
#define LIBRO_H

#include"Opera.h"
#include"info.h"


class Libro: public Opera{
private:
    QString autore;
public:
    Libro(const QString& , const QString& , bool=0);
    QString GetAutore() const;
    //virtual bool disponibile() const;
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca_campi(const QString&) const;
    virtual info get_infoTot()const;
    virtual QString get_Tipo()const;
};






#endif // LIBRO_H
