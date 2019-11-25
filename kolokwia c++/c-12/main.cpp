#include <iostream>
#include"sznur.h"
using namespace std;

int main()
{
    Sznur s;
    int liczba;
    int m=3;
    int k=2;
    while(true)
    {
        cout<<"podaj liczbe 999 konczy: "; cin>>liczba;
        if(liczba==999) break;

        s.wstaw(liczba);
    }
    s.wypisz();
    cout<<endl;
    cout<<"podaj k: ";cin>>k;
    cout<<endl<<"podaj m: "; cin>>m;
    s.usun(k,m);
    s.wypisz();
    return 0;
}
