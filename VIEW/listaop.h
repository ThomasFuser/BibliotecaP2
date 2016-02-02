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

public slots:

private:
  //campi dati
    DataBase* model;
    QTableWidget* table;
    QVBoxLayout* layout_table;
  //metodi privati
    void buildTable();          //metodo che popola la tabella

};

#endif // LISTAOP_H
