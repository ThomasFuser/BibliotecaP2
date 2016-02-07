#ifndef INSERISCI_LIBRO_H
#define INSERISCI_LIBRO_H

#include <QWidget>
 #include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>

#include "../MODEL/database.h"

class inserisci_Libro : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_Libro(QWidget *parent = 0);

signals:
    void submitL(QString, QString);
    void prova();
public slots:
    void slot_submit();
private:

    QPushButton* submit;

    QLabel* t;     //titolo
    QLabel* a;     //anno

    QLineEdit* titolo;
    QLineEdit* autore;

    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();



};

#endif // INSERISCI_LIBRO_H