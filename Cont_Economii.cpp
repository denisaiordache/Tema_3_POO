//
// Created by denys on 08.05.2020.
//

#include "Cont_Economii.h"

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
    }
    return *this;
}

istream &operator>>(istream &in, Cont_Economii &c) {
    in>>(dynamic_cast<Cont&>(c));
    std::cout<<"Rata:"; in>>c.rata_dobanda;
    std::cout<<"Durata ratei:"; in>>c.nr_luni;
    std::cout<<"Istoricul soldului:"; in>>c.istoric;
    return in;
}


ostream &operator<<(ostream &out, const Cont_Economii &c) {
    out<<(static_cast<const Cont&>(c));
    out<<c.rata_dobanda<<" "<<c.nr_luni<<" "<<c.istoric;
    return out;
}


