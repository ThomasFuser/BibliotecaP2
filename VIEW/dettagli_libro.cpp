#include "dettagli_libro.h"
#include <QPalette>
Dettagli_Libro::Dettagli_Libro(int Id, DataBase* db, QWidget *parent) : id(Id), model(db), QWidget(parent)
{
    setWindowTitle("Dettagli del libro");
    //bottone che permettte di chiudere la finestra
       quit=new QPushButton("Chiudi");
       quit->setFont(QFont("Times",18,QFont::Bold));

    //set lable
       t=new QLabel("TITOLO:");
       s=new QLabel("STATO:");
       i=new QLabel("ID:");
       a=new QLabel("AURORE");

    //set QLineEdit
       titolo=new QLineEdit();
       stato=new QLineEdit();
       identificativo=new QLineEdit();
       autore=new QLineEdit();


    //inserimento dei dati e settaggio dello stile
       update_dettagli();
       set_style();
       disabilita_modifica();

    //creo i layout manager
       QGridLayout* grid=new QGridLayout;
       QVBoxLayout* Vlayout=new QVBoxLayout;        //layout manager

    //setto i laypput manager
       grid->addWidget(t,0,0);
       grid->addWidget(titolo,0,1);
       grid->addWidget(a,1,0);
       grid->addWidget(autore,1,1);
       grid->addWidget(i,3,0);
       grid->addWidget(identificativo,3,1);
       grid->addWidget(s,2,0);
       grid->addWidget(stato,2,1);
       Vlayout->addLayout(grid);
       Vlayout->addWidget(quit);
       setLayout(Vlayout);

    //connect
       //bottone quit che chiude la finestra
       connect(quit, SIGNAL(clicked()),qApp,SLOT(quit()));
}


void Dettagli_Libro::update_dettagli(){

    info iLibro=model->get_infoOpera(id);

    titolo->setText(iLibro.get_titolo());
    stato->setText(iLibro.get_stato());
    identificativo->setText(iLibro.get_ID());
    autore->setText(iLibro.get_dettaglio());
}

void Dettagli_Libro::set_style(){

    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    titolo->setPalette(*paletteLine);
    stato->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    autore->setPalette(*paletteLine);
}


void Dettagli_Libro::abilita_modifica(){
    titolo->setEnabled(true);
    identificativo->setEnabled(true);
    autore->setEnabled(true);
}

void Dettagli_Libro::disabilita_modifica(){
      titolo->setEnabled(false);
      stato->setEnabled(false);
      identificativo->setEnabled(false);
      autore->setEnabled(false);
}
