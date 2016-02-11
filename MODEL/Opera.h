#ifndef OPERA_H
#define OPERA_H

#include<iostream>
#include <QString>
#include<QXmlStreamWriter>
#include "info.h"

enum Exc{imp_prestare};

class Opera{
private:
    //campi dati
    QString titolo;
    bool statoP;                                                             //{ 0:non presente in biblioteca; 1:presente }
    int ID;

    static int maxId;
public:
    Opera(const QString& , bool =0);
    QString GetTitolo()const;                                                //ritorna il titolo dell'opera
    int  Get_Id() const;                                                     //ritorna Id opera
    int  Get_Max() const;                                                    //ritorna il massimo Id opera  
    bool Presente()const;                                                    //ritorna {0: in prestito , 1: non in prestito (presente)}
    void Set_Id(const int);                                                  //setta Id Opera
    void Set_Max(const int);                                                 //setta Id max
    void RiscattaOpera();                                                    //setta a 1 "stato" -> per segnalare la restituzione di un'opera

    virtual ~Opera();
    virtual bool ricerca_campi(const QString& ) const;                      //controlla nei campi delle opere se è presente l'opera in questione
    virtual bool disponibile()const =0;                                     //l'opera è disponibile per il prestito?
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const =0;         //metodo di scrittura nel file xml dell'opera polimorfa
    virtual void PrestaOpera();                                             //setta a 0 "stato" -> per segnalare il prestito di un'opera (se è possibile prestare l'opera)
    virtual info get_infoTot()const =0;                                     //ritorna tutte le informazioni dell'opera selezionata
    virtual QString get_Tipo()const =0;                                     //ritorna il tipo dell'opera

};








#endif // OPERA_H
