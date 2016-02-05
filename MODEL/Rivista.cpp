#include"Rivista.h"

//campo dati statico
int  Rivista::maxAnni=20;

//costruttore
Rivista::Rivista(QString tit, int anno, bool stato): Opera(tit,stato) , annoUscita(anno)
{
    if(anno<1000)
    {
        std::cout<<"Errore: anno inserito non valido"<<std::endl;
        annoUscita=1000;
    }
}

//*****************funzioni pubbliche*****************//
int Rivista::GetMaxAnni() const{ return maxAnni; }

int Rivista::GetAnnoUscita() const{ return annoUscita; }

void Rivista::SetMaxAnni(const int newAnno){
    maxAnni=newAnno;
    return;
}
void Rivista::Set_Anno_Uscita(int a)
{
    if(a<1000){ std::cout<<"Errore: anno inserito non valido"<<std::endl; }
    else annoUscita=a;
}

//concretizzazione dei metodi virtuali della classe base

//PRE=(this è una Rivista e annoUscita contiene l'anno di uscita di essa)
bool Rivista::disponibile() const{
        if(Presente()){
            time_t t = time(0);             //oggetto che contenente anno auttuale
            tm* timePtr = localtime(&t);
            if(((timePtr->tm_year + 1900)-annoUscita)<=maxAnni) return true;
            return false;
        }
        return false;
}

void Rivista::Write_Opera(QXmlStreamWriter& xmlWriter) const{

    QString anno;
    int a=GetAnnoUscita();
    anno.setNum(a);                            // ATTENZIONE A QUESTA STRINGA. NON MI CONVINCE
    xmlWriter.writeStartElement("opera");      // <Opera>
    xmlWriter.writeTextElement("tipo", "1");

    int id=Get_Id();
    QString ID;
    ID.setNum(id);
    xmlWriter.writeTextElement("id", ID );            //<id>

    int s=Presente();
    QString stato;
    stato.setNum(s);
    xmlWriter.writeTextElement("stato",stato);
    xmlWriter.writeTextElement("titolo", GetTitolo());
    xmlWriter.writeTextElement("anno", anno);       //non potevo mettere il metodo;non funziona la conversione

    xmlWriter.writeEndElement();            //</opera>

}
//POST=(la funzione ritorn true <=> (il tempo (anni )trascorso dall'uscita della rivista )<=maxAnni. Ritorna false altrimenti)


bool Rivista::ricerca_campi(const QString& text) const
{
    if(Opera::ricerca_campi(text)) return true;
    bool ok=false;
    int anno=text.toInt(&ok);
    if(ok && anno==GetAnnoUscita())   return true;                 //la stringa contiene effettivamente un numero
    return false;
}


void Rivista::Mod_Opera(const QString& titolo, const QString& autore, const QString& anno)
{
    if(!(titolo.isEmpty())) Opera::Mod_Opera(titolo,autore,anno);
    if(!(anno.isEmpty()))
    {
        int a=anno.toInt();
        if(a>=1000) annoUscita=a;
    }
}
QString Rivista::get_Tipo()const{ return "Rivista"; }


info Rivista::get_infoTot()const{
    QString dsp="disponibile", anno="1900", ID, pr="si";
    if(!disponibile()) dsp="non disponibile";
    if(!Presente()) pr="no";
    anno.setNum(GetAnnoUscita());
    ID.setNum(Get_Id());
    return info(GetTitolo(), dsp, ID, anno,pr);
}


//si può prestare una rivista solo se gli anni dalla sua uscita sono minori di max anni quindi solo se è disponibile
void Rivista::PrestaOpera(){
    if(disponibile()) Opera::PrestaOpera();
    else std::cout<<"non è possibile prestare l'opera"<<std::endl;
}

//si può riscattare una opera con lo stesso vincolo del prestito. in particolare ho aggiunto un controllo che permette di riscattare opere che altrimenti non è possibile riscattare
void Rivista::RiscattaOpera(){
     time_t t = time(0);             //oggetto che contenente anno attuale
     tm* timePtr = localtime(&t);
     if(((timePtr->tm_year + 1900)-annoUscita)<=maxAnni) Opera::RiscattaOpera();
     else std::cout<<"non è possibile riscattare l'opera"<<std::endl;
}



















