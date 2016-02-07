#include "c_add_libro.h"

c_add_libro::c_add_libro(DataBase* db,inserisci_Libro* v , QObject *parent):model(db), view(v) ,QObject(parent)
{
    connect(view,SIGNAL(submitL(QString, QString)),this,SLOT(add(QString, QString)));
    std::cout<<"CONTROLLER add"<<std::endl;
}


void c_add_libro::add(QString tit, QString anno){

    info op(tit,"","",anno);
    model->add_Libro(op);
}
