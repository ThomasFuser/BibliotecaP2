#include "c_listaop.h"

C_listaop::C_listaop(DataBase* db, listaOp* v,QObject *parent) : model(db), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info(int)));


}


void C_listaop::visualizza_info(int id){

    view->disabilita_doppio_click();

    if(dynamic_cast<Rivista*>(model->Trova_Precisa(id)))
    {
        dett_rivista=new Dettagli_Rivista(id,model);
        connect(dett_rivista,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_rivista()));
        dett_rivista->show();
    }
    else if(dynamic_cast<Libro*>(model->Trova_Precisa(id)))
    {
        dett_libro=new Dettagli_Libro(id,model);
        connect(dett_libro,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_libro()));
        dett_libro->show();
    }
}

void C_listaop::chiudi_dettagli_libro(){
    view->abilita_doppio_click();
    delete dett_libro;
}

void C_listaop::chiudi_dettagli_rivista(){
    view->abilita_doppio_click();
    delete dett_rivista;
}
