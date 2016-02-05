#ifndef RIVISTA_H
#define RIVISTA_H

#include"Opera.h"
#include"info.h"


class Rivista: public Opera{
private:
    int annoUscita;
    static int maxAnni;
public:
    Rivista(QString, int, bool=0);              //costruttore
    int GetMaxAnni() const;                         //ritorna max anni prestito
    int GetAnnoUscita() const;                      //ritorna l'anno di uscita della rivista
    void Set_Anno_Uscita(int);
    static void SetMaxAnni(const int);              //aumenta/diminuisce max anni per cui rivista è disponibile

   // virtual ~Rivista(){};
    virtual bool disponibile() const;               // la rivista è disponibile per la consultazione?
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca_campi(const QString&) const;
    virtual void Mod_Opera(const QString&, const QString&, const QString&);
    virtual bool Match_Opera(const Opera*) const{ return 0; }
    virtual info get_infoTot()const;

    virtual void PrestaOpera();                                             // setta a 0 "stato" -> per segnalare il prestito di un'opera


    virtual QString get_Tipo()const;
};

#endif // RIVISTA_H
