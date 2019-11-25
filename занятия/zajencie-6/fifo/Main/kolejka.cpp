#include <iostream>
#include "kolejka.h"

using namespace std;


void Kolejka::add_Element(int val)
{
    Node * newEl = new Node(val);
    if(head == nullptr)
        head = newEl;
    //head = newEl;
    else
    {
        tail->next = newEl;
    }
    tail = newEl;
    Size++;
}

void Kolejka::wypisz()
{
    Node * current =  head;
    while(current != nullptr)
    {
        cout<<"value -> "<<current->data/*<<"\t adres -> "<<current->next*/<<endl;
        current = current->next;
    }
    cout<<endl;
}


int Kolejka::getElement()
{
    /*Node * previous = nullptr;
    Node * current = head;
    while(current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = nullptr;*/
    if(Size)
    {
        Node * tmp = head;
        int tmp_data = head->data;
        head = head->next;
        delete tmp;
        Size--;
        return tmp_data;
    }
    else
        throw runtime_error("brak elementow");
}

Kolejka::Kolejka(Kolejka &k)
{
    head= nullptr;
    Size=0;
    operator=(k);              /// ******************
}


void Kolejka::odwzoruj()
{
    Node * przed = nullptr;
    Node * succ = head;
    Node * after;


    while(succ != nullptr)
    {
        after = succ->next;
        succ->next = przed;
        head = succ;
        przed = succ;
        succ = after;
    }
}

void Kolejka::przestawKawalekNaPoczatek(int levo, int pravo)
{
    if(levo < pravo && pravo <= Size && levo > -1)
    {
        int counter = 0;
        Node * previous_current_left = nullptr;
        Node * current_left = head;
        while(counter < levo-1)
        {
            previous_current_left = current_left;
            current_left = current_left->next;
            counter++;
        }

        Node * current_right = current_left;
        while(counter != pravo-1)
        {
            current_right = current_right->next;
            counter++;
        }
        Node * next_current_right = current_right->next;
        Node *tmp = head;
        current_right->next = tmp;
        head = current_left;
        previous_current_left->next = next_current_right;
    }
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
    ///else this.usun();
    if (this != &k)
    {
        if(head != nullptr)
        {

            usun();
        }

        Node * old_kolejka = k.head;
        while(old_kolejka != nullptr)
        {
            if(head == nullptr)
            {
                Node * new_node = new Node(old_kolejka->data);
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new Node(old_kolejka->data);
                tail = tail->next;
            }
            Size++;
            old_kolejka = old_kolejka->next;
        }
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




