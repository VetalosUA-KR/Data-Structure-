#include <iostream>
#include"sznur.h"
using namespace std;

int main()
{
    int a;
    Sznur s;
    while(true)
    {
        cout<<"podaj liczbe 999konczy";
        cin>>a;
        if(a==999)break;
        s.wstaw(a);
        cout<<endl;
    }
    s.wypisz();
    cout<<endl;
    s.usun();
   // cout<<"zdjalem"<<s.usun()<<endl;
    s.wypisz();

    return 0;
}
