#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(DataBase* db,mainWindow* v, QObject *parent) :model(db),view(v),  QObject(parent) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
    connect(view,SIGNAL(aggiorna_prestito(int)),this,SLOT(aggiorna_prestitoDB(int)));
}


void C_mainWindow::rimuovi_operaDB(int ID){
    model->remove_opera(ID);
    view->updateMainWindow();
}

void C_mainWindow::aggiorna_prestitoDB(int ID){
    try{ model->Presta_ricevi(ID); }
    catch(Exc){
        QString identificativo;
        identificativo.setNum(ID);
        QMessageBox warning;
            warning.setIcon(QMessageBox::Warning);
            warning.setWindowTitle("OPERAZIONE NON ESEGUITA");
            warning.setText("L'opera con ID <b>"+identificativo+"</b> non può essere prestata in quanto ha una data di uscita maggiore o uguale a 20 anni");
            warning.setStandardButtons(QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
    }
    emit aggiorna_dettagli();

}
