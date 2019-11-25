#include <iostream>
#include "list_sort.h"

using namespace std;

int main()
{
    list_sort l1;
    l1.addELement(2);
    l1.addELement(3);
    l1.addELement(5);
    l1.addELement(5);
    l1.addELement(4);
    l1.addELement(4);
    l1.addELement(1);
    l1.addELement(1);
    l1.wypisz();
    cout<<endl;
    l1.deletWszystkieElement(5);
    cout<<endl;
    l1.wypisz();
    return 0;
}
