#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>

class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(QObject *parent = 0);



public slots:
    //void showInfoSelection();          //creazione della vista interessata
};

#endif // C_LISTAOP_H
