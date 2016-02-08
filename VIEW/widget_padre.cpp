#include "widget_padre.h"

Widget_Padre::Widget_Padre(DataBase* db,QWidget *parent) :model(db), QWidget(parent)
{
}



DataBase* Widget_Padre::get_model()const { return model; }
