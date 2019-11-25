
#include <stdexcept>
#include "stosy-tab.h"
#include <iostream>

using namespace std;
Stos::Stos(int mrs)
{
    cout<<"create construktor"<<endl;
    if(mrs <= 0) throw invalid_argument("blad");
    max_rozmiar_stosu = mrs;
    dane = new int[mrs];
    ileJest = 0;
}

Stos::~Stos()
{
    cout<<"called destructor"<<endl;
    delete [] dane;
}

void Stos::wypisz()
{
    for(int i = ileJest-1; i >= 0; i--)
    {
        cout<<i<<" element stosu = "<<dane[i]<<endl;
    }
}

void Stos::wloz(int a)
{
    if (ileJest == max_rozmiar_stosu) throw runtime_error("stos pelny");
    dane[ileJest] = a;
    ileJest++;
}

int Stos::zdejmi()
{
    if(ileJest == 0) throw runtime_error("stos pusty");
    ileJest --;
    return dane[ileJest];
}

int Stos::rozmiarStosu()
{
    return ileJest;
}





