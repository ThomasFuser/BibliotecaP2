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
    void aggiorna_vista();          //metodo che popola la tabella
    void costruisci_contenuto();
    void build_Nuova(const container&);
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

    QTableWidget* table;
    QVBoxLayout* layout_table;
    int select_opera;
    void set_style();
    void registrazione_elenco() const;
    void elimina_registrazione() const;


};

#endif // LISTAOP_H

