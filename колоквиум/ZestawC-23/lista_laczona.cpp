#include <iostream>
#include "lista_laczona.h"

using namespace std;


void lista_laczona::rozrzucPary(int n)
{

}


void lista_laczona::usun()
{
    if(size < 3){return;}
    else
    {
        Node * previouse = nullptr;
        Node * first = head;
        Node * seconde = first->next;
        Node * three = seconde->next;
        while(true)
        {
            if(first->data - seconde->data == 1)
            {
                if(previouse == nullptr)
                {
                    head = head->next;
                    delete first;
                }
                else
                {
                    previouse->next = seconde;
                    delete first;
                }
                previouse = three;
            }
            else
            {
                if(previouse == nullptr)
                {
                    head = head->next;
                    seconde->next = three->next;
                    delete first;
                    delete three;
                }
                else
                {
                    previouse->next = seconde;
                    seconde->next = three->next;
                    delete first;
                    delete three;
                }
                previouse = seconde;
            }
            if(three->next != nullptr && three->next->next != nullptr && three->next->next->next != nullptr)
            {
                first = three->next;
                seconde = first->next;
                three = seconde->next;
            }
            else{return;}
        }
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

void lista_laczona::addElement(int d)
{
    Node * newElement = new Node(d);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        if(head->data <= d)
        {
            newElement->next = head;
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
    }
    size++;
}
