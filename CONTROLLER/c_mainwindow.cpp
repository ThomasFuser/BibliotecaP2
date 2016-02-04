#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(DataBase* db,mainWindow* v, QObject *parent) :model(db),view(v),  QObject(parent) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
}



void C_mainWindow::rimuovi_operaDB(int ID){
    std::cout<<"remove ID: "<<ID<<std::endl;

    model->remove_opera(ID);
    view->updateMainWindow();
}
