#ifndef LISTAOP_H
#define LISTAOP_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QVBoxLayout>


#include"../MODEL/database.h"
#include"../MODEL/container.h"

class listaOp : public QWidget
{
    Q_OBJECT
public:
    explicit listaOp(DataBase*, QWidget *parent = 0);
    void updateTable();          //metodo che popola la tabella
    ~listaOp();
signals:
   void richiesta_info(const int);
   void selezione(const int);
   void tabella_vuota();
private slots:
   void doppio_click(int);        //permette di emettere il segnale richiesta_info l'id selezionato
   void click_singolo(int);       //permette di far emettere il segnale selezione con l'id selezionato

private:
  //campi dati
    DataBase* model;
    QTableWidget* table;
    QVBoxLayout* layout_table;

    int select_opera;
  //metodi privati
    void set_stile_tabella();

};

#endif // LISTAOP_H

