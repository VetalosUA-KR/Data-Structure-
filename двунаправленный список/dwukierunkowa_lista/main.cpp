#include <iostream>
#include "dwukierunkowa_lista.h"

using namespace std;

int main()
{
    dwukierunkowa_lista d1;
    d1.addElement(7);
    d1.addElement(5);
    d1.addElement(6);
    d1.addElement(9);
    d1.addElement(4);
    d1.addElement(8);
    d1.addElement(1);
    d1.addElement(3);
    d1.addElement(2);
    d1.wypiszZPoczatka();
    cout<<endl;
    d1.addToIndex(2, 100);
    d1.addToIndex(2, 99);
    //d1.deleToIndex(0);
    /*d1.deleToIndex(1);
    d1.deleToIndex(1);
    d1.deleToIndex(1);*/
    //d1.wypiszZPoczatka();
    d1.wypiszZKonca();
    return 0;
}
