#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "struktura.h"
#include <iostream>
using namespace std;


struct Lista
{
private:
    struct Node
    {
        Emeryt value;
        Node* next;
        Node(Emeryt _value, Node* _next)
        {
            value=_value;
            next=_next;
        }
    };

    Node* head;
    int ile;

public:
    Lista()
    {
        head=NULL;
        ile=0;
    }

    ~Lista()
    {
        while(head!=NULL)
        {
            Node* killer = head;
            head=head->next;
            delete killer;
        }
        ile=0;
    }

    void wstaw (Emeryt _value)
    {
        Node* zaszukacz = NULL;
        Node* szukacz = head;
        Node* x = new Node(_value);

        if (szukacz == NULL)
        {
            head = x;
        }
        else
        {
            while(szukacz!= NULL && szukacz -> value<_value)
            {
                zaszukacz = szukacz;
                szukacz = szukacz -> next;
            }

            x->next = szukacz;
            zaszukacz -> next = x;
        }
        ile++;
    }

    void wypisz()
    {
        Node* szukacz = head;
        while(szukacz!=NULL)
        {
            szukacz->E.wypisz1();
            szukacz = szukacz -> next;
        }

    }

    Emeryt Pobierz()
    {
        Emeryt nowa;
        Node* tmp = head;
        nowa = tmp -> value;
        head = tmp->next;
        delete tmp;
        ile--;
        return nowa;
    }

    int rozmiar()
    {
        return ile;
    }
};

#endif // LISTA_H_INCLUDED

