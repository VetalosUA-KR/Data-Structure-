#include <iostream>
#include "Stos.h"

using namespace std;

int main()
{
    Stos s1;
    s1.wloz(1);
    s1.wloz(2);
    s1.wloz(3);
    s1.wloz(4);
    s1.wloz(5);

    s1.wypisz();
    cout<<endl;
    cout<<endl;
    s1.wlozDoSrodku(1111, 0);
    s1.wypisz();
    /*cout<<endl;
    cout<<endl;
    cout<<"Head 1 -> "<<s1.getHead()->data<<endl;
    cout<<"Hwost 1 -> "<<s1.getTail()->data<<endl;

    cout<<endl;

    Stos s2 = s1;
    s2.wloz(4);
    s2.wypisz();
    cout<<"Head 2 -> "<<s2.getHead()->data<<endl;
    cout<<"Hwost 2 -> "<<s2.getTail()->data<<endl;*/

    return 0;
}
