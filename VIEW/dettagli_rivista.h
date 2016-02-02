#ifndef DETTAGLI_RIVISTA_H
#define DETTAGLI_RIVISTA_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include"../MODEL/database.h"

class Dettagli_Rivista : public QWidget
{
    Q_OBJECT
public:
    explicit Dettagli_Rivista(DataBase* =0, QWidget *parent = 0);

signals:

public slots:


private:
    DataBase* model;
    //QLineEdit* lineEdits;

};

#endif // DETTAGLI_RIVISTA_H
