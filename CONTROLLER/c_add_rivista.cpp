#include "c_add_rivista.h"
#include<QApplication>
c_add_rivista::c_add_rivista(DataBase* db,inserisci_Rivista* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    connect(view,SIGNAL(submitR(info)),this,SLOT(add(info)));
}


void c_add_rivista::add(info op){
    model->add_Rivista(op);
}

