#include <iostream>
#include "bib_osoba.h"

using namespace std;

/* GRUPA */
/*Grupa::Grupa(int _ileOsob)
{
    ilosOsob = _ileOsob;
    Osoba listOsob[30];
}*/

void Grupa::wypiszZaMisecem(int mes[])
{
    for(int i = 0; i < ilosOsob; i++)
    {
        if (listOsob[i].pesel[2] == mes[0]&& listOsob[i].pesel[3] == mes[1])
        {
            listOsob[i].wypisz();
        }
    }
}

void Grupa::wypiszGrupe()
{
    for(int i = 0; i < ilosOsob; i++)
    {
        listOsob[i].wypisz();
    }
}

bool Grupa::CzyJestMezczyzna ()
{
    for(int i = 0; i < ilosOsob; i++)
    {
        if(listOsob[i].pesel[9] % 2 == 0) return true;
    }
    return false;
}

/* OSOBA */

Osoba::Osoba(string im, string naz, string pes, int wz)
{
    imie = im;
    nazwisko = naz;
    wzrost = wz;
    for(int i = 0; i < 11; i++)
    {
        //pesel[i] = int(pes[i]);
        pesel[i] = pes[i]-'0';
    }
    //cout<<"Skonstruktowalem osobe"<<endl;
}

void Osoba::wypisz()
{
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<"nr PESEL: ";
    for(int i = 0; i < 11; i++)
    {
        cout<<pesel[i];
    }
    cout<<endl;
    cout<<"wzrost: "<<wzrost<<endl<<endl;

}

void Osoba::zmienWzrost(int nowyWzrost)
{
    wzrost = nowyWzrost;
}
void Osoba::zmienNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}








