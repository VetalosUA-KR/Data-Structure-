#include <iostream>
#include "lista_laczona.h"

using namespace std;

int main()
{
    lista_laczona l1;

    ///K=2 sznur 9,9,9,4,4,4,4,5,4,7,7,1,1,2
    /**l1.addElement(9);
    l1.addElement(9);
    l1.addElement(9);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(5);
    l1.addElement(4);
    l1.addElement(7);
    l1.addElement(7);
    l1.addElement(1);
    l1.addElement(1);
    l1.addElement(2);*/

    //1,7,9,3,0,1,5,5,5,2,4,3,1,2,9,3,2,3 i N=2
    /*l1.addElement(1);
    l1.addElement(7);
    l1.addElement(9);
    l1.addElement(3);
    l1.addElement(0);
    l1.addElement(1);
    l1.addElement(5);
    l1.addElement(5);
    l1.addElement(5);
    l1.addElement(2);
    l1.addElement(4);
    l1.addElement(3);
    l1.addElement(1);
    l1.addElement(2);
    l1.addElement(9);
    l1.addElement(3);
    l1.addElement(2);
    l1.addElement(3);*/

    ///4,7,5,1,6,6,1,7,3,7,2,9,1,1,1
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

    /*l1.addElement(9);
    l1.addElement(7);
    l1.addElement(6);
    l1.addElement(5);
    l1.addElement(4);
    l1.addElement(3);
    l1.addElement(1);*/
    l1.wypisz();
    cout<<endl;
    l1.usunCiagi(2);
    l1.wypisz();
    return 0;
}






