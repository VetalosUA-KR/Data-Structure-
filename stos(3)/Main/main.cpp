#include <iostream>
#include "stosy-tab.h"

using namespace std;

int main()
{
    Stos st(3);

    cout<<"podaj liczby do stosu, 999 koniec";
    int x;
    while (true)
    {
        cout<<"podaj liczbe   ->  "; cin>>x;
        if (x == 999) break;
        try{
            st.wloz(x);
        }
        catch(exception&e){
            cout<<e.what();
            cout<<endl<<"Nie wlozylw liczby"<<endl;
            break;
        }
        st.wypisz();
    }
    int rez = 0;
    for(int i = 0; i < 3; i++)
    {
        rez += st.zdejmi();
    }
    cout<<"summa  =  "<<rez<<endl;

    return 0;
}
