#include <iostream>
#include "lista_laczona.h"

using namespace std;

lista_laczona::~lista_laczona()
{
    while(head != nullptr)
    {
        Node * toDel = head;
        head = head->next;
        delete toDel;
        size--;
    }
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
            newElem->next = head;
            head = newElem;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->data >= d)
            {
                tmp = tmp->next;
            }
            newElem->next = tmp->next;
            tmp->next = newElem;
        }
    }
    size++;
}


void lista_laczona::usun2()
{
    if(size < 2){return;}
    else
    {
        Node * previouseToDelete = nullptr;
        Node * lastToDelete = nullptr;
        Node * first = head;
        while(first->next != nullptr)
        {
            if((first->data - first->next->data) == 1)
            {
                if(first == head)
                {
                    Node * toDelete = first;
                    head = head->next;
                    first = first->next;
                    delete toDelete;
                }
                else
                {
                    Node * toDelete = first;
                    previouseToDelete = first;
                    first = first->next;
                    delete toDelete;
                }
                lastToDelete = first;
            }
            else
            {
                if(lastToDelete != nullptr)
                {
                    lastToDelete->next = nullptr;
                }
            }
        }
    }
}


///Удаление - разбить на тройки, если в тройке среднее значение первого и последнего элемента равно второму, удалить второй, иначе удалить все тройку
void lista_laczona::usun1()
{
    if(size < 3){return;}
    else
    {
        Node * previouseFirst = nullptr;
        Node * first = head;

        while(first != nullptr && first->next != nullptr && first->next->next != nullptr)
        {
            Node * seconde = first->next;
            Node * three = seconde->next;
            if((first->data+three->data)/2.0 == seconde->data)
            {
                first->next = three;
                seconde->next = nullptr;
                delete seconde;
                previouseFirst = three;
                first = three->next;
            }
            else
            {
                Node * tmp = first;
                first = three->next;
                if(previouseFirst == nullptr)
                {
                    head = first;
                }
                else
                {
                    previouseFirst->next = first;
                }

                delete tmp;
                delete seconde;
                delete three;

            }

        }
    }
}





















