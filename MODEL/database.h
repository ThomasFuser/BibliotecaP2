#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>

#include"container.h"               //contenitore
#include"Opera.h"                   //classe base della gerarchia
#include"Rivista.h"                 //derivata 1
#include"Libro.h"                   //derivata 2


class DataBase{
private:
    //campi dati
    static QString filename;
    container db;

    Opera* Trova_Precisa(const int) const;                   //ricerca una precisa opera identificata dal suo puntatore
    //POST=( ritorna puntatore ad opera <=> id identifica un'opera presente nel catalogo. op ha ID=id )

    void Load();                                        //crea il contenitore in RAM leggendo il file xml
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
    DataBase();
    ~DataBase();

    bool vuoto() const;                                 //ritorna true <=> container è vuoto altrimenti ritorna false

    //PRE=(Vdb=vecchio database.Ndb=nuovo database, (1)op può essere puntatore a opera non valida=NULL, (2)db può essere vuoto, (3)l'opera può non essere nel DataBase, (4) opera presente )
    void remove_opera(const int);                          //elimina una opera
    //POST=(se vale (1),(2),(3): Vbd=Ndb altrimenti (4) Vdb=Ndb-Opera)

    //PRE=(La stringa passata alla funzione può essere o non essere presente in nessun campo dati di nessun oggetto del DataBase)
    container cerca_opera(const QString&) const;        //cerca una opera cercando in tutti i campi di essa (ricerca polimorfa). la ricerca è caseInsensitive
    //POST=(il contenitore ritornato è vuoto <=> la stringa non è stata trovata in nessuna opera mentre; altrimenti il contenitore contiene tutte le opere con un campo dati che matcha con la stringa passata)

    void Add_Opera(Opera*);                             //metodo che aggiunge un'opera -> ci possono essere due opere uguali

    void Mod_Opera(const int id, const QString&, const QString&, const QString&); //metodo che modifica i campi dati dell'oggetto puntato da Opera*







    //******************************  ITERATORI DISPONIBII PER TEST ******************************//
    // rendo accessibile l'utilizzo degli iteratori del contenitore
    // container::iteratore db_iteratore;
    container::iteratore db_iterator;

    container::iteratore db_begin();
    container::iteratore db_end();


};



#endif // DATABASE_H






















