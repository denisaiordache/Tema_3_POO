//
// Created by denys on 09.05.2020.
//

#ifndef TEMA_3_POO_CONT_CURENT_H
#define TEMA_3_POO_CONT_CURENT_H
#include "Cont.h"


class Cont_Curent:public Cont {
protected:
    int nr_tranzactii_gratuite;
    double comision_retragere;
public:
    Cont_Curent();
    Cont_Curent(string &det, string &d, double s, int &nr_t, double &com);
    ~Cont_Curent() override=default;
    Cont_Curent(const Cont_Curent &cc);
    Cont_Curent& operator = (const Cont_Curent& cc);
    friend istream &operator >> (istream &in, Cont_Curent &cc);
    friend ostream &operator << (ostream &out, Cont_Curent &cc);
    void afis() override;
    void depunere(double val);
    void retragere(double val);
    int get_tranzactii_gratuite();


};


#endif //TEMA_3_POO_CONT_CURENT_H
