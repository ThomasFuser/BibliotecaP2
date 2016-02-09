#include "mainwindow.h"
#include<QApplication>
mainWindow::mainWindow(DataBase* db) : Widget_Padre(db) {

  //tabella con l'elenco delle opere
    tab=new listaOp(get_model());

    controllerOP=new C_listaop(get_model(),tab);

  //bottoni
    exit=new QPushButton("ESCI");
    presta_rientra=new QPushButton("PRESTA / RIENTRA");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");
    disabilita_bottoni();
  //barra della ricerca
    barra_cerca=new QLineEdit();

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();


    centra_finestra();
    costruisci_contenuto();

    creaLayout();

    connect(tab,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));

    //connect(tab,SIGNAL(disabilita_funzioni()),this,SLOT(disabilita()));  connect(tab,SIGNAL(disabilita_funzioni()),qApp,SLOT(aboutQt()));

    connect(rimuovi_opera,SIGNAL(clicked()),this,SLOT(rimuovi_segnale()));
    connect(presta_rientra,SIGNAL(clicked()),this,SLOT(slot_aggiorna_prestito()));
    connect(aggiungi_rivista,SIGNAL(clicked()),this,SLOT(slot_inserisci_rivista()));
    connect(aggiungi_libro,SIGNAL(clicked()),this,SLOT(slot_inserisci_libro()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
  // connessione della ricerca
    connect(barra_cerca,SIGNAL(textEdited(QString)),this,SLOT(testo_editato(QString)));

}
void mainWindow::set_style(){
    barra_cerca->setStatusTip("Ricerca per: Titolo, Autore, Anno di pubblicazione, ID");

}

void mainWindow::costruisci_contenuto(){
     aggiorna_vista();
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
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}




void mainWindow::modifica_campo(int ID){
    opera_selezionata=ID;
    abilita_bottoni();

}

void mainWindow::rimuovi_segnale(){
    QString identificativo;
    identificativo.setNum(opera_selezionata);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Rimuovi Opera");
        warning.setText("Hai selezionato l'opera con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente eliminare questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit rimuovi(opera_selezionata);
        }
}


void mainWindow::testo_editato(QString text){ emit cerca_opera(text); }

void mainWindow::slot_inserisci_rivista(){
    emit show_inserisci_rivista();
}

void mainWindow::slot_inserisci_libro(){
    emit show_inserisci_libro();
}


void mainWindow::disabilita(){
    disabilita_bottoni();
}

void mainWindow::slot_aggiorna_prestito(){

    info infoOP=(get_model())->get_infoOpera(opera_selezionata);
    QString identificativo,stato;
    identificativo.setNum(opera_selezionata);

    if(infoOP.is_consultabile()=="si") stato="prestare";
    else stato="ricevere";

    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Aggiornamento del prestito");
        warning.setText("Hai selezionato l'opera con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente "+stato+ " questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes)
        {
            (get_model())->aggiorna_view();
            emit aggiorna_prestito(opera_selezionata);
        }
}


void mainWindow::costruisci_Tabella(const container& lista){ tab->build_Nuova(lista); }

void mainWindow::aggiorna_vista(){ tab->aggiorna_vista(); }

void mainWindow::abilita_bottoni(){
    rimuovi_opera->setEnabled(true);
    presta_rientra->setEnabled(true);
}

void mainWindow::disabilita_bottoni(){
   rimuovi_opera->setEnabled(false);
   presta_rientra->setEnabled(false);
}


mainWindow::~mainWindow(){


    std::cout<<"distruttore di main window"<<std::endl;
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete rimuovi_opera;
    delete tab;
    delete presta_rientra;
    delete controllerOP;
    delete aggiungi_libro;
    delete barra_cerca;
    delete aggiungi_rivista;
    delete exit;
}





