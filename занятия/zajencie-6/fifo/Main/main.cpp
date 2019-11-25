#include <iostream>
#include "kolejka.h"

using namespace std;

int main()
{
    Kolejka k1;
    k1.add_Element(6);
    k1.add_Element(5);
    k1.add_Element(4);
    k1.add_Element(3);
    k1.add_Element(2);
    k1.add_Element(1);
    k1.wypisz();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //k1.przestawKawalekNaPoczatek(2,6);
    ///k1.odwzoruj();
    k1.przestawKawalekNaPoczatek(2,4);
    k1.wypisz();

    cout<<k1.getHead();
    cout<<k1.getTail();

    /*cout<<"size k1 = "<<k1.getSize()<<endl;
    Kolejka k2;
    k2 = k1;*/

    /*k2.add_Element(4);
    k2.add_Element(5);
    k2.add_Element(6);*/
    /*cout<<endl<<k1.getHead();
    cout<<endl<<k1.getTail();*/
    //cout<<"get last element -> "<<k1.getElement()<<endl;

    /*k2.wypisz();

    cout<<"size k2 = "<<k2.getSize()<<endl;
    cout<<"tail = "<<k2.getTail()<<endl;
    cout<<"head = "<<k2.getHead()<<endl;

    cout<<"czy kolejki rownowazne ?  -> "<<(k1==k2)<<" <-\t (1 - rownowazne \t 0 - nie)";*/


    return 0;
}
