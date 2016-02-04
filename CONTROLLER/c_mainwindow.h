#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include <QObject>
#include "../VIEW/mainwindow.h"

class C_mainWindow : public QObject
{
    Q_OBJECT
public:
    explicit C_mainWindow(DataBase* , mainWindow*, QObject *parent=0);

signals:

private slots:
    void rimuovi_operaDB(int);

private:
    DataBase* model;
    mainWindow* view;
};

#endif // C_MAINWINDOW_H
