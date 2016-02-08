#ifndef WIDGET_PADRE_H
#define WIDGET_PADRE_H

#include <QWidget>
#include <QDesktopWidget>



class DataBase;                 //in questo modo evito l'inclusione circolare (DataBase e header)

class Widget_Padre : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Padre(DataBase*, QWidget *parent = 0);
    virtual void aggiorna_vista() =0;
signals:

public slots:

private:
    DataBase* model;

protected:

    DataBase* get_model() const;

    virtual void set_style() =0;
    virtual void costruisci_contenuto() =0;

    virtual ~Widget_Padre(){};
    void centra_finestra();

};

#endif // WIDGET_PADRE_H
