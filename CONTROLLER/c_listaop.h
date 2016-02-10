#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/listaop.h"
#include "../VIEW/dettagli_rivista.h"
#include "../VIEW/dettagli_libro.h"

class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(DataBase*, listaOp*, QObject *parent = 0);

public slots:
    void visualizza_info(int);
    void chiudi_dettagli_libro();
    void chiudi_dettagli_rivista();
private:
    DataBase* model;
    listaOp* view;
    Dettagli_Libro* dett_libro;
    Dettagli_Rivista* dett_rivista;
};

#endif // C_LISTAOP_H
