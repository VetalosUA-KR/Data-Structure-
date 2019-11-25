#include <iostream>
#include "list_sort.h"

using namespace std;

void list_sort::addELement(int data)
{
    Node * nowy;
    try
    {
        nowy = new Node(data);
    }
    catch(exception &e) {throw runtime_error ("brak pamieci");}
    if(first == nullptr)
    {
        first = nowy;
    }
    else if(data <= first->data)
    {
        nowy->next = first;
        first = nowy;
    }
    else
    {
        Node * zaszuk = nullptr;
        Node * szuk = first;
        while(szuk != nullptr && szuk->data < data)
        {
            zaszuk = szuk;
            szuk = zaszuk->next;
        }
        nowy->next = szuk;
        zaszuk->next = nowy;
    }
    Size ++;

}

void list_sort::deletWszystkieElement(int data, int param)
{
    if(first == nullptr)
    {

    }
    else
    {
        Node * previous_tmp = nullptr;
        Node * tmp = first;

        while(tmp != nullptr && tmp->data != data)
        {
            previous_tmp = tmp;
            tmp = tmp->next;
        }
        if(tmp != nullptr)
        {
           while(tmp != nullptr && tmp->data == data)
           {
               if(tmp!=first) //(first->data != data)
               {
                    previous_tmp->next = tmp->next;
                    delete tmp;
                    tmp = previous_tmp->next;
               }
               else
               {
                   //Node * toDelete = first;
                   first = tmp->next;
                   delete tmp;
                   tmp = first;

               }
                Size--;
                //tmp = tmp->next;
           }
        }
        else
        {
            throw runtime_error("niepoprava liczba");
        }
    }
}

void list_sort::deletElement(int data)
{
    if(first == nullptr)
    {

    }
    else
    {
        Node * previous_tmp = nullptr;
        Node * tmp = first;

        while(tmp != nullptr && tmp->data != data)
        {
            previous_tmp = tmp;
            tmp = tmp->next;
        }
        if(tmp != nullptr)
        {
           if(first->data != data)
           {
                previous_tmp->next = tmp->next;
                delete tmp;
           }
           else
           {
               Node * toDelete = first;
               first = toDelete->next;
               delete toDelete;
           }
            Size--;
        }
        else
        {
            cout<<"brak elementow";
        }
    }
}

void list_sort::wypisz()
{
    Node * tmp = first;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<endl;
        tmp = tmp->next;
    }
}


list_sort::~list_sort()
{

}
