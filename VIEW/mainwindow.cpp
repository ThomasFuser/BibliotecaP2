#include "mainwindow.h"

mainWindow::mainWindow(DataBase* db, QWidget *parent) : model(db),  QWidget(parent) {

  //tabella con l'elenco delle opere
    tab=new listaOp(model);
    controllerOP=new C_listaop(model,tab);

  //bottoni
    presta_rientra=new QPushButton("PRESTA / RIENTRA");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");

  //barra della ricerca
    barra_cerca=new QLineEdit();

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    creaLayout();


}




void mainWindow::creaLayout(){

    bottoni->addWidget(presta_rientra);
    bottoni->addWidget(aggiungi_libro);
    bottoni->addWidget(aggiungi_rivista);
    bottoni->addWidget(rimuovi_opera);

    orizzontale->addWidget(tab);
    orizzontale->addLayout(bottoni);

    Prlayout->addWidget(barra_cerca);
    Prlayout->addLayout(orizzontale);
    setLayout(Prlayout);
}


mainWindow::~mainWindow(){
    delete tab;             delete presta_rientra;
    delete controllerOP;    delete aggiungi_libro;
    delete barra_cerca;     delete aggiungi_rivista;
    delete rimuovi_opera;   delete orizzontale;
    delete bottoni;         delete Prlayout;
}



