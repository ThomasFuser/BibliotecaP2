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

    DataBase db;
    /*mainWindow* finestra=new mainWindow(&db);
    C_mainWindow* controller=new C_mainWindow(&db,finestra); */
    mainWindow finestra(&db);
    C_mainWindow controller(&db,&finestra);

    finestra.show();


    return a.exec();
}




























