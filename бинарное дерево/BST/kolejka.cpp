#include <iostream>
#include "kolejka.h"

using namespace std;

void kolejka::addElement(/**binary_tree.Node * bn*/)
{
    KolejkaNode * newElement = new KolejkaNode(/**bn*/);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        KolejkaNode * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newElement;
    }
}

void kolejka::pop()
{
    KolejkaNode * toDelete = head;
    head = head->next;
    delete toDelete;
}






