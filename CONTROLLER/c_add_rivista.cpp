#include "c_add_rivista.h"
#include<QApplication>
c_add_rivista::c_add_rivista(DataBase* db,inserisci_Rivista* v ,mainWindow* mv, QObject *parent):model(db),
                                                                                                 view(v),
                                                                                                 mainW(mv),
                                                                                                 QObject(parent)
{
    connect(view,SIGNAL(submitR(info)),this,SLOT(add(info)));
}


void c_add_rivista::add(info op){
    model->add_Rivista(op);
    mainW->aggiorna_vista();
}

