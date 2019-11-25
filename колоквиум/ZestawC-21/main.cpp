#include <iostream>
#include "lista-lacona.h"

using namespace std;

int main()
{

    lista_lacona lista1;
    lista_lacona lista2;

    /// 4,7,5,1,6,6,7,1,4,2,9,1,1
    lista1.wstaw(4);
    lista1.wstaw(7);

    lista1.wstaw(5);
    lista1.wstaw(1);

    lista1.wstaw(6);
    lista1.wstaw(8);

    lista1.wstaw(7);
    lista1.wstaw(1);

    lista1.wstaw(4);
    lista1.wstaw(2);

    lista1.wstaw(9);
    lista1.wstaw(1);

    lista1.wstaw(1);

    lista1.wypisz();
    //lista1.usun(2);
    cout<<endl;
    lista1.test();
    //lista1.wypisz();
    /*lista1.wstaw(1);
    lista1.wstaw(2);

    lista1.wstaw(7);
    lista1.wstaw(7);

    lista1.wstaw(1);
    lista1.wstaw(3);

    lista1.wstaw(2);
    lista1.wstaw(4);

    lista1.wstaw(5);

    ///
    lista2.wstaw(3);
    lista2.wstaw(2);

    lista2.wstaw(3);
    lista2.wstaw(6);

    lista2.wstaw(3);
    lista2.wstaw(4);

    lista2.wstaw(8);
    lista2.wstaw(6);

    lista2.wstaw(5);
    lista2.wstaw(6);

    lista2.wstaw(2);*/

    //lista1.wymenPary(lista2);
   // lista1.test();

    /*lista.wstaw(3);
    lista.wstaw(6);
    lista.wstaw(6);

    lista.wstaw(4);
    lista.wstaw(7);
    lista.wstaw(5);

    lista.wstaw(7);
    lista.wstaw(3);
    lista.wstaw(2);

    lista.wstaw(9);
    lista.wstaw(7);
    lista.wstaw(7);

    lista.wstaw(4);
    lista.wstaw(2);*/


    return 0;
}
