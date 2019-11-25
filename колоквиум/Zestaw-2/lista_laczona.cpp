#include <iostream>
#include "lista_laczona.h"

using namespace std;

void lista_laczona::wypisz()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

void lista_laczona::addElement(int d)
{
    Node * newElem = new Node(d);
    if(head == nullptr)
    {
        head = newElem;
    }
    else
    {
        if(d >= head->data)
        {
            Node * n = head;
            head = newElem;
            newElem->next = n;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next!= nullptr && tmp->next->data >= d)
            {
                tmp = tmp->next;
            }
            newElem->next = tmp->next;
            tmp->next = newElem;
        }
    }
    Size++;
}

void lista_laczona::usun()
{

    if(Size < 4)
    {
        return;
    }
    else
    {
        Node * PreviouseFirst = nullptr;
        Node * first = head;
        Node * seconde = first->next;
        Node * three = seconde->next;
        Node * four = three->next;
        while(true)
        {
            if(first->data+four->data == seconde->data+three->data)
            {
                Node * tmp = first;
                first = four->next;
                if(PreviouseFirst)
                {
                    PreviouseFirst->next = first;
                }
                else
                    {head = first;}
                for(int i = 0; i < 4; i++)
                {
                    Node * toDelete = tmp;
                    tmp = tmp->next;
                    delete toDelete;
                    Size--;
                }
                if(first != nullptr && first->next != nullptr && first->next->next != nullptr && first->next->next->next != nullptr)
                {
                    //first = four->next;
                    seconde = first->next;
                    three = seconde->next;
                    four = three->next;
                }
                else{return;}
            }
            else
            {
                Node * toDelete = first;
                if(PreviouseFirst)
                {
                    PreviouseFirst->next = seconde;
                }
                else
                    {head = head->next;}

                delete toDelete;

                toDelete = four;
                three->next = four->next;
                delete toDelete;
                Size -= 2;

                if(three->next != nullptr && three->next->next != nullptr && three->next->next->next != nullptr && three->next->next->next->next != nullptr)
                {
                    PreviouseFirst = three;
                    first = three->next;
                    seconde = first->next;
                    three = seconde->next;
                    four = three->next;
                }
                else {return;}
            }
        }
    }
}

void lista_laczona::przenies()
{
   Node * last = head;
   while(last->next != nullptr)
   {
       last = last->next;
   }

   Node * previouseFirst = head;
   Node * first = head;
   Node * seconde = head->next;
   if(first->data == seconde->data)
   {
        if(first == head)
        {
            head = seconde->next;
            last->next = first;
            seconde->next = nullptr;
        }
        else
        {
            seconde->next = last->next;
        }
   }
}













