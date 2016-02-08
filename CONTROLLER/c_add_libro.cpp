#include "c_add_libro.h"

c_add_libro::c_add_libro(DataBase* db,inserisci_Libro* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    connect(view,SIGNAL(submitL(info)),this,SLOT(add(info)));
    std::cout<<"CONTROLLER add libro"<<std::endl;
}


void c_add_libro::add(info op){
    model->add_Libro(op);
    //aggiornamento della tabella
}
