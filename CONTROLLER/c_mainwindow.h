#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/mainwindow.h"
#include "../CONTROLLER/c_add_rivista.h"
#include "../CONTROLLER/c_add_libro.h"

class C_mainWindow : public QObject
{
    Q_OBJECT
public:
    explicit C_mainWindow(DataBase* , mainWindow* , QObject *parent=0);

private slots:
    void rimuovi_operaDB(int);
    void aggiorna_prestitoDB(int);
    void inserisci_rivistaDB();
    void inserisci_libroDB();
    void cerca_operaDB(QString);

private:
    DataBase* model;
    mainWindow* view;
};

#endif // C_MAINWINDOW_H
