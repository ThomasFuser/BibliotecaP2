#include "c_add_libro.h"

c_add_libro::c_add_libro(DataBase* db,inserisci_Libro* v ,mainWindow* mv, QObject *parent):model(db),
                                                                                           view(v),
                                                                                           mainW(mv),
                                                                                           QObject(parent)
{
    connect(view,SIGNAL(submitL(info)),this,SLOT(add(info)));
    connect(view,SIGNAL(chiudi_aggiungi_Libro()),this,SLOT(chiudi_add_libro()));
}


void c_add_libro::add(info op){
    model->add_Libro(op);
    mainW->aggiorna_vista();
}

void c_add_libro::chiudi_add_libro(){ delete view; }
