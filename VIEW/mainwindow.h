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
    void updateMainWindow();
    ~mainWindow();
signals:
    void rimuovi(int);
public slots:
    void rimuovi_segnale();

private slots:
    void modifica_campo(int);     //slot che consente di rimuovere l'opera selezionataù

private:
    DataBase* model;

    listaOp* tab;
    C_listaop* controllerOP;

    int opera_selezionata;

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
