#include"database.h"

QString DataBase::filename="../BibliotecaP2/DataBase.xml";


container::iteratore DataBase::db_begin(){ return db.begin(); }
container::iteratore DataBase::db_end(){ return db.end(); }


DataBase::DataBase(){ Load(); }
DataBase::~DataBase(){ Close(); }


void DataBase::Load(){
    //variabili provvisorie
    int tipo=0, anno=0, stato=-1, id=0,max=0;
    QString autore="Sconosciuto", titolo="Sconosciuto";
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
                 //sistemo i valori che il costruttore di Opera modifica
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


bool DataBase::vuoto() const{ return db.empty(); }


void DataBase::add_Rivista(const info& op){
    int anno=op.get_dettaglio().toInt();
    Rivista* r=new Rivista(op.get_titolo(),anno,1);
    db.add_item(r);
}


void DataBase::add_Libro(const info& op){
    Libro* l=new Libro(op.get_titolo(),op.get_dettaglio(),1);
    db.add_item(l);
}


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
        return info("Opera non presente", "Opera non presente", "Opera non presente", "Opera non presente","Opera non presente");
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


void DataBase::aggiorna_view() const{
    std::vector<Widget_Padre*>::const_iterator it=registro.begin();
    std::vector<Widget_Padre*>::const_iterator it_e=registro.end();
    for(; it<it_e; ++it) (*it)->aggiorna_vista();
}


void DataBase::add_registro(Widget_Padre* wp){
    registro.push_back(wp);
}


void DataBase::remove_registro(Widget_Padre* wp){
    std::vector<Widget_Padre*>::iterator it=registro.begin();
    std::vector<Widget_Padre*>::iterator it_e=registro.end();
    bool trovato=false;
    for(; it<it_e && !trovato; ++it)
    {
        if((*it)==wp){
            trovato=true;
            registro.erase(it);
        }
    }
}
