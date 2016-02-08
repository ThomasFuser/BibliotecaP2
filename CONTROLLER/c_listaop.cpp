#include "c_listaop.h"

C_listaop::C_listaop(DataBase* db, listaOp* v,QObject *parent) : model(db), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info(int)));
}


void C_listaop::visualizza_info(int id){

    model->Trova_Precisa(3);

    if(dynamic_cast<Rivista*>(model->Trova_Precisa(id)))
    {
        dett_rivista=new Dettagli_Rivista(id,model);
        dett_rivista->show();
    }
    else if(dynamic_cast<Libro*>(model->Trova_Precisa(id)))
    {
        dett_libro=new Dettagli_Libro(id,model);
        dett_libro->show();
    }
}

C_listaop::~C_listaop(){
    delete model;
    delete view;
    delete dett_libro;
    delete dett_rivista;
}
