#include"database.h"

//QString DataBase::filename="DataBase.xml";
QString DataBase::filename="../BibliotecaP2/DataBase.xml";

//iteratori

container::iteratore DataBase::db_begin(){ return db.begin(); }
container::iteratore DataBase::db_end(){ return db.end(); }


DataBase::DataBase(){ Load();}
DataBase::~DataBase(){ Close(); }

void DataBase::Load(){
    //variabili provvisorie
    int tipo=0, anno=0, stato=-1, id=0,max=0;
    QString autore="Unknown", titolo="Unknown";
    Opera* op=0;

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();
    while(!xmlReader.atEnd())                                //legge il file fino alla fine del file
    {
        if(xmlReader.isStartElement())                       //legge tag apertura
        {
            if(xmlReader.name()=="database"|| xmlReader.name()=="opera") xmlReader.readNext();          //se leggo tag "database" o "opera" allora vado avanti
            else

                if(xmlReader.name()=="max") max=xmlReader.readElementText().toInt();
                else

                if(xmlReader.name()=="tipo") tipo=xmlReader.readElementText().toInt();
                else
                    if(xmlReader.name()=="id") id=xmlReader.readElementText().toInt();
                    else

                    if(xmlReader.name()=="stato") stato=xmlReader.readElementText().toInt();
                    else

                    if(tipo==1)                     //sto leggendo una rivista
                    {
                        if(xmlReader.name()=="titolo") titolo=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="anno") anno=xmlReader.readElementText().toInt();
                            else std::cout<<"Errore: La rivista sembra essere corrotta. Lettura non valida"<< std::endl;        //ci sono dei tag non validi
                    }else
                        if(tipo==2)                 //sto leggendo un libro
                        {
                            if(xmlReader.name()=="titolo") titolo=xmlReader.readElementText();
                            else
                                if(xmlReader.name()=="autore") autore=xmlReader.readElementText();
                                else std::cout<<"Errore: Il libro sembra essere corrotto. Lettura non valida"<< std::endl;      //ci sono dei tag non validi
                        }else std::cout<<"Errore: Opera non riconosciuta. Tipo: "<<tipo<< std::endl;
        }else                                                                   //sto leggendo la chiusura di qualche tag
        {
             if(xmlReader.isEndElement() && xmlReader.name()=="opera")          //leggo </opera> -> posso costruire un'opera
             {
                 if(tipo==1) op= new Rivista(titolo,anno,stato);             //costruisco una rivista
                 else op=new Libro(titolo,autore,stato);                     //costruisco un libro
                 //sistemo i valori che il costruttore di Opera mi "sballa"
                 op->Set_Id(id);
                 op->Set_Max(max);
                 db.add_item(op);                                      //aggiungo l'opera nel contenitore
                 xmlReader.readNext();
             }else xmlReader.readNext();
        }
    }

    file.close();
}


void DataBase::Close(){
    QFile file(filename);
         file.open(QIODevice::WriteOnly);

         QXmlStreamWriter xmlWriter(&file);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();

         xmlWriter.writeStartElement("database");

         container::iteratore it=db.begin();
         if(!vuoto())
         {
            int max_val=db[it]->Get_Max();
            QString MAX;
            MAX.setNum(max_val);
            xmlWriter.writeTextElement("max",MAX);
            for(it; it!=db.end(); ++it)                                    //passa tutto il contenitore
                db[it]->Write_Opera(xmlWriter);

         }
         xmlWriter.writeEndDocument();                                  //</database>
         file.close();
}

//metodi pubblici database
bool DataBase::vuoto() const{ return db.empty(); }

//PRE=(opera* op può essere anche =0. L'opera può anche essere presente nella biblioteca)
void DataBase::Add_Opera(Opera* op)
{
    if(!op) std::cout<<"impossibile aggiungere l'opera"<<std::endl;
    else db.add_item(op);
}
//POST=(inserisce nel contenitore l'opera <=> è una opera valida quindi op!=0)

void DataBase::add_Rivista(info op){
    int anno=op.get_dettaglio().toInt();
    Rivista* r=new Rivista(op.get_titolo(),anno);
    db.add_item(r);
}

void DataBase::add_Libro(info op){
    Libro* l=new Libro(op.get_titolo(),op.get_dettaglio());
    db.add_item(l);
}



//cerca un'opera che abbia tra i campi dati la stringa text e ritorna un containitore di puntatori
container DataBase::cerca_opera(const QString& text) const
{
    container cont;
    for(container::iteratore it=db.begin(); it!=db.end(); it++)
        if(db[it]->ricerca_campi(text)) cont.add_item(db[it]);
    return cont;
}





Opera* DataBase::Trova_Precisa(int id) const
{
    if(vuoto())
    {
        std::cout<<"Errore: DataBase vuoto"<<std::endl;
        return 0;
    }
    bool trovata=false;
    container::iteratore it=db.begin();
    container::iteratore ris;
    while(it!=db.end() && !trovata)
    {
        if((*it)->Get_Id()==id) trovata=true;
        ris=it;
        it++;
    }
    if(!trovata) return 0;
    return db[ris];
}

void DataBase::remove_opera(const int id)
{  
    Opera* prov=Trova_Precisa(id);
    if(prov!=0) db.remove_item(prov);
    else std::cout<<"nessuna opera da cancellare"<<std::endl;
}

info DataBase::get_infoOpera(int ID) const{
    Opera* op=Trova_Precisa(ID);
    if(!op)
    {
        std::cout<<"opera non trovata"<<std::endl;
        return info("Sconosciuto", "Sconosciuto", "ID non valido", "Sconosciuto","Sconosciuto");
    }
    return info(op->get_infoTot());
}


void DataBase::Presta_ricevi(int ID){
    Opera* op=Trova_Precisa(ID);
    if(op)
    {
        if(op->Presente()) op->PrestaOpera();
        else op->RiscattaOpera();
    }else std::cout<<"opera non trovata"<<std::endl;
}





















