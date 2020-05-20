//
// Created by denys on 08.05.2020.
//

#ifndef TEMA_3_POO_CONT_H
#define TEMA_3_POO_CONT_H
#include <string>
#include <iostream>
using namespace std;


class Cont {
protected:
    string detinator;
    string data;
    double sold;
    static int nr_conturi;
public:
    Cont();
    Cont(string &det, string &d, double s);
    Cont(const Cont &c);
    Cont& operator = (const Cont& c);
    virtual ~Cont()= default;
    friend istream &operator >> (istream &in, Cont &c);
    friend ostream &operator << (ostream &out, const Cont &c);
    virtual void afis()=0;
    double getSold();



};


#endif //TEMA_3_POO_CONT_H
