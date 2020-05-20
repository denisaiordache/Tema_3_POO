//
// Created by denys on 09.05.2020.
//

#include "Cont_Curent.h"

Cont_Curent::Cont_Curent():Cont() {
    nr_tranzactii_gratuite=0;
    comision_retragere=0.0;
}

Cont_Curent::Cont_Curent(string &det, string &d, double s, int &nr_t, double &com):Cont(det,d,s) {
    this->nr_tranzactii_gratuite=nr_t;
    this->comision_retragere=com;
}

Cont_Curent::Cont_Curent(const Cont_Curent &cc):Cont(cc) {
    this->nr_tranzactii_gratuite=cc.nr_tranzactii_gratuite;
    this->comision_retragere=cc.comision_retragere;
}

Cont_Curent &Cont_Curent::operator=(const Cont_Curent &cc) {
    if(this!=&cc)
    {
        this->Cont::operator=(cc);
        this->nr_tranzactii_gratuite=cc.nr_tranzactii_gratuite;
        this->comision_retragere=cc.comision_retragere;
    }
    return *this;
}

istream &operator>>(istream &in, Cont_Curent &cc) {
    in>>(dynamic_cast<Cont&>(cc));
    std::cout<<"Tranzactii gratuite:"; in>>cc.nr_tranzactii_gratuite;
    std::cout<<"Comision:"; in>>cc.comision_retragere;
    return in;
}

ostream &operator<<(ostream &out, Cont_Curent &cc) {
    out<<(static_cast<Cont&>(cc));
    out<<"Tranzactii gratuite ramase:"<<cc.nr_tranzactii_gratuite<<'\n';
    out<<"Comision:"<<cc.comision_retragere<<'\n';
    return out;
}

void Cont_Curent::afis() {
    this->Cont::afis();
    cout<<"Tranzactii gratuite ramase:"<<this->nr_tranzactii_gratuite<<'\n';
    cout<<"Comision retrageri:"<<this->comision_retragere<<'\n';
}

void Cont_Curent::depunere(double val) {
    this->sold=this->sold+val;
}

void Cont_Curent::retragere(double val) {
    if(nr_tranzactii_gratuite>0){
        try{
            if(val>sold)
                throw "\nRetragere respinsa:Fonduri insuficiente!\n";
            else
            {   nr_tranzactii_gratuite--;
                sold=sold-val;
            }
        }
        catch(const char* err){cout<<err;}
    } else
        try {
            double val_comision=comision_retragere*sold;
            if(val+val_comision>sold)
                throw "\nRetragere respinsa:Fonduri insuficiente!\n";
            else
                sold=sold-val-val_comision;
        }
        catch(const char* eroare){cout<<eroare;}
}

int Cont_Curent::get_tranzactii_gratuite() {
    return nr_tranzactii_gratuite;
}




