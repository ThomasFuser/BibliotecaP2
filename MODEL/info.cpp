#include "info.h"

info::info(QString t, QString s,QString i, QString d, QString c): titolo(t), stato(s), ID(i),
                                                                  dettaglio(d), consultabile(c){}

QString info::get_titolo() const{ return titolo; }

QString info::get_stato() const{ return stato; }

QString info::get_ID() const{ return ID; }

QString info::get_dettaglio() const{ return dettaglio; }

QString info::is_consultabile() const { return consultabile; }
