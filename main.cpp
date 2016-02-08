#include <QApplication>
#include <iostream>

#include "MODEL/Opera.h"
#include "MODEL/Rivista.h"
#include "MODEL/Libro.h"

#include "MODEL/database.h"
#include <VIEW/listaop.h>
#include <VIEW/dettagli_rivista.h>
#include <VIEW/dettagli_libro.h>
//#include <VIEW/mainwindow.h>

#include <CONTROLLER/c_listaop.h>
#include <CONTROLLER/c_mainwindow.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   DataBase* db=new DataBase();        //creo un oggetto DataBase che al momento della sua costruzione riempie
                        //un contenitore in RAM con tutte le opere trovate nell'archivio
/*cout<<"ciaooooo"<<endl;
    QString uno("ciao");
    QString due("ciao ciao");
    QString conc=uno+due;
   // cout<<conc.toInt()<<endl;*/
   /* Opera* nuova=new Libro("1Q84","giapponese");
    db->Add_Opera(nuova);*/
    /*db->remove_opera(10);
    db->remove_opera(11);
    db->remove_opera(12);
    db->remove_opera(7);
    db->remove_opera(8);
    db->remove_opera(6);*/


    /*Dettagli_Rivista prov(2,db);
    Dettagli_Libro prov1(3,db);

    prov.show();
    prov1.show();*/
DataBase db;

            std::cout<<"PRIMA DELLA COSTRUZIONE DI QUALCHE OGGETTO"<<std::endl;
    mainWindow* finestra=new mainWindow(&db);
            std::cout<<"DOPO LA COSTRUZIONE DI "<<std::endl;
    C_mainWindow* controller=new C_mainWindow(&db,finestra);
    /*listaOp* view= new listaOp(db);
    C_listaop*  controller=new C_listaop(db, view);*/





    finestra->show();

    return a.exec();
}




























