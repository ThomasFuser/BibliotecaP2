#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>
#include "../MODEL/database.h"
#include "../VIEW/listaop.h"
#include "../VIEW/dettagli_libro.h"
#include "../VIEW/dettagli_rivista.h"

class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(DataBase*, listaOp*, QObject *parent = 0);


public slots:
    void visualizza_info(int) const;          //creazione della vista interessata

private:
    DataBase* model;
    listaOp* view;
};

#endif // C_LISTAOP_H
