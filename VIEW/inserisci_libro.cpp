#include "inserisci_libro.h"

inserisci_Libro::inserisci_Libro(QWidget *parent) : QWidget(parent){
    submit=new QPushButton("CONFERMA");

    t=new QLabel("TITOLO:");
    a=new QLabel("AUTORE");

    titolo=new QLineEdit();
    autore=new QLineEdit();

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();

    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
}


void inserisci_Libro::build_Layout(){

    grid->addWidget(t,0,0); grid->addWidget(titolo,0,1);
    grid->addWidget(a,1,0); grid->addWidget(autore,1,1);

    layout->addLayout(grid);
    layout->addWidget(submit);

    setLayout(layout);
}


void inserisci_Libro::slot_submit(){
    if(titolo->text().isEmpty() || titolo->text().isNull() ||  autore->text().isEmpty() || autore->text().isNull())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inserire una nuova rivista");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Inserisci nuova rivista");
            warning.setText("Sei sicuro di voler inserire la rivista <b>"+titolo->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
                std::cout<<"invio segnale submitR"<<std::endl;
                /*info op(titolo->text(),"","",anno->text());
                emit submitR(op);
                pulisci_Campi();*/
                QString uno=titolo->text();
                QString due=autore->text();
                emit submitL(uno,due);
                std::cout<<"emissione segnale 2"<<std::endl;
                emit prova();

            }
}}
void inserisci_Libro::pulisci_Campi(){
    titolo->clear();
    autore->clear();
}


