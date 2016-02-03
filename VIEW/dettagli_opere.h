#ifndef DETTAGLI_OPERE_H
#define DETTAGLI_OPERE_H

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

class dettagli_opere : public QWidget
{
    Q_OBJECT
public:
    explicit dettagli_opere(int, DataBase* =0, QWidget *parent = 0);

signals:

public slots:
private:
    DataBase* model;
    int id;

    QPushButton* quit;
    QLabel* t;     //titolo
    QLabel* s;     //stato
    QLabel* i;     //id


    QLineEdit* titolo;
    QLineEdit* stato;
    QLineEdit* identificativo;

};

#endif // DETTAGLI_OPERE_H
