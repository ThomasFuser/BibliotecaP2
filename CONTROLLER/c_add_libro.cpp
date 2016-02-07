#include "c_add_libro.h"


#include<QApplication>
c_add_libro::c_add_libro(DataBase* db,inserisci_Libro* v , QObject *parent):model(db), view(v) ,QObject(parent)
{


    connect(view,SIGNAL(submitL(QString, QString)),this,SLOT(add(QString, QString)));
    connect(view,SIGNAL(prova()),this,SLOT(stronzo()));
    std::cout<<"CONTROLLER add"<<std::endl;
}


void c_add_libro::add(QString tit, QString anno){

    info op(tit,"","",anno);
    model->add_Libro(op);
}

void c_add_libro::stronzo(){
    std::cout<<"stronzo"<<std::endl;
}
