#ifndef OPERA_H
#define OPERA_H

#include<iostream>
#include <QString>
#include<QXmlStreamWriter>


class Opera{
private:
    //campi dati
    QString titolo;
    bool statoP;                                    //{ 0:non presente in biblioteca; 1:presente }
    int ID;

    static int maxId;
public:
    Opera(QString , bool =0);
    QString GetTitolo()const;                                               // ritorna il titolo dell'opera
    bool Presente()const;                                                   // ritorna {0: in prestito , 1: non in prestito (presente)}
    void PrestaOpera();                                                     // setta a 0 "stato" -> per segnalare il prestito di un'opera
    void RiscattaOpera();                                                   // setta a 1 "stato" -> per segnalare la restituzione di un'opera
    void Set_Titolo(const QString&);                                        //modifica campo titolo

    void Set_Id(const int);         //setta Id Opera
    void Set_Max(const int);        //setta Id max
    int Get_Id() const;             //ritorna Id opera
    int Get_Max() const;            //ritorna il massimo Id opera

    //metodi virtuali
    virtual ~Opera(){};
    virtual bool ricerca_campi(const QString& ) const;                      //controlla nei campi delle opere se è presente l'opera in questione
    virtual bool disponibile()const =0;                                     //l'opera è disponibile per il prestito?
    virtual void Write_Opera(QXmlStreamWriter& xmlWriter) const =0;         //metodo stampa dell'opera
    virtual void Mod_Opera(const QString&, const QString&, const QString&);
  //  virtual QString Get_info() const{}
   virtual QString get_Tipo()const =0;                                     //ritorna il ripo dell'opera (ATTENZIONE)



};








#endif // OPERA_H