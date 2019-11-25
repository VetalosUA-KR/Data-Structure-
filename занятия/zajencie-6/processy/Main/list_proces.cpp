#include <iostream>
#include "list_proces.h"

using namespace std;

list_proces::~list_proces()
{
    while(Size)
    {
        Node * toDel = head;
        head = toDel->next;
        delete toDel;
        Size--;
    }
}

void list_proces::wypisz()
{
    Node * current = head;
    while(current != nullptr)
    {
        cout<<(current->data).getPID()<<endl;
        current = current->next;
    }
}

void list_proces::pszestawNaPaczatek(int proc_ID)
{
    if(proc_ID == head->data.getPID())
    {
        cout<<"this is first element to out!"<<endl;
    }
    else
    {
        Node * previous_current_proces = nullptr;
        Node * current_proces = head;
        while(current_proces != nullptr && current_proces->data.getPID() != proc_ID)
        {
            previous_current_proces = current_proces;
            current_proces = current_proces->next;
        }
        //cout<<"previous_current_proces = "<<previous_current_proces->data.getPID()<<endl;
        //cout<<"current_proces = "<<current_proces->data.getPID()<<endl;
        Node * tmp = head;
        previous_current_proces->next = current_proces->next;
        head = current_proces;
        head->next = tmp;
    }
}

void list_proces::addElement(Process np)
{
    Node * next_current_proces = nullptr;
    Node * current_proces = head;
    while(current_proces != nullptr && current_proces->data.getPID() != np.getPID())
    {
        next_current_proces = current_proces;
        current_proces = current_proces->next;
    }
    if(current_proces != nullptr)
    {
        int l = current_proces->data.getL_wantwos();
        current_proces->data.setWantki(l+np.getL_wantwos());
    }
    else
    {
        Node * nowy = new Node(np);
        if(next_current_proces == nullptr) /// wstawianie do pustej
        {
            head = nowy;
        }
        else /// wtawianie do NIE pustej
        {
            next_current_proces->next = nowy;
        }
        Size++;
    }
}
