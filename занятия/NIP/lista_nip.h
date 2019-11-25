#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "bib_nip.h"


struct lista_nip
{
private:
    struct Node
    {
        NIP data;
        Node * next;

        Node (NIP d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
    };

    Node * head = nullptr;
    int size = 0;

public:

    lista_nip()=default;
    void wstaw(NIP data);
    NIP zdejmi();
};
#endif
