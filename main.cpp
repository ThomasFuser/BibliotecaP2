#include <QApplication>
#include <iostream>

#include "MODEL/Opera.h"
#include "MODEL/Rivista.h"
#include "MODEL/Libro.h"

#include "MODEL/database.h"
#include <VIEW/listaop.h>
#include <VIEW/dettagli_rivista.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase* db=new DataBase();        //creo un oggetto DataBase che al momento della sua costruzione riempie
                        //un contenitore in RAM con tutte le opere trovate nell'archivio
/*cout<<"ciaooooo"<<endl;
    QString uno("ciao");
    QString due("ciao ciao");
    QString conc=uno+due;
   // cout<<conc.toInt()<<endl;*/
   /* Opera* nuova=new Libro("1Q84","giapponese");
    db->Add_Opera(nuova);*/
    db->remove_opera(10);
    db->remove_opera(11);
    db->remove_opera(12);
    db->remove_opera(7);
    db->remove_opera(8);
    db->remove_opera(6);


    Dettagli_Rivista prov(3,db);
    prov.show();



    listaOp view(db);

    view.show();


    delete db;


    return a.exec();
}






























/*container cont;
Opera* prov=new Rivista("ciao",1912);
Opera* prov1=new Libro("coion","ciao");
cont.add_item(prov);
cont.add_item(prov1);


container nuovo=cont.find_item("ciao");
std::cout<<nuovo.empty()<<std::endl;
container::iteratore it=nuovo.begin();
for(it=nuovo.begin();it!=nuovo.end();it++)*/

    //*****************  c'è una conversione da Qstring a std::string  *****************//
/*std::cout<<"primo elemento"<<((nuovo[it])->GetTitolo()).toStdString()<<std::endl;


std::cout<<cont.empty()<<std::endl;
cont.remove_item(prov);
//cont.remove_item(prov1);
std::cout<<cont.empty()<<std::endl;*/




//SECONDE PROVE : INSERIMENTO CANCELLAZIONE OPERE
                /*
                container::iteratore it;
                    for(it=db->db_begin(); it!=db->db_end(); it++)       //non mi convince l'utilizzo dell'iteratore fatto qui
                    {std::cout<<"questa opera è: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;}

                    std::cout<<"fuori op"<<std::endl<<std::endl<<std::endl;

                    Opera* prov=new Rivista("Airone",2016);
                    db->Add_Opera(prov);

                     container risultato=db->cerca_opera("ciao");
                     if(risultato.empty()) std::cout<<"nessun risultato"<<std::endl;
                     else{
                         container::iteratore iter=risultato.begin();        // std::cout<<"questa opera èèèèèèèèèè: "<<(iter.getIt()->GetTitolo()).toStdString()<<std::endl;
                         db->remove_opera(risultato[iter]);
                     }






                       std::cout<<std::endl<<"\n\n\nle nuove opere sono le seguenti: "<<std::endl;

                   for(container::iteratore it=db->db_begin(); it!=db->db_end(); it++)       //non mi convince l'utilizzo dell'iteratore fatto qui
                      std::cout<<"questa opera è: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;

                    //faccio una ricerca di una opera:

                */



                     /*for(container::iteratore it=db->db_begin(); it!=db->db_end(); it++)       //non mi convince l'utilizzo dell'iteratore fatto qui
                     {

                        std::cout<<"questa opera è: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;
                     }

*/
/*  if(db->vuoto()) std::cout<<"vuoto"<<std::endl;

container::iteratore it;
  for(it=db->db_begin(); it!=db->db_end(); it++)       //non mi convince l'utilizzo dell'iteratore fatto qui
  {std::cout<<"questa opera è: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;}
std::cout<<"sotto for"<<std::endl;


Opera* op=new Libro("lilli lilli lilli","V per Venditti");
db->Add_Opera(op);
/*container risultato=db->cerca_opera("lilli lilli lilli");
container::iteratore iter=risultato.begin();
db->remove_opera(risultato[iter]);*/
/*

   container risultato=db->cerca_opera("TV sorrisi e canzoni");
   if(risultato.empty()) std::cout<<"nessun risultato"<<std::endl;
   else{
       container::iteratore iter=risultato.begin();        // std::cout<<"questa opera èèèèèèèèèè: "<<(iter.getIt()->GetTitolo()).toStdString()<<std::endl;
       db->remove_opera(risultato[iter]);
   }

     std::cout<<std::endl<<"\n\n\nle nuove opere sono le seguenti: "<<std::endl;

 for(container::iteratore it=db->db_begin(); it!=db->db_end(); it++)       //non mi convince l'utilizzo dell'iteratore fatto qui
    std::cout<<"questa opera è: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;

 it=db->db_begin();

std::cout<<"questa opera èèèèè: "<<(it.getIt()->GetTitolo()).toStdString()<<std::endl;

Opera* m=new Rivista("ciao",1912);



db->Mod_Opera(m,"ciao","","");


*/















