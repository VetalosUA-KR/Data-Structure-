#include <iostream>
#include "kolejka.h"

using namespace std;


void Kolejka::add_Element(int val)
{
    Node * newEl = new Node(val,head);
    if(!head)tail = newEl;
    head = newEl;
    Size++;
}

void Kolejka::wypisz()
{
    Node * current =  head;
    while(current != nullptr)
    {
        cout<<"value -> "<<current->data<<"\t adres -> "<<current->next<<endl;
        current = current->next;
    }
    cout<<endl;
}


int Kolejka::getElement()
{
    Node * previous = nullptr;
    Node * current = head;
    while(current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = nullptr;
    Node * toDelete = current;
    delete toDelete;
    Size--;
    return toDelete->data;
}

Kolejka::Kolejka(Kolejka &k)
{
    operator=(k);
}

bool Kolejka::operator==(Kolejka &s)
{
    Node * current_left = head;
    Node * current_right = s.head;
    while(current_left != nullptr)
    {
        if(current_left->data != current_right->data)
        {
            return false;
        }
        current_left = current_left->next;
        current_right = current_right->next;
    }
    return true;

}

Kolejka &Kolejka::operator=(Kolejka &k)
{
    /*Node * old_kolejka = k.head;
    while(old_kolejka != nullptr)
    {
        if(head == nullptr)
        {
            head = new Node(old_kolejka->data);
        }
        else
        {
            Node * new_kolejka = head;
            while(new_kolejka->next != nullptr)
            {
                new_kolejka = new_kolejka->next;
            }
            new_kolejka->next = new Node(old_kolejka->data);
        }
        Size++;
        old_kolejka = old_kolejka->next;
    }*/
    Node * old_kolejka = k.head;
    Node * new_kolejka = head;
    while(old_kolejka != nullptr)
    {
        while(new_kolejka != nullptr)
        {
            new_kolejka = new_kolejka->next;
        }
        new_kolejka = new Node(old_kolejka->data,head);
        Size++;
        old_kolejka = old_kolejka->next;
    }
    return *this;
}

void Kolejka::usun()
{
    while(Size)
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
        Size--;
    }
}

Kolejka::~Kolejka()
{
    while(Size)
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
        Size--;
    }
}


int Kolejka::getSize()
{
    return Size;
}

int Kolejka::getHead()
{
    return head->data;
}

int Kolejka::getTail()
{
    return tail->data;
}



