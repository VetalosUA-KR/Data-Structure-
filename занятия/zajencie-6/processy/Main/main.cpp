#include <iostream>
#include "process.h"
#include "list_proces.h"
using namespace std;

int main()
{
    list_proces new_list;
    new_list.addElement(1);
    new_list.addElement(2);
    new_list.addElement(3);
    new_list.addElement(4);
    new_list.addElement(5);
    new_list.addElement(6);
    new_list.addElement(7);
    new_list.wypisz();
    cout<<"head = "<<new_list.getHead()<<endl;
    new_list.pszestawNaPaczatek(4);
    new_list.wypisz();

    return 0;
}
