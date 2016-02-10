#ifndef WIDGET_PADRE_H
#define WIDGET_PADRE_H

#include <QWidget>
#include <QDesktopWidget>



class DataBase;

class Widget_Padre : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Padre(DataBase*, QWidget *parent = 0);
    virtual ~Widget_Padre();

    DataBase* get_model() const;                //ritorna un puntatore al database
    virtual void set_style() =0;                //imposta lo stile nelle view
    virtual void aggiorna_vista() =0;           //aggionrnamento del contenuto di ogni vista
    virtual void costruisci_contenuto() =0;     //costruisce il contenuto delle view
    void centra_finestra();                     //permette di centrare la finestra al momento della sua creazione
private:
    DataBase* model;
};

#endif // WIDGET_PADRE_H
