#include "bib_IBAN.h"


struct lista
{
private:
    struct Node
    {
        IBAN dane;
        Node * next;
        Node(IBAN d, Node * n = nullptr)
        {
            dane = d;
            next = n;
        }
    };

    Node * head = nullptr;

public:
    lista()=default;

    void wstaw(IBAN ib);
    void wypisz();
    IBAN zdejmiPierwszy();
};
