#ifndef DETTAGLI_LIBRO_H
#define DETTAGLI_LIBRO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>

#include <QApplication>


#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include"../MODEL/database.h"
#include"../MODEL/info.h"

class Dettagli_Libro : public QWidget
{
    Q_OBJECT
public:
    explicit Dettagli_Libro(int, DataBase* =0, QWidget *parent = 0);
    void update_dettagli();
    ~Dettagli_Libro();

signals:

public slots:


private:
    DataBase* model;
    int id;

    QPushButton* presta_ritira;
    QLabel* t;     //titolo
    QLabel* p;     //stato
    QLabel* i;     //id
    QLabel* a;     //anno
    QLabel* c;     //disponibilità

    QLineEdit* titolo;
    QLineEdit* prestito;
    QLineEdit* identificativo;
    QLineEdit* autore;
    QLineEdit* consultabile;

    QPalette* paletteLine;

    void set_style();
    void disabilita_modifica();
    void abilita_modifica();
};





#endif // DETTAGLI_LIBRO_H
