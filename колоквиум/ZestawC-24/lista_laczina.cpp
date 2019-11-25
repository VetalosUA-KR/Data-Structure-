#include <iostream>
#include "lista_laczina.h"

using namespace std;


void lista_laczona::przeniesParami(int k)
{
    Node * previouseLeft = nullptr;
    Node * left = head;
    for(int i = 0; i < (size/2) - k; i++)
    {
        previouseLeft = left;
        left = left->next;
    }

    if((size)%2 != 0) {k++;}

    Node * previouseRight = nullptr;
    Node * right = left;

    for(int i = 0; i < k; i++)
    {
        previouseRight = right;
        right = right->next;
    }


}


void lista_laczona::usunZDodatkiem()
{
    if(size < 2){return;}
    else
    {
        Node * previouse = nullptr;
        Node * first = head;
        Node * seconde = first->next;
        while(true)
        {
            if(first->data == seconde->data)
            {
                int d = first->data;

                Node* pom = seconde->next; ///ap - dodane вспомагательная

                if(previouse == nullptr)
                {
                    head = seconde->next;
                    delete first;
                    delete seconde;
                }
                else
                {
                    previouse->next = seconde->next;
                    delete first;
                    delete seconde;
                }

               /* if(previouse->next != nullptr && previouse->next->data == d) //AP:
jesli usuwana para byla na poczatku to previouse jest null
                Node * toDel = previouse->next;
                    previouse->next = toDel->next;
                    delete toDel;
                }
                */
                //ap: zamiast powyzszego:
                if(pom != nullptr && pom->data == d)
                {
                    Node * toDel = pom;
                    if (previouse==nullptr)
                        head = toDel->next;
                    else
                        previouse->next = toDel->next;
                    delete toDel;
               }


/*                if(previouse->next != nullptr && previouse->next->next != nullptr)
 //AP: tu tez previouse mogl byc null
                {
                    first = previouse->next;
                    seconde = first->next;
                }
                //else {return;} */


                //ap: ... i aktualizacja wskaznikow dla tego przypadku
                    if (previouse==nullptr)
                        first = head;
                    else
                        first=previouse->next;

                    if (first!=nullptr)
                        seconde = first->next;
                    if (first==nullptr || seconde == nullptr) break;


            }
            else if(seconde->next != nullptr && seconde->next->next != nullptr)
            {
                previouse = seconde;
                first = seconde->next;
                seconde = first->next;
            }
            else{return;}
        }
    }
}


void lista_laczona::wypisz()
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
    Node * newElement = new Node(d);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        if(head->data <= d)
        {
            newElement->next = head;
            head = newElement;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->data >= d)
            {
                tmp = tmp->next;
            }
            newElement->next = tmp->next;
            tmp->next = newElement;
        }
    }
    size++;
}
