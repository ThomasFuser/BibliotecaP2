#include <QApplication>


#include "MODEL/database.h"
#include <CONTROLLER/c_mainwindow.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); 
    DataBase db; 
    mainWindow finestra(&db);
    C_mainWindow controller(&db,&finestra);

    finestra.show();

    return a.exec();
}




























