#include "Stos.h"
#include <iostream>

using namespace std;

Stos::~Stos()
{
    Node * kiler;
    while(head != nullptr)
    {
        kiler = head;
        head = head->next;
        delete kiler;
        Size --;
    }
}

void Stos::wypisz()
{
    Node * current = head;
    while(current != nullptr)
    {
        cout<<current->data<<"\t <==> "<<current->next<<endl;
        current = current->next;
    }
}

void Stos::wloz(int a)
{
    Node * nowy;
    try
    {
        nowy = new Node(a);
    }
    catch(exception&e)
    {
        throw runtime_error("brak pamieci");
    }
    if(head == nullptr) tail = nowy;
    nowy->next = head;

    head = nowy;
    Size++;
}

void Stos::wlozDoSrodku(int data, int index)
{
    if(index == 0) wloz(data);
    else if(index <= Size)
    {
        Node * current = head;
        for(int i = 0; i < index-1; i++)
        {
            current = current->next;
        }
        current->next = new Node(data, current->next);
        Size++;
    }
    else throw runtime_error("wyszedl za ramki listy!");

  /*  Node * current = head;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current = new Node(data, current->next);
*/
}

void Stos::usunZSrodku(int index)
{
    if(index == 0)
    {
        zdejmi();
    }
    else if(index < Size)
    {
        Node * current = head;
        for(int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        cout<<current->data<<endl;
        Node * toDelet = current->next;
        current->next = toDelet->next;
        delete toDelet;
        Size--;

        /// Node * current = head;
    }
    else
    {
        throw runtime_error("nemozno usunac elemtn z wiekszym indeksom od rozmiaru stosu!");
    }
}

int Stos::zdejmi()
{
    if(Size == 0)
        throw runtime_error("brak elementow");
    int val = head->data;
    Node * tmp = head;
    head = tmp->next;
    delete tmp;
    Size --;
    return val;

}

int Stos::getSize()
{
    return Size;
}

bool Stos::operator==(Stos &s)
{
    Node * current1 = head;
    Node * current2 = s.head;

    if(Size != s.getSize())
        throw runtime_error("rozna dlugosc stosow");
    while(current1 != nullptr)
    {
        if(current1->data != current2->data)
        {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

Stos& Stos::operator=(Stos &s)
{
    Node * oldStos = s.head;
    while(oldStos != nullptr)
    {
        if(head == nullptr)
        {
            head = new Node(oldStos->data);
        }
        else
        {
            Node * newStos = head;
            while(newStos->next != nullptr)
            {
                newStos = newStos->next;
            }
            Node * tmp = new Node(oldStos->data);
            if(newStos->next == nullptr)
            {
                tail = tmp;
            }
            newStos->next = tmp;
        }
        Size++;
        oldStos = oldStos->next;
    }
    return *this;
}

Stos::Stos(Stos &s)
{
    Node * oldStos = s.head;
    while(oldStos != nullptr)
    {
        if(head == nullptr)
        {
            head = new Node(oldStos->data);
            tail = head;
        }
        else
        {
            tail->next = new Node(oldStos->data);
            tail = tail->next;
        }
        Size++;
        oldStos = oldStos->next;
    }
}














