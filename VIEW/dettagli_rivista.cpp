#include "dettagli_rivista.h"
#include <QPalette>
Dettagli_Rivista::Dettagli_Rivista(int Id, DataBase* db) : Dettagli_opera(Id,db)
{

    setWindowTitle("Dettagli della rivista");

    a=new QLabel("ANNO:");

    anno=new QLineEdit();

    get_grid()->addWidget(a,1,0);
    get_grid()->addWidget(anno,1,1);

    setLayout(get_grid());
    centra_finestra();
    disabilita_modifica();
    costruisci_contenuto();
    set_style();

}

void Dettagli_Rivista::costruisci_contenuto(){
     Dettagli_opera::costruisci_contenuto();
     info iLibro=(get_model())->get_infoOpera(get_ID());
     anno->setText(iLibro.get_dettaglio());
}

void Dettagli_Rivista::set_style(){
    Dettagli_opera::set_style();
    anno->setPalette(*get_paletteLine());
}


void Dettagli_Rivista::disabilita_modifica(){
      Dettagli_opera::disabilita_modifica();
      anno->setEnabled(false);
}

Dettagli_Rivista::~Dettagli_Rivista(){
    delete a;
    delete anno;
}
