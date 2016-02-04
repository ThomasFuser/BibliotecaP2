#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "listaop.h"
#include "../CONTROLLER/c_listaop.h"
#include "../MODEL/database.h"

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainWindow(DataBase*, QWidget *parent = 0);
    ~mainWindow();
signals:

public slots:

private:
    DataBase* model;

    listaOp* tab;
    C_listaop* controllerOP;

    QLineEdit* barra_cerca;

    QPushButton* presta_rientra;
    QPushButton* aggiungi_rivista;
    QPushButton* aggiungi_libro;
    QPushButton* rimuovi_opera;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    void creaLayout();



};

#endif // MAINWINDOW_H
