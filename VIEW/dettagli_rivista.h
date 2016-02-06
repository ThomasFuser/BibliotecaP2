#ifndef DETTAGLI_RIVISTA_H
#define DETTAGLI_RIVISTA_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>

#include <QApplication>


#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include"../MODEL/database.h"
#include"../MODEL/info.h"

class Dettagli_Rivista : public QWidget
{
    Q_OBJECT
public:
    explicit Dettagli_Rivista(int, DataBase* =0, QWidget *parent = 0);
    void update_dettagli();
    ~Dettagli_Rivista();
signals:

public slots:


private:
    DataBase* model;
    int id;

    QLabel* t;     //titolo
    QLabel* p;     //prestito
    QLabel* i;     //id
    QLabel* a;     //anno
    QLabel* c;     //disponibilità

    QLineEdit* titolo;
    QLineEdit* prestito;
    QLineEdit* identificativo;
    QLineEdit* anno;
    QLineEdit* consultabile;

    QPalette* paletteLine;

    void set_style();
    void abilita_modifica();
    void disabilita_modifica();
};

#endif // DETTAGLI_RIVISTA_H



