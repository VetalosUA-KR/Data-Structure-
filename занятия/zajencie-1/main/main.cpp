#include <iostream>
#include "bib_osoba.h"
#include "bib_grupa.h"

//parzysta to kobieta
//nieparzysta to mezczyzna

using namespace std;

int main ()
{


    /* kolega;

    kolega.wzrost = 176;

    kolega.wypisz();

    Osoba kolerzanka("Eva", "Rogowska", "12345678910", 20);

    kolerzanka.wypisz();*/

    Grupa gr;
    //gr.wypiszGrupe();
    int m[2] = {0,8};
    gr.wypiszZaMisecem(m);
    //cout<<"CzyJestMezczyzna "<<gr.CzyJestMezczyzna();

    return 0;
}
