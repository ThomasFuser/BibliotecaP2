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
#include <QVBoxLayout>
#include"../MODEL/database.h"
#include"../MODEL/info.h"

class Dettagli_Rivista : public QWidget
{
    Q_OBJECT
public:
    explicit Dettagli_Rivista(int, DataBase* =0, QWidget *parent = 0);
     void update_dettagli();
signals:

public slots:


private:
    DataBase* model;
    int id;

    QPushButton* quit;
    QLabel* t;     //titolo
    QLabel* s;     //stato
    QLabel* i;     //id
    QLabel* a;     //anno

    QLineEdit* titolo;
    QLineEdit* stato;
    QLineEdit* identificativo;
    QLineEdit* anno;

    QPalette* paletteLine;

    void set_style();
    void abilita_modifica();
    void disabilita_modifica();
};

#endif // DETTAGLI_RIVISTA_H

