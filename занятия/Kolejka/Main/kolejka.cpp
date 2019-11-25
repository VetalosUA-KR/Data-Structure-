
#include <iostream>
#include "kolejka.h"

using namespace std;
Kolejka::Kolejka()
{
    ileJest = 0;
    dane = NULL;
}

Kolejka::~Kolejka()
{
    if(ileJest > 0)
    {
        cout<<"dane jest udalili "<<endl;
        delete [] dane;
    }
}

int Kolejka::rozmiarTablicy()
{
    return ileJest;
}


int Kolejka::zdejmi()
{

    if(ileJest > 0)
    {
        int wyn;
        int * nowa;
        nowa = new int [ileJest-1];
        wyn = dane[0];
        for(int i = 1; i < ileJest; i++)
        {
            nowa[i-1] = dane[i];
        }
        delete [] dane;
        dane = nowa;
        ileJest--;
        return wyn;
    }
    else
    {
        throw runtime_error("kolejka pusta");
    }
}

void Kolejka::wstaw(int a)
{
    int * nowa;
    try {nowa = new int [ileJest+1];}
    catch(exception &e){throw runtime_error("brak pamieci");}
    for(int i = 0 ; i < ileJest; i++)
    {
        nowa[i] = dane[i];
    }
    nowa[ileJest] = a;
    //kasyjemy stara tablice
    delete [] dane;
    //podpinamy nowa
    dane = nowa;
    ileJest++;

}

void Kolejka::wypisz()
{
    for(int i = 0; i < ileJest; i++)
    {
        cout<<dane[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}












