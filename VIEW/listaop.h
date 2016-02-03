#ifndef LISTAOP_H
#define LISTAOP_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QVBoxLayout>
                                        //manca campo dati per identificare utente selezionatto

#include"../MODEL/database.h"
#include"../MODEL/container.h"

class listaOp : public QWidget
{
    Q_OBJECT
public:
    explicit listaOp(DataBase*, QWidget *parent = 0);

signals:
   void richiesta_info(const int);
private slots:
   void doppio_click(int);        //permette di far comparire la view adatta alla opera che si vuole aprire

private:
  //campi dati
    DataBase* model;
    QTableWidget* table;
    QVBoxLayout* layout_table;
    int select_opera;
  //metodi privati
    void buildTable();          //metodo che popola la tabella


};

#endif // LISTAOP_H

