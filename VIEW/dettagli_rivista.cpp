#include "dettagli_rivista.h"
#include <QPalette>
Dettagli_Rivista::Dettagli_Rivista(int Id, DataBase* db, QWidget *parent) : id(Id), model(db), QWidget(parent)
{
    setWindowTitle("Dettagli della rivista");


    //set lable
       t=new QLabel("TITOLO:");
       p=new QLabel("PRESTITO:");
       i=new QLabel("ID:");
       a=new QLabel("ANNO DI USCITA");
       c=new QLabel("IN SEDE:");

    //set QLineEdit
       titolo=new QLineEdit();
       prestito=new QLineEdit();
       identificativo=new QLineEdit();
       anno=new QLineEdit();
       consultabile=new QLineEdit();

    //inserimento dei dati e settaggio dello stile
       update_dettagli();
       set_style();

    //creo il layout manager
       QGridLayout* grid=new QGridLayout;

    //setto i laypput manager
       grid->addWidget(t,0,0);
       grid->addWidget(titolo,0,1);    
       grid->addWidget(a,1,0);
       grid->addWidget(anno,1,1);
       grid->addWidget(i,2,0);
       grid->addWidget(identificativo,2,1);
       grid->addWidget(p,3,0);
       grid->addWidget(prestito,3,1);
       grid->addWidget(c,4,0);
       grid->addWidget(consultabile,4,1);

       setLayout(grid);


       disabilita_modifica();


}


void Dettagli_Rivista::update_dettagli(){
    info iRivista=model->get_infoOpera(id);

    titolo->setText(iRivista.get_titolo());
    prestito->setText(iRivista.get_stato());
    identificativo->setText(iRivista.get_ID());
    anno->setText(iRivista.get_dettaglio());
    consultabile->setText(iRivista.is_consultabile());
}

void Dettagli_Rivista::set_style(){
    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    titolo->setPalette(*paletteLine);
    prestito->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    anno->setPalette(*paletteLine);
    consultabile->setPalette(*paletteLine);
}

void Dettagli_Rivista::abilita_modifica(){
    titolo->setEnabled(true);
    identificativo->setEnabled(true);
    anno->setEnabled(true);
    consultabile->setEnabled(true);
}

void Dettagli_Rivista::disabilita_modifica(){
      titolo->setEnabled(false);
      prestito->setEnabled(false);
      identificativo->setEnabled(false);
      anno->setEnabled(false);
      consultabile->setEnabled(false);
}


Dettagli_Rivista::~Dettagli_Rivista(){
    delete t;
    delete p;
    delete i;
    delete a;
    delete c;
    delete titolo;
    delete anno;
    delete identificativo;
    delete prestito;
    delete consultabile;
    delete paletteLine;
    //delete model;
}


























