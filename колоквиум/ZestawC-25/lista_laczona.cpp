
#include <iostream>
#include "lista_laczona.h"

using namespace std;

void lista_laczona::addElement(int d)
{
    Node * newEle = new Node(d);
    if(head == nullptr)
    {
        head = newEle;
    }
    else
    {
        Node * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newEle;
    }
    Size++;
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

void lista_laczona::usunNadmiar(int n) ///**********************************
{
    Node * target = head;
    while(target != nullptr)
    {
        Node * previouse = nullptr;
        Node * current = target;
        int counter = 0;
        while(current != nullptr)
        {
            if(target->data == current->data)
            {
                counter++;
                if(counter > n)
                {
                    Node * toDel = current;
                    previouse->next = current->next;
                    delete current;
                    Size--;
                }
            }
            previouse = current;
            current = current->next;
        }
        counter = 0;
        target = target->next;
    }
}

///Если передать 0, то нужно буддет удалять первый элемент, это не обрабатываеться
/*void lista_laczona::usunCiagi(int K)
{
    if(K+1 > Size){return;}
    else
    {
        Node * previouse = head;
        for(int i = 1; i < K; i++)
        {
            previouse = previouse->next;
        }
        int index = K;
        while(previouse != nullptr)
        {
            if(index == K)
            {
                Node * current = previouse->next;
                while(current != nullptr && current->data != current->next->data)
                {
                    Node * toDel = current;
                    previouse->next = current->next;
                    delete toDel;
                    current = current->next;
                }
                index = 0;
            }
            else
            {
                previouse = previouse->next;
                index++;
            }
        }
    }
}*/

void lista_laczona::usunCiagi(int K)
{
    if(K+1 > Size)
    {
        return;
    }
    else
    {
        Node * succ = head;
        Node * previouse = head;
        for(int i = 1; i < K; i++)
        {
            previouse = previouse->next;
        }
        int index = K;
        while(succ != nullptr)
        {
            Node * begin = succ;
            Node * end = begin;
            Node * after = begin->next;
            int counter = 1;
            while(after != nullptr && end->data != after->data)
            {
                end = after;
                after = after->next;
                counter++;
            }

            if(counter >= 1)
            {
                if(!previouse)
                {
                    head = after;
                }
                else
                {
                    previouse->next = after;
                }
                succ = after;
                end->next = nullptr;
                while(begin != nullptr)
                {
                    Node * toDel = begin;
                    begin = begin->next;
                    delete toDel;
                    //size--;
                }
            }
            for(counter = 0; counter < K && succ != nullptr; counter++)
            {
                previouse = succ;
                succ = succ->next;
            }
        }
    }
}
    /**void lista_laczona::usunF(int K)
    {

          Node* succ=head;
          Node* pred=NULL;
          Node* killer_begin;
          Node* killer_end;
          int index=1;
          Node* tmp=head;
          while(succ!=NULL)
          {
            //cout<<"pred dane jest "<<pred->dane<<endl;
            pred=succ;
            Node* Begin=succ;
            Node* End=Begin;
            Node* after=Begin->next;

             if(index==K)
               {
                     while(after!=NULL && after->data%2!=0)
                    {
                     End=after;
                     after=after->next;
                     killer_begin=Begin->next;
                     killer_end=End;
                    }

                    pred->next=End->next;
                    succ=after;
                    delete killer_begin;
                    delete killer_end;
                    index=1;
               }
               else
               {
                    pred->next=End->next;
                    succ=after;
                    index++;
               }

           }
    }*/








