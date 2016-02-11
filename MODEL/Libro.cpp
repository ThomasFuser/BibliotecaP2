#include"Libro.h"

Libro::Libro(const QString& tit, const QString& al, bool stat): Opera(tit,stat), autore(al){}

QString Libro::GetAutore() const{ return autore; }

/*bool Libro::disponibile() const {
    if(Presente()) return true;
    return false;
}*/

void Libro::Write_Opera(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeStartElement("opera");               //<opera>
    xmlWriter.writeTextElement("tipo", "2");            //<tipo>

    int id=Get_Id();
    QString ID;
    ID.setNum(id);
    xmlWriter.writeTextElement("id", ID );            //<id>

    int s=Presente();
    QString stato;
    stato.setNum(s);
    xmlWriter.writeTextElement("stato", stato );            //<tipo>

    xmlWriter.writeTextElement("titolo", GetTitolo());  //<titolo>...</titolo>
    xmlWriter.writeTextElement("autore", GetAutore());  //<autore>...</autore>
    xmlWriter.writeEndElement();                        //</opera>
}


bool Libro::ricerca_campi(const QString& text) const{

    if(Opera::ricerca_campi(text)) return true;     //eseguo prima funzione della classe base
    if(QString::compare(text, GetAutore(), Qt::CaseInsensitive)) return false;              //aggiungo funzionalità
    return true;
}


info Libro::get_infoTot()const{
    QString dsp="disponibile", ID, pr="si";
    if(!disponibile()) dsp="non disponibile";
    if(!Presente()) pr="no";
    ID.setNum(Get_Id());
    return info(GetTitolo(), dsp, ID, GetAutore(),pr);
}

QString Libro::get_Tipo()const{ return "Libro"; }





