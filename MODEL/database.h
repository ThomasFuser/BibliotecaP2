#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include"container.h"
#include"Opera.h"
#include"Rivista.h"
#include"Libro.h"
#include"info.h"
#include"../VIEW/widget_padre.h"



class DataBase{
private:
    //campi dati
    static QString filename;
    container db;
    std::vector<Widget_Padre*> registro;                //registro delle view "dettagli" collegate al modello per aggionramento nel caso in cui "presta/ricevi" venga con la view dettagli aperta
    void Load();                                        //crea il contenitore leggendo il file xml
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
    DataBase();
    ~DataBase();

    bool vuoto() const;                                 //ritorna true <=> container è vuoto altrimenti ritorna false
    void remove_opera(const int);                       //elimina una opera
    container cerca_opera(const QString&) const;        //cerca una opera cercando in tutti i campi di essa (ricerca polimorfa). la ricerca è caseInsensitive
    void add_Rivista(info);                             //aggiunge una rivista
    void add_Libro(info);                               //aggiunge una libro
    info get_infoOpera(int) const;                      //ritorna un oggetto "info" contenente tutte le informazioni riguardanti un' opera con un preciso ID. se l'opera non è oresente la funzione ritorna un oggetto info con tutti i suoi campi contenenti "sconosciuto" mentre nel campo corrispondente ad ID: ID non valido
    Opera* Trova_Precisa(int) const;                    //ricerca una precisa opera identificata dal suo puntatore
    void Presta_ricevi(int);

    void aggiorna_view() const;                         //permette di aggiornare le view registrate al dataBase
    void add_registro(Widget_Padre*);                   //registrazione al DataBase
    void remove_registro(Widget_Padre*);                //permette di eliminare la registrazione al DataBase

    container::iteratore db_iterator;

    container::iteratore db_begin();
    container::iteratore db_end();

};



#endif // DATABASE_H
