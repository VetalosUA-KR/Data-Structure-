#include <iostream>
#include "lista_laczona.h"

using namespace std;

int main()
{
    lista_laczona l1;

    /// 4,7,5,1,6,6,1,7,7,7,2,9,1,1,1,1,1
    l1.addElement(8);
    l1.addElement(7);
    l1.addElement(6);
    l1.addElement(5);
    l1.addElement(3);
    l1.addElement(3);
    l1.addElement(3);
    l1.addElement(2);
    l1.addElement(1);
    l1.addElement(1);
    l1.addElement(1);
    l1.addElement(1);

    l1.wypisz();
    cout<<endl;
    l1.usunStaleCiagi(2);
    l1.wypisz();

    return 0;
}
