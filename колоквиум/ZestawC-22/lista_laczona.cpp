#include "lista_laczona.h"
#include <iostream>

using namespace std;

void lista_laczona::addElement(int data)
{
    Node * newElement;
    try
    {
        newElement = new Node(data);
    }
    catch(exception &e)
    {
        throw runtime_error("brak pamici");
    }
    if(head == nullptr)
    {
        head = newElement;
        tail = newElement;
    }
    else
    {
        if(head->data >= data)
        {
            Node * h = head;
            head = newElement;
            newElement->next = h;
            //tail = h;
        }
        else
        {
            Node * current = head;
            while(current->next != nullptr && current->next->data <= data)
            {
                current = current->next;
            }
            if(tail == current)
            {
                tail->next = newElement;
                tail = newElement;
            }
            else
            {
                Node * nextElement = current->next;
                current->next = newElement;
                newElement->next = nextElement;
            }
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

void lista_laczona::przeniesZKrokiem(int k)
{
    if(head==nullptr){return;}
    else
    {
        Node * previouse = nullptr;
        Node * first = head;

        Node * startLeft = nullptr;
        Node * finishLeft = nullptr;

        Node * startRight;
        Node * finishRight;

        int index = 1;
        int kuda = 0; /// 0 - left      1 - right
        while(first != nullptr)
        {
            if(index == k)
            {
                Node * mover = first;
                previouse->next = first->next;
                //first->next = nullptr;
                if(kuda == 0)
                {
                    /*mover->next = startLeft;
                    startLeft = mover;*/
                    if(finishLeft == nullptr)
                    {
                        startLeft = mover;
                        finishLeft = mover;
                        mover->next = nullptr;
                    }
                    else
                    {
                        mover->next = startLeft;
                        startLeft = mover;
                    }
                    cout<<"/////////////////"<<endl;
                    //finishLeft->next = nullptr;
                    Node * tmp = startLeft;
                    while(tmp != nullptr)
                    {
                        cout<<tmp->data<<" ";
                        tmp = tmp->next;
                    }
                    cout<<"/////////////////"<<endl;
                    first = previouse->next;

                    kuda = 1;
                }
                else if(kuda == 1)
                {
                    first = previouse->next;
                    kuda = 0;
                }
                //first = previouse->next;
                index = 1;
            }
            else
            {
                previouse = first;
                first = previouse->next;
                index++;
            }
        }

            //cout<<startLeft->data<<" ";

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
            if(three->data%first->data==0 && three->data%seconde->data==0)
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
                three->next = four->next;
                delete four;
            }
            if(four->next != nullptr && four->next->next != nullptr && four->next->next->next != nullptr && four->next->next->next->next != nullptr)
            {
                first = four->next; /// ОПАСНО !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! потому что иногда мы удаляем четвертый элемент
                seconde = first->next;
                three = seconde->next;
                four = three->next;
            }
            else{return;}
        }
    }
}






/**
Node * previouse = nullptr;
        Node * first = head;

        Node * beg = nullptr;
        Node * en = nullptr;

        Node * beg2 = nullptr;
        Node * en2 = nullptr;

        int in = 0;
        int kuda = 0; /// 0 - в начало      1 - в конец
        while(first != nullptr)
        {
            if(in == k)
            {
                Node * mover = first;
                previouse->next = first->next;
                first = first->next;
                /// Перенес в начало
                if(kuda == 0)
                {
                    if(beg == nullptr)
                    {
                        beg = mover;
                    }
                       mover->next = beg;

                    beg = mover;
                    kuda = 1;
                }
                /// перенос в конец
                else
                {
                    if(beg2 == nullptr)
                    {
                        beg2 = first;
                    }
                    else
                    {
                        en2->next = first;
                    }
                    en2 = first;
                    kuda = 0;
                }
                in = 0;
            }
            else
            {
                previouse = first;
            first = first->next;

            }
            in++;
        }
        en->next = nullptr;
        en2->next = nullptr;


        cout<<"v naczalo ->";
        Node * tmp = beg;
        while(tmp != nullptr)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }


        cout<<endl<<"v koniec ->";
        Node * tmp2 = beg2;
        while(tmp2 != nullptr)
        {
            cout<<tmp2->data<<" ";
            tmp2 = tmp2->next;
        }
        */









