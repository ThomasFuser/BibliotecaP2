#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "listaop.h"
#include "widget_padre.h"

#include "../CONTROLLER/c_listaop.h"
#include "../MODEL/database.h"



class mainWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit mainWindow(DataBase*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void costruisci_Tabella(const container&);
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~mainWindow();
signals:
    void chiudi_app();
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
    void modifica_campo(int);
    void disabilita();
    void testo_editato(const QString&);
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

    void creaLayout();
    void abilita_bottoni();
    void disabilita_bottoni();
};

#endif // MAINWINDOW_H
