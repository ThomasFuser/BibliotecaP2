#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>
#include "../MODEL/database.h"
#include "../VIEW/listaop.h"

#include "../CONTROLLER/c_dett_libro.h"          //#include "../VIEW/dettagli_libro.h"
#include "../VIEW/dettagli_rivista.h"

class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(DataBase*, listaOp*, QObject *parent = 0);
    ~C_listaop();

public slots:
    void visualizza_info(int);          //creazione della vista interessata

private:
    DataBase* model;
    listaOp* view;
    Dettagli_Libro* dett_libro;
    Dettagli_Rivista* dett_rivista;
};

#endif // C_LISTAOP_H
