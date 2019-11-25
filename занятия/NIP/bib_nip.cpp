#include <iostream>
#include <string>
#include <fstream>
#include "bib_nip.h"
//#include "lista_nip.h"
#include <cstdlib>

using namespace std;

string zdejmiPodatek(NIP _nip)
{
    string urzad = _nip.getNIP().substr(0,3);
    return urzad;
}

/// 6, 5, 7, 2, 3, 4, 5, 6, 7.
bool cyfraKontroli(NIP _nip)
{
    int wagi[9] = {6, 5, 7, 2, 3, 4, 5, 6, 7};
    string n = _nip.getNIP().substr(0,9);

    string ostatniaCyfra = _nip.getNIP().substr(9,1);

    int wynik = 0;
    for(int i = 0; i < 9; i++)
    {
        wynik+= (n[i]-'0')*wagi[i];
    }
    if((wynik%11) == ostatniaCyfra[0]-'0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

