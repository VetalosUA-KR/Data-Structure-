#include"sznur.h"
#include <iostream>

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
    s.wypisz();

    return 0;
}
