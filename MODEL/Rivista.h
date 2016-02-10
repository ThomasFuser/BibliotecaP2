#ifndef RIVISTA_H
#define RIVISTA_H

#include"Opera.h"
#include"info.h"


class Rivista: public Opera{
private:
    int annoUscita;
    static int maxAnni;
public:
    Rivista(const QString& , int, bool=0);
    int GetMaxAnni() const;
    int GetAnnoUscita() const;
    virtual bool disponibile() const;
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca_campi(const QString&) const;
    virtual info get_infoTot()const;
    virtual void PrestaOpera();
    virtual QString get_Tipo()const;
};

#endif // RIVISTA_H
