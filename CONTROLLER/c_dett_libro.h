/*#ifndef C_DETT_LIBRO_H
#define C_DETT_LIBRO_H

#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/dettagli_libro.h"
#include "../CONTROLLER/c_mainwindow.h"
#include "../MODEL/database.h"
class c_dett_libro : public QObject
{
    Q_OBJECT
public:
    explicit c_dett_libro(int, DataBase*, C_mainWindow* , QObject* =0);

signals:

private slots:
    void aggiorna_dettagliView();
private:
    Dettagli_Libro* view;
    C_mainWindow* controller_main;
    DataBase* model;
    int ID;
};

#endif // C_DETT_LIBRO_H
*/
