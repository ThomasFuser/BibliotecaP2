#include "c_listaop.h"

C_listaop::C_listaop(DataBase* db, listaOp* v,QObject *parent) : model(db), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info(int)));
    model->Trova_Precisa(3);
    std::cout<<"COSTRUTTORE DOPO TROVA PRECISA"<<std::endl;
}


void C_listaop::visualizza_info(int id) const{



    model->Trova_Precisa(3);

    std::cout<<"SLOT DOPO TROVA PRECISA"<<std::endl;


    if(dynamic_cast<Rivista*>(model->Trova_Precisa(id)))
    {
        Dettagli_Rivista* dett=new Dettagli_Rivista(id,model);
        dett->show();
    }
    else if(dynamic_cast<Libro*>(model->Trova_Precisa(id)))
    {
        Dettagli_Libro* dett=new Dettagli_Libro(id,model);
        dett->show();
    }

}
