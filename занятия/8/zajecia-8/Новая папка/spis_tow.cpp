#include "spis_tow.h"
#include <iostream>

using namespace std;

void spis_tow::vstaw(Towar t)
{
    Node * newTow = new Node(t);
    if(pocz == nullptr)
    {
        pocz = newTow;
    }
    else if()//
    {
        Node * tmp = pocz;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newTow;
    }
}

void spis_tow::wypisz()
{
    Node * tmp = pocz;
    while(tmp != nullptr)
    {
        cout<<"kod towaru = "<<tmp->dane.getKod()<<"\t"<<"ilosc towaru = "<< tmp->dane.getIlosc();
        tmp = tmp->next;
    }
}
