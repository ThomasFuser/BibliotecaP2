#include "dettagli_libro.h"
#include <QPalette>
Dettagli_Libro::Dettagli_Libro(int Id, DataBase* db) : Dettagli_opera(Id,db)
{

    setWindowTitle("Dettagli del libro");

    a=new QLabel("AURORE:");

    autore=new QLineEdit();

    get_grid()->addWidget(a,1,0);
    get_grid()->addWidget(autore,1,1);

    setLayout(get_grid());
    centra_finestra();
    disabilita_modifica();
    set_style();
    costruisci_contenuto();
}

void Dettagli_Libro::costruisci_contenuto(){
     Dettagli_opera::costruisci_contenuto();
     info iLibro=(get_model())->get_infoOpera(get_ID());
     autore->setText(iLibro.get_dettaglio());
}

void Dettagli_Libro::set_style(){
    Dettagli_opera::set_style();
    autore->setPalette(*get_paletteLine());
}


void Dettagli_Libro::disabilita_modifica(){
      Dettagli_opera::disabilita_modifica();
      autore->setEnabled(false);     
}

Dettagli_Libro::~Dettagli_Libro(){
    std::cout<<"distruttore di libro"<<std::endl;
    delete a;     //autore
    delete autore;
}
