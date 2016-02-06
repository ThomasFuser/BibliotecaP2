#include "c_add_rivista.h"

c_add_rivista::c_add_rivista(DataBase* db,inserisci_Rivista* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    std::cout<<"CONTROLLER add"<<std::endl;
     connect(view,SIGNAL(submitR(info)),this,SLOT(add(info)));
}


void c_add_rivista::add(info op){
    std::cout<<"SLOT CONTROLLER OP"<<std::endl;
    model->add_Rivista(op);
}
