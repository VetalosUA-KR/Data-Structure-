#include <iostream>
#include <string>
#include <fstream>
//#include "bib_nip.h"
#include "lista_nip.h"
#include <cstdlib>





void lista_nip::wstaw(NIP data)
{
    Node * newElement = new Node (data);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        Node * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newElement;
    }
}

NIP lista_nip::zdejmi()
{
    if(head != nullptr)
    {
        NIP current = head->data;
        head = head->next;
        return current;
    }
    else
    {

        throw logic_error("brak elementow");
    }
}











