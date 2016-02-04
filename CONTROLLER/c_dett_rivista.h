#ifndef C_DETT_RIVISTA_H
#define C_DETT_RIVISTA_H

#include <QObject>

#include "../VIEW/dettagli_rivista.h"
#include "../MODEL/database.h"

class c_Dett_Rivista : public QObject
{
    Q_OBJECT
public:
    explicit c_Dett_Rivista(DataBase*, Dettagli_Rivista*, QObject *parent = 0);

signals:

public slots:


private:
    DataBase* model;
    Dettagli_Rivista* view;

};

#endif // C_DETT_RIVISTA_H
