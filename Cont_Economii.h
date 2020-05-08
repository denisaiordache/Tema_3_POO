//
// Created by denys on 08.05.2020.
//

#ifndef TEMA_3_POO_CONT_ECONOMII_H
#define TEMA_3_POO_CONT_ECONOMII_H
#include "Cont.h"
#include <string>


class Cont_Economii:public Cont {
protected:
    double rata_dobanda;
    int nr_luni;
    string istoric;
public:
    Cont_Economii();
    Cont_Economii(string &det, string &d, double s, double &r, int &n, string &ist);
    ~Cont_Economii() override =default;
    Cont_Economii(const Cont_Economii &c);
    Cont_Economii& operator = (const Cont_Economii& c);
    friend istream &operator >> (istream &in, Cont_Economii &c);
    friend ostream &operator << (ostream &out, const Cont_Economii &c);




};


#endif //TEMA_3_POO_CONT_ECONOMII_H
