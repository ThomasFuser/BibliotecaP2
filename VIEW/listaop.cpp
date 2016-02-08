#include"listaop.h"

listaOp::listaOp(DataBase* db): Widget_Padre(db){

    table=new QTableWidget();

  //inserisco la tabella nel layout del widget
    layout_table=new QVBoxLayout();
    layout_table->addWidget(table);
    set_style();
    setLayout(layout_table);

    costruisci_contenuto();

  //segnali
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click(int)));     //doppio click
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(click_singolo(int)));          //click singolo
}

void listaOp::costruisci_contenuto(){ aggiorna_vista(); }

void listaOp::aggiorna_vista(){

    int row=0;
        DataBase* ciao=get_model();
        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             container::iteratore it;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {
                table->setRowCount(row+1);
                id=(*it)->Get_Id();
                i.setNum(id);

                QTableWidgetItem *ID = new QTableWidgetItem(i);
                QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
                QTableWidgetItem *tipo = new QTableWidgetItem((*it)->get_Tipo());

                table->setItem(row,0,ID);
                table->setItem(row,1,valore);
                table->setItem(row,2,tipo);
                row++;
             }
        }
        else{
                table->setRowCount(row);
                emit tabella_vuota();
            }
}

void listaOp::set_style(){

  //set numero righe e colonne della tabella
    table->setColumnCount(3);
    table->setRowCount(0);

  //set dimensioni tabella
    table->setMinimumWidth(600);
    table->setColumnWidth(0,50);
    table->setColumnWidth(1,431);
    table->setColumnWidth(2,100);
    table->setMaximumWidth(600);
    table->setMinimumHeight(300);
    table->setMaximumHeight(300);

    //intestazione tabella
    QStringList tabHeader;
    tabHeader<<"ID"<<"Titolo"<<"Tipologia";
    table->setHorizontalHeaderLabels(tabHeader);
    //comportamento nel momento in cui si seleziona un item
    table->setSelectionMode(QAbstractItemView::SingleSelection);    // modifica disabilitata
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void listaOp::build_Nuova(const container& lista){
    int row=0;
    if(!(lista.empty()))
    {
         int id;
         QString i;
         container::iteratore it;

         for(it=lista.begin(); it!=lista.end(); it++)
         {
            table->setRowCount(row+1);
            id=(*it)->Get_Id();
            i.setNum(id);

            QTableWidgetItem *ID = new QTableWidgetItem(i);
            QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
            QTableWidgetItem *tipo = new QTableWidgetItem((*it)->get_Tipo());

            table->setItem(row,0,ID);
            table->setItem(row,1,valore);
            table->setItem(row,2,tipo);
            row++;
         }
    }
    else{
            table->setRowCount(row);
            emit tabella_vuota();
        }
}

void listaOp::registrazione_elenco() const{
    get_model()->add_registro(const_cast<listaOp*>(this));
}

void listaOp::elimina_registrazione() const{
    get_model()->remove_registro(const_cast<listaOp*>(this));
}



                    ////////////////////////////slot/////////////////////////////

void listaOp::doppio_click(int r){
    select_opera=table->item(r,0)->text().toInt();
    emit richiesta_info(select_opera);
}

void listaOp::click_singolo(int r){
    select_opera=table->item(r,0)->text().toInt();
    emit selezione(select_opera);
}

listaOp::~listaOp(){
    delete table;
    delete layout_table;
}










