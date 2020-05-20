//
// Created by denys on 10.05.2020.
//

#ifndef TEMA_3_POO_GESTIONARE_CONTURI_H
#define TEMA_3_POO_GESTIONARE_CONTURI_H
#include <iostream>
#include "Cont_Curent.h"
#include "Cont_Economii.h"
#include <unordered_map>
#include <vector>

template<class T>class Gestionare_Conturi{
protected:
    static int index_cont;
    vector <T> conturi;
    unordered_map<int, vector<string>> operatiuni;
public:
    Gestionare_Conturi();
    ~Gestionare_Conturi();
    Gestionare_Conturi& operator +=(const T& cont);
    void depunere(int id_cont, double suma);


};
template<> int Gestionare_Conturi<class T>::index_cont=0;

template<class T>
Gestionare_Conturi<T>::Gestionare_Conturi() {
    index_cont++;
}

template<class T>
Gestionare_Conturi<T>::~Gestionare_Conturi() {
    index_cont--;

}

template<class T>
Gestionare_Conturi<T> & Gestionare_Conturi<T>::operator+=(const T &cont) {
    conturi.push_back(cont);
    index_cont++;
}

template<class T>
void Gestionare_Conturi<T>::depunere(int id_cont, double suma) {
    conturi[id_cont].depunere(suma);
    operatiuni[id_cont].push_back("depunere");
}


template<>
class Gestionare_Conturi<Cont_Economii>{
public:
    static void afisare_cont(Cont_Economii &c){if(c.get_nr_luni()==12)
            cout<<c;}

};






#endif //TEMA_3_POO_GESTIONARE_CONTURI_H
