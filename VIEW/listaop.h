#ifndef LISTAOP_H
#define LISTAOP_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QVBoxLayout>

#include "widget_padre.h"
#include"../MODEL/database.h"
#include"../MODEL/container.h"

class listaOp : public Widget_Padre
{
    Q_OBJECT
public:
    explicit listaOp(DataBase*);
    void aggiorna_vista();
    void costruisci_contenuto();
    void build_Nuova(const container&);         //costruisce la tabella partendo da un contenitore passato ad essa
    void abilita_doppio_click();
    void disabilita_doppio_click();
    ~listaOp();
signals:
   void richiesta_info(const int);
   void selezione(const int);
   void tabella_vuota();
   void disabilita_funzioni();
   void abilita_funzioni();

private slots:
   void doppio_click(int);        //permette di emettere il segnale richiesta_info l'id selezionato
   void click_singolo(int);       //permette di far emettere il segnale selezione con l'id selezionato

private:

    QTableWidget* table;
    QVBoxLayout* layout_table;
    int select_opera;
    void set_style();
};

#endif // LISTAOP_H

