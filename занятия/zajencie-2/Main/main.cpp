#include <iostream>
#include "bib_ulamek.h"
#include "bib_geometria.h"
#include "bib_macierza.h"

using namespace std;

int main()
{

    /*cout<<"podaj ilosc wierszuw i kolumn"<<endl;
    int w,k;
    cin>>w>>k;
    Macierz m1(w,k);
    m1.zapisz();
    m1.wypisz();*/



    ///  TESTOWANIE bib_geometria
    Punkt a1(1,3);
    Punkt a2(2,5);

    Prosta _prosta(2,1);
    _prosta.wypis();
    a1.wypis();
    cout<<_prosta.czyPunktLezeNaProstej(a1)<<endl;

    Prosta _prosta2;
    _prosta2 = _prosta2.prostaPrzez_2_punkty(a1,a2);
    _prosta2.wypis();

    /// TESTOWANIE ULAMKOW
    int a,b;
    cout<<"podaj licznik -> ";
    cin>>a;
    cout<<"podaj mian -> ";
    cin>>b;
    Ulamek x(a,b);
    Ulamek y (2,5);
    if(x == y)
    {
        cout<<"rowne";
    }
    else if(x > y) 2 > 4
    {
        x.wypisz();  cout<<" wieksze od "; y.wypisz();
    }
    else if (x < y)
    {
       // cout<<x.licz<<"/"<<x.mian<<" mniejsze od "<<y.licz<<"/"<<y.mian<<endl;
    }
    cout<<endl;
    Ulamek z;
    z = x / y;
    z.wypisz();
    cout<<endl;
    z.skroc();
    z.wypisz();*/

    return 0;
}
