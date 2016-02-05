/*#include "c_dett_libro.h"

c_dett_libro::c_dett_libro(int i,DataBase* db,C_mainWindow* v,QObject *parent):ID(i),model(db), controller_main(v) ,QObject(parent){


    connect(view,SIGNAL(aggiorna_prestito(int)),this,SLOT(aggiorna_prestitoDB(int)));

    view=new Dettagli_Libro(ID,model);

    //connessione tra la view main e questo controller
    connect(controller_main,SIGNAL(aggiorna_dettagli()),this,SLOT(aggiorna_dettagliView()));

}


void c_dett_libro::aggiorna_dettagliView(){
    view->update_dettagli();
}*/

