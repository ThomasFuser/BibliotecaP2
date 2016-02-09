#ifndef DETTAGLI_LIBRO_H
#define DETTAGLI_LIBRO_H

#include"dettagli_opera.h"

class Dettagli_Libro : public Dettagli_opera
{
    Q_OBJECT
public:
    explicit Dettagli_Libro(int, DataBase*);
    void update_dettagli();
    ~Dettagli_Libro();

private:

    QLabel* a;     //autore

    QLineEdit* autore;

    void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void set_style();

};





#endif // DETTAGLI_LIBRO_H
