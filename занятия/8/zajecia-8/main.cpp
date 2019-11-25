#include <iostream>
#include "spis_towar.h"

using namespace std;

int main()
{
    spis_tow st;
    int i = 0;
    int a;
    float b;

    while(i < 4)
    {
        cout<<"podaj kod towaru -> ";
        cin>>a;
        cout<<"podaj ilosc towaru -> ";
        cin>>b;
        Towar x(a,b);
        i++;
        st.vstaw(x);
        st.wypisz();
        cout<<endl<<"****************"<<endl;
    }
    int k;
    float ile;
    cout<<"podaj kod towaru dla zdejmowania -> ";
    cin>>k;
    cout<<"podaj ile towaru bede zdejmowane -> ";
    cin>>ile;
    st.zdejmiZaKodem(k, ile);
    //st.skompresuj();
    //st.wypisz();
    return 0;
}
