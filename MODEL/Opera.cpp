#include"Opera.h"
#include<QString>

//inizializzazione del massimo ID
int Opera::maxId=0;

//costruttore
Opera::Opera(QString tit,bool s): titolo(tit), statoP(s)
{
    maxId++;
    ID=maxId;
}



//*****************funzioni pubbliche*****************//

int Opera::Get_Id() const{ return ID; }
int Opera::Get_Max() const{ return maxId;}
void Opera::Set_Id(const int n){ ID=n; }
void Opera::Set_Max(const int n){ maxId=n; }

QString Opera::GetTitolo() const{
    return titolo;
}

bool Opera::Presente()const{ return statoP; }

void Opera::PrestaOpera(){ statoP=1; }



void Opera::RiscattaOpera(){ statoP=0; }


void Opera::Set_Titolo(const QString& text){ titolo=text;  }

bool Opera::ricerca_campi(const QString& text) const{
    int ID=text.toInt();
    if(QString::compare(text, GetTitolo(), Qt::CaseInsensitive)) return false;      //ricerca CaseInsensitive
    else return true;
    if(ID==Get_Id()) return true;
    return false;
}











void Opera::Mod_Opera(const QString& tit, const QString& au, const QString& ann){ titolo=tit; }





















