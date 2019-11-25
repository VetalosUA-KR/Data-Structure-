#include <iostream>
#include "lista_laczona.h"

using namespace std;


void lista_laczona::usunPlus(int k)
{
    if(size <= 2){return;}
    else
    {
        Node * previouse = nullptr;
        Node * first = head;
        while(first != nullptr && first->next;)
        {
            Node * seconde = first->next;

            if(first->data == seconde->data)
            {
                ///************
                if(seconde->next != nullptr && seconde->next->next != nullptr && seconde->next->next->next != nullptr)
                {
                    if(previouse == nullptr)
                    {
                        head = seconde->next->next->next->next;
                        delete first;
                        delete seconde;
                        delete seconde->next;
                        delete seconde->next->next;
                        delete seconde->next->next->next;
                        first = head;
                    }
                    else
                    {
                        previouse->next = seconde->next->next->next->next;
                        delete first;
                        delete seconde;
                        delete seconde->next;
                        delete seconde->next->next;
                        delete seconde->next->next->next;
                        first = previouse->next;
                    }
                }
                else
                {
                    previouse = seconde;
                    first = seconde->next;
                }
            }

            /*if(seconde->next != nullptr && seconde->next->next != nullptr)
            {
                previouse = seconde;
                first = seconde->next;
                seconde = first->next;
            }
            else
            {
                return;
            }*/
        }
    }
}


void lista_laczona::addElement(int data)
{
    Node * newElement = new Node (data);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        if(head->data <= data)
        {
            newElement->next = head;
            head = newElement;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->data >= data)
            {
                tmp = tmp->next;
            }
            newElement->next = tmp->next;
            tmp->next = newElement;
        }
    }
    size++;
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





