#include <iostream>
#include "dwukierunkowa_lista.h"

using namespace std;

/// Добавляет элемент
void dwukierunkowa_lista::addElement(int d)
{
    ///Обычное добавление
    /*Node * newElem = new Node(d);
    if(head == nullptr)
    {
        head = newElem;
        last = newElem;
    }
    else
    {
        Node * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newElem;
        newElem->previouse = tmp;
        last = newElem;
    }
    size++;*/

    ///Добавление с сортировкой
    Node * newElement = new Node(d);
    if(head == nullptr)
    {
        head = newElement;
        last = newElement;
    }
    else
    {
        if(head->data >= d)
        {
            Node * target = head;
            newElement->next = head;
            head = newElement;
            if(last == nullptr)
            {
                last = newElement->next;
            }
            else
            {
                target->previouse = newElement;
            }
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->data <= d)
            {
                tmp = tmp->next;
            }
            if(tmp == last)
            {
                last->next = newElement;
                newElement->previouse = last;
                last = newElement;
            }
            else
            {
                newElement->next = tmp->next;
                newElement->previouse = tmp;
                tmp->next->previouse = newElement;
                tmp->next = newElement;
            }
        }
    }
    size++;
}

void dwukierunkowa_lista::deleToIndex(int index)
{
    if(head == nullptr || size == 0) {return;}
    Node * tmp = head;
    int currentIndex = 1;
    while(tmp != nullptr && index != currentIndex)
    {
        tmp = tmp->next;
        currentIndex++;
    }
    if(tmp == head)
    {
        head = head->next;
        tmp->next->previouse = nullptr;
    }
    else if(tmp == last)
    {
        last = tmp->previouse;
        tmp->previouse->next = nullptr;
    }
    else
    {
        tmp->previouse->next = tmp->next;
        tmp->next->previouse = tmp->previouse;
    }
    size--;
}

/// Добавляет элемент на указанный индекс
void dwukierunkowa_lista::addToIndex(int index, int data)
{
    Node * newElement = new Node(data);
    Node * tmp = head;
    int currentIndex = 1;
    while(tmp != nullptr && currentIndex != index)
    {
        tmp = tmp->next;
        currentIndex++;
    }
    if(tmp == head)
    {
    }
    else if(tmp == last)
    {

    }
    else
    {
        newElement->next = tmp;
        newElement->previouse = tmp->previouse;
        tmp->previouse->next = newElement;
        tmp->previouse = newElement;
    }
}

void dwukierunkowa_lista::wypiszZPoczatka()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

void dwukierunkowa_lista::wypiszZKonca()
{
    Node * tmp = last;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->previouse;
    }
}






