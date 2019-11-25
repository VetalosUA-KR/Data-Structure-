#include <iostream>
#include "lista_laczona.h"

using namespace std;

///Удаление - разбить на тройки, если в тройке среднее значение первого и последнего элемента равно второму, удалить второй, иначе удалить все тройку


int main()
{
    lista_laczona l1;
    l1.addElement(7);
    l1.addElement(6);
    l1.addElement(6);
    l1.addElement(3);
    l1.addElement(3);
    l1.addElement(3);
    l1.addElement(2);
    l1.addElement(1);
    l1.addElement(1);
    l1.addElement(1);
    l1.addElement(1);
    l1.wypis();
    cout<<endl;
    l1.usun1();
    l1.wypis();
    return 0;
}
