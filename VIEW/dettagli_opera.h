
#ifndef DETTAGLI_OPERA_H
#define DETTAGLI_OPERA_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

#include"../MODEL/database.h"
#include "widget_padre.h"



class Dettagli_opera : public Widget_Padre{
    Q_OBJECT

public:
    void closeEvent(QCloseEvent*);
    virtual ~Dettagli_opera();
signals:
    void chiudi_dettagli_opera();

protected:
    explicit Dettagli_opera(int, DataBase* );

    virtual void set_style();
    virtual void costruisci_contenuto();
    void disabilita_modifica();


private:

    int id;

    QLabel* t;                  //titolo
    QLabel* p;                  //prestito
    QLabel* i;                  //id
    QLabel* c;                  //disponibilità

    QLineEdit* titolo;
    QLineEdit* prestito;
    QLineEdit* identificativo;
    QLineEdit* consultabile;

    QPalette* paletteLine;
    QGridLayout* grid;

    void registra() const;
    void elimina_registrazione() const;

public:

    virtual void aggiorna_vista();
    int get_ID()const;
    QPalette* get_paletteLine()const;
    QGridLayout* get_grid()const;

};

#endif // DETTAGLI_OPERA_H
