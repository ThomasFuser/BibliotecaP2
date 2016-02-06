#ifndef C_ADD_RIVISTA_H
#define C_ADD_RIVISTA_H

#include <QObject>
#include "../VIEW/inserisci_rivista.h"
#include "../MODEL/database.h"

class c_add_rivista : public QObject
{
    Q_OBJECT
public:
    explicit c_add_rivista(DataBase*, inserisci_Rivista*, QObject *parent = 0);

signals:

public slots:
    void add(info);
private:
    DataBase* model;
    inserisci_Rivista* view;

};

#endif // C_ADD_RIVISTA_H
