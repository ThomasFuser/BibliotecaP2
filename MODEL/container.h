// contenitore base che gestisce la memoria con gli smartp

#ifndef CONTAINER_H
#define CONTAINER_H

#include<iostream>
#include<QString>

#include "Opera.h"




class container{
    friend class iteratore;
private:
    class nodo;

    class smartp{
    public:
            smartp(nodo* =0);							//costruttore 0~1 parametro + convertitore implicito nodo*->smartp
            ~smartp();									//distruttore
            smartp(const smartp&);						//costruttore di copia

            smartp& operator=(const smartp&);			//operatore di assegnazione
            bool operator==(const smartp&)const;		//operatore di uguaglianza
            bool operator!=(const smartp&)const;		//operatore di disuguaglianza
            nodo* operator->()const;					//operatore di accesso a membro
            nodo& operator*()const;

            nodo* punt;
        };

    class nodo{
    public:
        nodo(Opera*, const smartp& =0); //costruttore 0~2 arg

        Opera* op;
        smartp next;
        int riferimenti;
    };
    //campo dati
    smartp first;

public:
    class iteratore{
        friend class container;
    private:
        container::smartp punt;
    public:
        bool operator==(const iteratore&) const;       //operatore di uguaglianza
        bool operator!=(const iteratore&) const;       //operatore di disuguaglianza
        iteratore& operator++();                       //operatore di incremento prefisso
        iteratore& operator++(int);                    //operatore di incremento postfisso
        Opera* operator->()const;                           //operatore di accesso a membro
        //metodi per test
                Opera* getIt() const{ return punt->op; }
    };

    container();                                         //costruttore contenitore vuoto
        //triade gestione memoria profonda
    container& operator=(const container&);              //assegnazione con smartp
    //~container();                                      //distruttore profondo del contenitore
    container(const container&);                         //costruzione di copia

            //metodi pubblici container
    bool empty() const;                                  // 1 <=> contenitore vuoto
    void add_item(Opera*);                               //aggiunta opera in coda alla lista
    //PRE=( Vc=vecchio contenitore, Nc=nuovo contenitore. L'item da eliminare è presente in  Vc. "o" è puntatore all'item)
    void remove_item(Opera*);                            //rimuovi una opera dalla lista
    //POST=(Nc=Vc-o)


    //metodi legati all'iteratore
    iteratore begin() const;
    iteratore end() const;
    Opera* operator[](const iteratore&) const;

};



#endif // CONTAINER_H







