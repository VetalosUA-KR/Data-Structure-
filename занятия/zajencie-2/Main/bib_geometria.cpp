#include<iostream>
#include "bib_geometria.h"

using namespace std;

///     Prosta

Prosta::Prosta(int _a, int _b)
{
    if(_a == 0) a = 1;
    else a = _a;
    b = _b;
}

/*Prosta::Prosta()
{
    _a = 1;
    _b = 0;
}*/

bool Prosta::czyPunktLezeNaProstej(Punkt p1)
{
    if(p1.y == (a*p1.x+b))
    {
        return true;
    }
    else return false;
}

Prosta Prosta::prostaPrzez_2_punkty(Punkt p1, Punkt p2)
{
    Prosta wyn(p2.y - p1.y, p2.x - p1.x);
    return wyn;
}

void Prosta::wypis()
{
    cout<<"y = "<<a<<" * x + "<<b<<endl;
}


///     Punkt

Punkt::Punkt(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Punkt::wypis()
{
    cout<<"wspolrzedna x = "<<x<<endl;
    cout<<"wspolrzedna y = "<<y<<endl;
}









