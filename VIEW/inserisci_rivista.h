#ifndef INSERISCI_RIVISTA_H
#define INSERISCI_RIVISTA_H

#include <QWidget>
 #include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>

#include "../MODEL/database.h"

class inserisci_Rivista : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_Rivista(QWidget *parent = 0);

signals:
    void submitR(info);
public slots:
    void slot_submit();
private:

    QPushButton* submit;

    QLabel* t;     //titolo
    QLabel* a;     //anno

    QLineEdit* titolo;
    QLineEdit* anno;

    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();



};

#endif // INSERISCI_RIVISTA_H
