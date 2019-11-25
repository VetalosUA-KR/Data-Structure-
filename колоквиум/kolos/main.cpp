#include <iostream>
#include "lista_laczona.h"


using namespace std;

int main()
{
    lista_laczona l1;
    l1.addElement(9);
    l1.addElement(7);
    l1.addElement(6);
    l1.addElement(6);
    l1.addElement(6);
    l1.addElement(6);
    l1.addElement(5);
    l1.addElement(3);
    l1.addElement(3);
    l1.addElement(1);


    l1.wypisz();
    cout<<endl;
    l1.usun(1);
    l1.wypisz();
    return 0;
}
