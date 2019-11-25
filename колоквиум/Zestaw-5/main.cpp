#include <iostream>
#include "lista_laczona.h"

using namespace std;

int main()
{
    lista_laczona l1;
    l1.addElement(4);
    l1.addElement(7);
    l1.addElement(5);
    l1.addElement(1);
    l1.addElement(6);
    l1.addElement(6);
    l1.addElement(1);
    l1.addElement(7);
    l1.addElement(7);
    l1.addElement(3);
    l1.addElement(2);
    l1.addElement(1);
    l1.addElement(2);
    l1.addElement(3);
    l1.addElement(1);

    l1.wypis();
    cout<<endl;
    l1.usunFragmenty(3);
    cout<<endl;
    l1.wypis();


    return 0;
}
