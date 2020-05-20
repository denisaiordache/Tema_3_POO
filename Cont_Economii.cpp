//
// Created by denys on 08.05.2020.
//

#include "Cont_Economii.h"
#include <iomanip>

Cont_Economii::Cont_Economii():Cont() {
    rata_dobanda=0;
    nr_luni=0;
    istoric.append(to_string(getSold()));


}

Cont_Economii::Cont_Economii(string &det, string &d, double s,double &r, int &n, string &ist):Cont(det,d,s) {
    this->rata_dobanda=r;
    this->nr_luni=n;
    this->istoric=ist;
}

Cont_Economii::Cont_Economii(const Cont_Economii &c):Cont(c) {
    this->rata_dobanda=c.rata_dobanda;
    this->nr_luni=c.nr_luni;
    istoric.append(" ");
    istoric.append(to_string(getSold()));
}

Cont_Economii &Cont_Economii::operator=(const Cont_Economii &c) {
    if(this!=&c)
    {
        this->Cont::operator=(c);
        this->rata_dobanda=c.rata_dobanda;
        this->nr_luni=c.nr_luni;
        this->istoric=c.istoric;
    }
    return *this;
}

istream &operator>>(istream &in, Cont_Economii &c) {
    std::cout<<"Introduceti datele referitoare la cont:"<<'\n';
    in>>(dynamic_cast<Cont&>(c));
    std::cout<<"Rata:"; in>>c.rata_dobanda;
    std::cout<<"Durata ratei:";
    try{
        in>>c.nr_luni;
        if(c.nr_luni!=3 && c.nr_luni!=6 && c.nr_luni!=12)
            throw "Intervalul ratei nu este corect!";
    }
    catch(char const* err){cout<<err;}
    std::ostringstream streamObj3;
    streamObj3 << std::fixed;
    streamObj3 << std::setprecision(2);
    streamObj3 << c.getSold();
    std::string strObj3 = streamObj3.str();
    c.istoric.append(" ");
    c.istoric.append(strObj3);
    return in;
}


ostream &operator<<(ostream &out,  Cont_Economii &c) {
    out<<(static_cast<Cont&>(c));
    out<<"Rata dobanda:"<<c.rata_dobanda<<'\n';
    out<<"Durata ratei:"<<c.nr_luni<<'\n';
    out<<"Istoric sold:"<<c.istoric<<'\n';
    return out;
}

void Cont_Economii::afis() {
    this->Cont::afis();
    cout<<"Rata dobanda:"<<this->rata_dobanda<<'\n';
    cout<<"Durata ratei:"<<this->nr_luni<<" "<<"luni"<<'\n';
    cout<<"Istoric sold:"<< this->istoric<<'\n';
}

void Cont_Economii::depunere(double val) {
    this->sold=this->sold+val;

}


