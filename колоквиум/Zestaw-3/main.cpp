#include <iostream>
#include "lista_laczona.h"

using namespace std;

int main()
{
    lista_laczona l1;

    ///1,5,6,1,3,7,2,7,3,1,3,1
    l1.addElement(1);
    l1.addElement(5);
    l1.addElement(6);
    l1.addElement(1);
    l1.addElement(3);
    l1.addElement(7);
    l1.addElement(2);
    l1.addElement(7);
    l1.addElement(3);
    l1.addElement(1);
    l1.addElement(3);
    l1.addElement(1);
    l1.wypisz();
    return 0;
}
