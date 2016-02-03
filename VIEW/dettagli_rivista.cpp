#include "dettagli_rivista.h"
#include <QPalette>
Dettagli_Rivista::Dettagli_Rivista(int Id, DataBase* db, QWidget *parent) : id(Id), model(db), QWidget(parent)
{
    setWindowTitle("Dettagli della rivista");
    //bottone che permettte di chiudere la finestra
       quit=new QPushButton("Chiudi");
       quit->setFont(QFont("Times",18,QFont::Bold));

    //set lable
       t=new QLabel("TITOLO:");
       s=new QLabel("STATO:");
       i=new QLabel("ID:");
       a=new QLabel("ANNO DI USCITA");

    //set QLineEdit
       titolo=new QLineEdit();
       stato=new QLineEdit();
       identificativo=new QLineEdit();
       anno=new QLineEdit();


    //inserimento dei dati e settaggio dello stile
       build_dettagli();
       set_style();

    //creo i layout manager
       QGridLayout* grid=new QGridLayout;
       QVBoxLayout* Vlayout=new QVBoxLayout;        //layout manager

    //setto i laypput manager


       grid->addWidget(t,0,0);
       grid->addWidget(titolo,0,1);
       grid->addWidget(i,1,0);
       grid->addWidget(identificativo,1,1);
       grid->addWidget(s,2,0);
       grid->addWidget(stato,2,1);
       grid->addWidget(a,3,0);
       grid->addWidget(anno,3,1);
       Vlayout->addLayout(grid);
       Vlayout->addWidget(quit);
       setLayout(Vlayout);



    //connect
       //bottone quit che chiude la finestra
       connect(quit, SIGNAL(clicked()),qApp,SLOT(quit()));
}


void Dettagli_Rivista::build_dettagli(){





    info iRivista=model->get_infoOpera(id);

    titolo->setText(iRivista.get_titolo());
    stato->setText(iRivista.get_stato());
    identificativo->setText(iRivista.get_ID());
    anno->setText(iRivista.get_dettaglio());

  //disabilito la modifica dei QLineEdit
    titolo->setEnabled(false);
    stato->setEnabled(false);
    identificativo->setEnabled(false);
    anno->setEnabled(false);



}

void Dettagli_Rivista::set_style(){

    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");




    titolo->setPalette(*paletteLine);
    stato->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    anno->setPalette(*paletteLine);
}
