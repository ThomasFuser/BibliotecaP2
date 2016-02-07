#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>

#include "listaop.h"
#include "../CONTROLLER/c_listaop.h"
#include "../MODEL/database.h"
#include "../CONTROLLER/c_add_rivista.h"
#include "../VIEW/inserisci_rivista.h"
#include "../VIEW/inserisci_rivista.h"

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainWindow(DataBase*, QWidget *parent = 0);
    void aggiorna_Tabella();
    void costruisci_Tabella(const container&);
    ~mainWindow();
signals:
    void rimuovi(int);
    void aggiorna_prestito(int);
    void show_inserisci_rivista();
    void show_inserisci_libro();
    void cerca_opera(QString);

private slots:
    void rimuovi_segnale();
    void slot_aggiorna_prestito();
    void slot_inserisci_rivista();
    void slot_inserisci_libro();

    void modifica_campo(int);     //slot che consente di rimuovere l'opera selezionata
    void disabilita();
    void testo_editato(QString);
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
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

   // inserisci_Rivista* ins_riv;

    void creaLayout();
    void abilita_bottoni();
    void disabilita_bottoni();
    void centra_finestra();

};

#endif // MAINWINDOW_H
