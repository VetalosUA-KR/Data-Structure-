#include <iostream>
#include "lista_laczona.h"

using namespace std;

void lista_laczona::addElement(int d)
{
   Node * newElement = new Node(d);
   if(head == nullptr)
   {
       head = newElement;
   }
   else
   {
       if(d >= head->data)
       {
           newElement->next =  head;
           head = newElement;
       }
       else
       {
           Node * tmp = head;
           while(tmp->next != nullptr && tmp->next->data >= d)
           {
               tmp = tmp->next;
           }
           newElement->next = tmp->next;
           tmp->next = newElement;
       }
       size++;
   }
}

void lista_laczona::wypisz()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}


void lista_laczona::usun(int k)
{
    if(size < 2){return;}
    Node * previouse = nullptr;
    Node * succ = head;
    while(succ != nullptr)
    {
        Node * begin = succ;
        Node * end = begin;
        Node * after = begin->next;
        int counter = 1;
        while(after != nullptr && end->data == after->data+1)
        {
            end = after;
            after = after->next;
            counter++;
        }

        if(counter > 1)
        {
            if(!previouse)
            {
                head = after;
            }
            else
            {
                previouse->next = after;
            }
            succ = after;
            end->next = nullptr;
            while(begin != nullptr)
            {
                Node * toDel = begin;
                begin = begin->next;
                delete toDel;
                size--;
            }
        }

        for(counter = 0; counter < k && succ != nullptr; counter++)
        {
            previouse = succ;
            succ = succ->next;
        }
    }
}


















