#include <iostream>
#include "lista_laczona.h"

using namespace std;


void lista_laczona::usunNadmiarowe(int n)
{
    Node * previouse = head;
    while(previouse != nullptr)
    {
        Node * predCurrent = previouse;
        Node * current = previouse->next;
        int counter = 1;
        while(current != nullptr)
        {
            if(previouse->data == current->data)
            {
                if(counter >= n)
                {
                    Node * toDel = current;
                    predCurrent->next = current->next;
                    delete toDel;
                }
                else
                {
                    counter++;
                }
            }
            predCurrent = current;
            current = current->next;
        }
        previouse = previouse->next;
    }
}


void lista_laczona::usunStaleCiagi(int m)
{
    if(size <= m*2){return;}
    else
    {
        Node * previouse = head;
        for(int i = 1; i < m; i++)
        {
            previouse = previouse->next;
        }
        int index = m;
        while(previouse != nullptr)
        {
            if(index == m)
            {
                Node * current = previouse->next;
                int d = current->data;
                int couter = 0;
                while(current != nullptr && current->data == d)
                {
                    couter++;
                    current = current->next;
                }
                if(couter >= m)
                {
                    Node * tmp = previouse->next;
                    while(tmp != current)
                    {
                        Node * toDel = tmp;
                        tmp = tmp->next;
                        delete toDel;
                    }
                    previouse->next = current;
                }
                previouse = current;

                index = 1;
            }
            else
            {
                previouse = previouse->next;
                index++;
            }
        }
    }
}

void lista_laczona::addElement(int d)
{
    Node * newElement = new Node (d);
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
