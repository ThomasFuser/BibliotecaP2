#include "c_add_rivista.h"
#include<QApplication>
c_add_rivista::c_add_rivista(DataBase* db,inserisci_Rivista* v ,mainWindow* mv, QObject *parent):model(db),
                                                                                                 view(v),
                                                                                                 mainW(mv),
                                                                                                 QObject(parent)
{
    connect(view,SIGNAL(submitR(const info&)),this,SLOT(add(const info&)));
    connect(view,SIGNAL(chiudi_aggiungi_rivista()),this,SLOT(chiudi_add_rivista()));
}


void c_add_rivista::add(const info& op){
    model->add_Rivista(op);
    mainW->aggiorna_vista();
}

void c_add_rivista::chiudi_add_rivista(){ delete view; }


