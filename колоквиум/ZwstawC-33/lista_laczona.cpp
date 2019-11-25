
#include <iostream>
#include "lista_laczona.h"

using namespace std;

void lista_laczona::rozrzucSrodek(int k)
{
    if((2*k+1) >= size){return;}
    else
    {
        Node * tmp = head;

        Node * leftBegin = head;
        Node * leftEnd = nullptr;

        Node * rightBegin = nullptr;

        Node * toChange = nullptr;

        for(int i = 0; i < k; i++)
        {
            tmp = tmp->next;
        }

        leftEnd = tmp;
        toChange = tmp;

        for(int i = k; i < size-k-1; i++)
        {
            tmp = tmp->next;
        }

        rightBegin = tmp;
        //leftEnd->next = rightBegin;

        int weare = 0; /// 0 - left         1 - right
        while(toChange != rightBegin)
        {
            if(weare == 0)
            {
                //cout<<"right "<<toChange->data<<" "<<endl;
                if(leftBegin == head)
                {
                    toChange->next = leftBegin;
                    leftBegin = leftBegin->next;
                    head = toChange;
                }
                else
                {
                    leftBegin->next = leftBegin;
                    leftBegin = leftBegin->next;
                }
                weare = 1;
            }
            else if(weare == 1)
            {
                //cout<<"left "<<toChange->data<<" "<<endl;
                rightBegin->next = toChange;
                rightBegin = toChange;
                rightBegin->next = toChange->next;
                //cout<<rightBegin->data<<"adasf";
                weare = 0;
            }
            toChange = toChange->next;
        }
    }
}


void lista_laczona::usun()
{
    if(size < 4){return;}
    else
    {
        Node * previouse = nullptr;
        Node * first = head;
        Node * seconde = first->next;
        Node * three = seconde->next;
        Node * four = three->next;
        while(true)
        {
            if(seconde->data != three->data)
            {
                if(previouse == nullptr)
                {
                    head = four->next;
                    delete first;
                    delete seconde;
                    delete three;
                    delete four;
                }
                else
                {
                    previouse->next = four->next;
                    delete first;
                    delete seconde;
                    delete three;
                    delete four;
                }
            }
            else
            {
                first->next = four;
                delete seconde;
                delete three;
                previouse = four; /// тут
            }
            ///previouse
            if(four->next != nullptr && four->next->next != nullptr && four->next->next->next != nullptr && four->next->next->next->next != nullptr)
            {
                /// или тут ?
                first = four->next;///previouse
                seconde = first->next;
                three = seconde->next;
                four = three->next;
            }
            else{return;}
        }
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

void lista_laczona::wypisz()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}
