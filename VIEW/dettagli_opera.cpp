#include "dettagli_opera.h"

Dettagli_opera::Dettagli_opera(int ID, DataBase* db) : id(ID) , Widget_Padre(db)
{
    //set lable
       t=new QLabel("TITOLO:");
       p=new QLabel("PRESTITO:");
       i=new QLabel("ID:");
       c=new QLabel("IN SEDE:");

    //set QLineEdit
       titolo=new QLineEdit();
       prestito=new QLineEdit();
       identificativo=new QLineEdit();
       consultabile=new QLineEdit();

       //creo i layout manager
        grid=new QGridLayout;

       //setto i laypput manager
        grid->addWidget(t,0,0);
        grid->addWidget(titolo,0,1);
        grid->addWidget(i,2,0);
        grid->addWidget(identificativo,2,1);
        grid->addWidget(p,3,0);
        grid->addWidget(prestito,3,1);
        grid->addWidget(c,4,0);
        grid->addWidget(consultabile,4,1);
}

void Dettagli_opera::set_style(){
    resize(300,250);
    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    titolo->setPalette(*paletteLine);
    prestito->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    consultabile->setPalette(*paletteLine);
}

void Dettagli_opera::costruisci_contenuto(){
    info info_Op=(get_model())->get_infoOpera(id);

    titolo->setText(info_Op.get_titolo());
    prestito->setText(info_Op.get_stato());
    identificativo->setText(info_Op.get_ID());
    consultabile->setText(info_Op.is_consultabile());
}

void Dettagli_opera::disabilita_modifica(){
      titolo->setEnabled(false);
      prestito->setEnabled(false);
      identificativo->setEnabled(false);
      consultabile->setEnabled(false);
}

int Dettagli_opera::get_ID()const{ return id; }

QPalette* Dettagli_opera::get_paletteLine()const{ return paletteLine; }

QGridLayout* Dettagli_opera::get_grid()const{ return grid; }

void Dettagli_opera::aggiorna_vista(){
    info info_Op=(get_model())->get_infoOpera(id);
    prestito->setText(info_Op.get_stato());
    consultabile->setText(info_Op.is_consultabile());
}
