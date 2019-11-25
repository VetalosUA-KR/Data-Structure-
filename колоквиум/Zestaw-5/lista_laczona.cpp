
#include <iostream>
#include "lista_laczona.h"

using namespace std;
/**
if(K+1 > Size){return;}
    else
    {
        Node * previouse = head;
        for(int i = 1; i < K; i++)
        {
            previouse = previouse->next;
        }
        int index = K;
        while(previouse != nullptr)
        {
            if(index == K)
            {
                Node * current = previouse->next;
                while(current != nullptr && current->data%2 != 0)
                {
                    Node * toDel = current;
                    previouse->next = current->next;
                    delete toDel;
                    current = current->next;
                }
                index = 0;
            }
            else
            {
                previouse = previouse->next;
                index++;
            }
        }
    }
*/
void lista_laczona::usunFragmenty(int p)
{
    if(p+1 > size){return;}
    else
    {
        Node * previouse = head;
        for(int i = 0; i < p; i++)
        {
            Node * toDel = previouse;
            previouse = previouse->next;
            head = head->next;
            delete toDel;
        }
        int index = p;
        Node * help = previouse;
        while(previouse != nullptr)
        {
            if(index == p)
            {
                int ind = 0;
                while(previouse->next != nullptr && previouse->data < previouse->next->data)
                {
                    ind++;
                    previouse = previouse->next;
                }
                if(ind == 0)
                {
                    previouse = help;
                }
                index = 0;
                if(previouse->next == nullptr)
                {
                    break;
                }
            }
            else
            {
                Node * toDel = previouse->next;
                for(int i = 0; i < p && toDel != nullptr; i++)
                {
                    previouse->next = toDel->next;
                    delete toDel;
                    toDel = previouse->next;
                }
                help = previouse;
                previouse = previouse->next;
                index = p;
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


void lista_laczona::wypis()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}














