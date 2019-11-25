#include <iostream>
#include "kolejka.h"

using namespace std;

int main()
{

    Kolejka k;

    int x;
    cout<<"liczba 999 koniec"<<endl;
    while(true)
    {
        cout<<"Podaj licbu -> ";
        cin>>x;
        if(x == 999) break;
        //if(x == 999) break;
        k.wstaw(x);
        k.wypisz();
    }


    int l;
    while(true)
    {
        try
        {
            l = k.zdejmi();
            cout<<"usunuli "<<l<<endl;
            cout<<"dlugosc tabeli = "<<k.rozmiarTablicy()<<endl;
            cout<<"zostalo: ";
            k.wypisz();
        }
        catch(exception &e)
        {
            cout<<e.what()<<endl;
            break;
        }

    }


    return 0;
}
