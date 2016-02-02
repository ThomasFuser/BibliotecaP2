#ifndef LIBRO_H
#define LIBRO_H

#include"Opera.h"
#include"info.h"


class Libro: public Opera{
private:
    QString autore;
public:
    Libro(QString, QString, bool=0);
    QString GetAutore() const;
    void Set_Autore(const QString&);

    //definizione metodi virtuali puri
    virtual ~Libro(){};
    virtual bool disponibile() const;
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca_campi(const QString&) const;
    virtual void Mod_Opera(const QString&, const QString&, const QString&);
    virtual info get_infoTot()const;
   // virtual QString Get_info() const;

    virtual QString get_Tipo()const;
};






#endif // LIBRO_H
