#include "dettagli_libro.h"
#include <QPalette>
Dettagli_Libro::Dettagli_Libro(int Id, DataBase* db, QWidget *parent) : id(Id), model(db), QWidget(parent)
{
    setWindowTitle("Dettagli del libro");

    //set lable
       t=new QLabel("TITOLO:");
       p=new QLabel("PRESTITO:");
       i=new QLabel("ID:");
       a=new QLabel("AURORE:");
       c=new QLabel("IN SEDE:");

    //set QLineEdit
       titolo=new QLineEdit();
       prestito=new QLineEdit();
       identificativo=new QLineEdit();
       autore=new QLineEdit();
       consultabile=new QLineEdit();


    //inserimento dei dati e settaggio dello stile
       update_dettagli();
       set_style();
       disabilita_modifica();

    //creo i layout manager
       QGridLayout* grid=new QGridLayout;


    //setto i laypput manager
       grid->addWidget(t,0,0);
       grid->addWidget(titolo,0,1);
       grid->addWidget(a,1,0);
       grid->addWidget(autore,1,1);
       grid->addWidget(i,2,0);
       grid->addWidget(identificativo,2,1);
       grid->addWidget(p,3,0);
       grid->addWidget(prestito,3,1);
       grid->addWidget(c,4,0);
       grid->addWidget(consultabile,4,1);

       setLayout(grid);

}


void Dettagli_Libro::update_dettagli(){

    info iLibro=model->get_infoOpera(id);

    titolo->setText(iLibro.get_titolo());
    prestito->setText(iLibro.get_stato());
    identificativo->setText(iLibro.get_ID());
    autore->setText(iLibro.get_dettaglio());
    consultabile->setText(iLibro.is_consultabile());

}

void Dettagli_Libro::set_style(){

    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    titolo->setPalette(*paletteLine);
    prestito->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    autore->setPalette(*paletteLine);
    consultabile->setPalette(*paletteLine);
}


void Dettagli_Libro::abilita_modifica(){
    titolo->setEnabled(true);
    identificativo->setEnabled(true);
    autore->setEnabled(true);
}

void Dettagli_Libro::disabilita_modifica(){
      titolo->setEnabled(false);
      prestito->setEnabled(false);
      identificativo->setEnabled(false);
      autore->setEnabled(false);
      consultabile->setEnabled(false);
}

Dettagli_Libro::~Dettagli_Libro(){
    delete t;
    delete p;
    delete i;
    delete a;
    delete c;
    delete titolo;
    delete autore;
    delete identificativo;
    delete consultabile;
    delete paletteLine;
    delete prestito;
}

