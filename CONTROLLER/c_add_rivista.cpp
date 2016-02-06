#include "c_add_rivista.h"
#include<QApplication>
c_add_rivista::c_add_rivista(DataBase* db,inserisci_Rivista* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    std::cout<<"CONTROLLER add"<<std::endl;

    //connect(view,SIGNAL(submitR(info)),this,SLOT(prova(info)));
    connect(view,SIGNAL(submitR(QString, QString)),this,SLOT(add(QString, QString)));
}


void c_add_rivista::add(QString tit, QString anno){
    info op(tit,"","",anno);
    model->add_Rivista(op);
}
