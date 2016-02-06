#include "c_add_libro.h"


#include<QApplication>
c_add_libro::c_add_libro(DataBase* db,inserisci_Libro* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    std::cout<<"CONTROLLER add"<<std::endl;

    connect(view,SIGNAL(submitL(QString, QString)),this,SLOT(add(QString, QString)));
}


void c_add_libro::add(QString tit, QString anno){
    std::cout<<"ZIO PORCO"<<std::endl;
    info op(tit,"","",anno);
    model->add_Libro(op);
}
