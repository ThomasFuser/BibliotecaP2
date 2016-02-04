#include"listaop.h"

listaOp::listaOp(DataBase* db, QWidget *parent): QWidget(parent), model(db)
{
    table=new QTableWidget(this);
    table->setColumnCount(3);       //per adesso metto una sola colonna
    table->setRowCount(0);          //inizializzo la tabella senza righe

  //set dimensioni tabella
    table->setMinimumWidth(400);
    table->setColumnWidth(0,50);
    table->setColumnWidth(1,220);

  //intestazione tabella
    QStringList tabHeader;
    tabHeader<<"ID"<<"Titolo"<<"Tipologia";
    table->setHorizontalHeaderLabels(tabHeader);

  //inserisco la tabella nel layout del widget
    layout_table=new QVBoxLayout();
    layout_table->addWidget(table);
  //comportamento nel momento in cui si seleziona un item
    table->setSelectionMode(QAbstractItemView::SingleSelection);    // modifica disabilitata
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    buildTable();
    setLayout(layout_table);

  //segnali
   // connect(table,SIGNAL(cellClicked(int, int)),this,SLOT(setSelectedOpera(int)));  //imposta l'id cercato nell'apposito campo
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click(int)));
}

void listaOp::buildTable(){
    if(!(model->vuoto()))
    {
         int row=0,id;
         QString i;
         container::iteratore it;
         for(it=model->db_begin(); it!=model->db_end(); it++)
         {
            table->setRowCount(row+1);
            id=(*it)->Get_Id();
            i.setNum(id);

            QTableWidgetItem *ID = new QTableWidgetItem(i);
            QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
            QTableWidgetItem *tipo = new QTableWidgetItem((*it)->get_Tipo());          // utilizzo la scappatoia solo per stampaare

             table->setItem(row,0,ID);
             table->setItem(row,1,valore);
             table->setItem(row,2,tipo);
            row++;
         }
    }
    else std::cout<<"tabella vuota"<<std::endl;
}


//slot


//selezione di una opera all'interno della tabella -> selezione l'id in modo tale da facilitare la ricerca ed invia un segnale che consentirà al controller di aprire la finestra desiderata
void listaOp::doppio_click(int r){
    select_opera=table->item(r,0)->text().toInt(); std::cout<<"selezione id: "<<select_opera<<std::endl;
    emit richiesta_info(select_opera);
}


listaOp::~listaOp(){
    delete table;
    delete layout_table;
}
















