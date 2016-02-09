#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include"container.h"               //contenitore
#include"Opera.h"                   //classe base della gerarchia
#include"Rivista.h"                 //derivata 1
#include"Libro.h"                   //derivata 2
#include"info.h"

#include"../VIEW/widget_padre.h"

//class Widget_Padre;

class DataBase{
private:
    //campi dati
    static QString filename;
    container db;
    std::vector<Widget_Padre*> registro;                //registro delle view collegate al modello
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
    void add_Rivista(info);
    void add_Libro(info);
    //ritorna un oggetto "info" contenente tutte le informazioni riguardanti un' opera con un preciso ID. se l'opera non è oresente la funzione ritorna un oggetto info con tutti i suoi campi contenenti "sconosciuto" mentre nel campo corrispondente ad ID: ID non valido
    info get_infoOpera(int) const;

    Opera* Trova_Precisa(int) const;                   //ricerca una precisa opera identificata dal suo puntatore
    //POST=( ritorna puntatore ad opera <=> id identifica un'opera presente nel catalogo. op ha ID=id )

    void Presta_ricevi(int);


    void aggiorna_view() const;
    void add_registro(Widget_Padre*);
    void remove_registro(Widget_Padre*);
    void svuota_contenitore();
    //******************************  ITERATORI DISPONIBII PER TEST ******************************//
    // rendo accessibile l'utilizzo degli iteratori del contenitore
    // container::iteratore db_iteratore;
    container::iteratore db_iterator;

    container::iteratore db_begin();
    container::iteratore db_end();


};



#endif // DATABASE_H
