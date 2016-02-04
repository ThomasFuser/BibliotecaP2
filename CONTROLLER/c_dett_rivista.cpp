#include "c_dett_rivista.h"

c_Dett_Rivista::c_Dett_Rivista(DataBase* db,Dettagli_Rivista* v, QObject *parent) : model(db),
                                                                                    view(v),
                                                                                    QObject(parent)  {

}
