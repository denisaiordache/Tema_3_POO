#include <iostream>
#include "Cont.h"
#include "Cont_Economii.h"
#include "Cont_Curent.h"
//#include "Gestionare_Conturi.h"
#include <vector>
using namespace std;

void citire_afisare()
{
    int n,opt;
    vector<Cont*> obiecte;
    cout<<"Dati numarul de elemente citite:"<<" "; cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Alegeti tipul de cont pentru care oferiti informatii:"<<'\n'<<"1.Cont curent"<<'\n'<<"2.Cont de economii"<<'\n';
        cin>>opt;
        if(opt==1)
        {
            cout<<"Ati ales un cont curent. Introduceti informatiile:\n";
            Cont_Curent cont;
            cin>>cont;
            obiecte.push_back(new Cont_Curent(cont));

        } else
        {
            cout<<"Ati ales un cont de economii. Introduceti datele:\n";
            Cont_Economii cont_ec;
            cin>>cont_ec;
            obiecte.push_back(new Cont_Economii(cont_ec));

        }
    }

    for(int j=0;j<n;j++)
        cout<<*obiecte[j];
}


int main() {
    /*Cont_Curent ob;
    cin>>ob;
   ob.depunere(25.3);
   cout<<ob.getSold();
   ob.depunere(250.49);
   ob.retragere(3000);*/

    /*Cont_Economii ob1;
    cin>>ob1;
    Gestionare_Conturi<Cont_Economii>::afisare_cont(ob1);*/

    citire_afisare();


    return 0;
}
