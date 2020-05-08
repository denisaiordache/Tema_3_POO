//
// Created by denys on 08.05.2020.
//

#include "Cont.h"


Cont::Cont(string &det, string &d, double s) {
    detinator=det;
    data=d;
    sold=s;

}

Cont::Cont() {
    detinator="";
    data="";
    sold=0;

}

Cont::Cont(const Cont &c) {
    this->detinator=c.detinator;
    this->sold=c.sold;
    this->data=c.data;
}


Cont &Cont::operator=(const Cont &c) {
    if(this!=&c)
    {this->detinator=c.detinator;
    this->data=c.data;
    this->sold=c.sold;}
    return *this;
}

istream &operator>>(istream &in, Cont &c) {
    cout<<"Detinator:"<<"";
    getline(in,c.detinator);
    cout<<"Data:"<<"";
    getline(in,c.data);
    cout<<"Sold:"<<"";
    in>>c.sold;
    return in;
}

ostream &operator<<(ostream &out, const Cont &c) {
    out<<"Nume detinator:"<<" "<<c.detinator<<'\n';
    out<<"Data deschiderii contului:"<<" "<<c.data<<'\n';
    out<<"Sold cont:"<<" "<<c.sold<<'\n';
    return out;
}

void Cont::afis() {
    cout<<(*this);

}

double Cont::getSold() {
    return sold;
}

