#include <iostream>
#include "lista_laczona.h"

using namespace std;

int main()
{
    lista_laczona l1;

    /// 1,3,6,1,3,7,2,6,3,1,1
    /**l1.addElement(5);
    l1.addElement(5);
    l1.addElement(5);
    l1.addElement(5);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(2);
    l1.addElement(1);*/

    l1.addElement(9);
    l1.addElement(8);
    l1.addElement(7);
    l1.addElement(6);
    l1.addElement(5);
    l1.addElement(4);
    l1.addElement(3);
    l1.addElement(2);
    l1.addElement(1);
    l1.addElement(0);
    l1.wypisz();
    cout<<endl;
    l1.rozrzucSrodek(3);
    l1.wypisz();
    return 0;
}
