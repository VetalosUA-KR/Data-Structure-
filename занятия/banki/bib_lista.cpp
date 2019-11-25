#include <iostream>
#include <string>
#include "bib_IBAN.h"
#include "bib_lista.h"
#include <cstdlib>


void lista::wstaw(IBAN ib)
{
    Node * newElement = new Node(ib);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        if(head->dane < ib)
        {
            newElement->next = head;
            head = newElement;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->dane > ib)
            {
                tmp = tmp->next;
            }
            newElement->next = tmp->next;
            tmp->next = newElement;
        }
    }
}


void lista::wypisz()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->dane.getNumerKonta()<<endl;
        tmp = tmp->next;
    }
}

IBAN lista::zdejmiPierwszy()
{
    if(head != nullptr)
    {
        Node * killer = head;
        head = head->next;
        return killer->dane;
    }
    else
    {
        throw logic_error("lista jest pusta");
    }
}

