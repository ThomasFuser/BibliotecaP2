#include"container.h"

//******************************************** CONTAINER ********************************************//

//costruttore contenitore vuoto
container::container(): first(0){}

//costruzione di copia
container::container(const container& cont): first(cont.first){}

//operatore di assegnazione
container& container::operator=(const container& cont)
{
    if(&cont==this) return *this;
    first=cont.first;
    return *this;
}


                                //metodi pubblici di utilità per l'utente
bool container::empty() const{ return first==0; }

void container::add_item(Opera* o)
{
    first=new nodo(o,first);
}

void container::remove_item(Opera* o)       //condivisione controllata della memoria
{    
    smartp p=first, prec, q;
    smartp original=first;
    first=0;
    while(p!=0 && !(p->op==o))
    {
        q=new nodo(p->op,p->next);
        if(prec==0) first=q;
        else prec->next=q;
        prec=q;
        p=p->next;
    }
    if(p==0) first=original;
    else if(prec==0) first=p->next;
         else prec->next=p->next;
}


//********  metodi di contenitore che usano iteratori */

container::iteratore container::begin() const
{
    iteratore prov;
    prov.punt=first;
    return prov;
}

container::iteratore container::end() const{
    iteratore prov;
    prov.punt=0;
    return prov;
}

Opera* container::operator[](const container::iteratore& i) const{
    return i.punt->op;              //quando non è presente il db mida errore qui
}



//******************************************** NODO ********************************************//

container::nodo::nodo(Opera* o, const smartp& n): op(o), next(n), riferimenti(0){}

//******************************************** SMARTP ********************************************//


container::smartp::smartp(nodo* n): punt(n)
{
    if(punt) punt->riferimenti++;
}

container::smartp::~smartp()
{
    if(punt)
    {
        (punt->riferimenti)--;
        if((punt->riferimenti)==0) delete punt;
    }
}

container::smartp::smartp(const smartp& sp): punt(sp.punt) { if(punt) punt->riferimenti++; }

container::smartp& container::smartp::operator=(const smartp& sp)
{
    if(this == &sp) return *this;					//tento di fare un'assegnazione con lo stesso puntatore
    nodo* prov=punt;
    punt=sp.punt;
    if(punt) (punt->riferimenti)++;
    if(prov)
    {
        (prov->riferimenti)--;
        if(!(prov->riferimenti)) delete prov;
    }
    return *this;
}

bool container::smartp::operator==(const smartp& sm)const { return (punt==sm.punt); }


bool container::smartp::operator!=(const smartp& sm)const { return (sm.punt!=punt); }


container::nodo* container::smartp::operator->()const { return punt; }

container::nodo& container::smartp::operator*()const { return *punt; }

//**************************** ITERATORE ****************************//

bool container::iteratore::operator==(const iteratore& i) const{
    return i.punt==punt;
}

bool container::iteratore::operator!=(const iteratore& i) const{
    return i.punt!=punt;
}

container::iteratore&  container::iteratore::operator++(){          //operatore prefisso
    if(punt!=0) punt=punt->next;
    return *this;

}

container::iteratore&  container::iteratore::operator++(int){        //operatore postfisso
    iteratore prov= *this;
    if(punt!=0) punt=punt->next;
    return prov;
}

Opera* container::iteratore::operator*()const{ return punt->op; }
