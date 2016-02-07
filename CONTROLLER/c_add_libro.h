#ifndef C_ADD_LIBRO_H
#define C_ADD_LIBRO_H

#include <QObject>
#include<QApplication>
#include "../VIEW/inserisci_libro.h"
#include "../MODEL/database.h"

class c_add_libro : public QObject
{
    Q_OBJECT
public:
    explicit c_add_libro(DataBase* , inserisci_Libro* ,QObject *parent = 0);

signals:

public slots:
    void add(QString,QString);


private:
    DataBase* model;
    inserisci_Libro* view;
};


#endif // C_ADD_LIBRO_H
