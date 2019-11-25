
#include <iostream>
#include "lista_laczona.h"

using namespace std;

void lista_lacona::wstaw(int data)
{
    Node * newElement = new Node(data);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        tail->next = newElement;
        /*Node * tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newElement;*/
    }
    tail = newElement;
    Size++;
}

void lista_lacona::wypisz()
{
    Node * tmp = head;
    int counter = 1;
    //cout<<"|";
    while(tmp != nullptr)
    {
       cout<<tmp->data<<" ";
        tmp = tmp->next;
        if(counter%3 == 0)
        {
            //cout<<"| \t |";
        }
        counter++;
    }
}

void lista_lacona::usun(int index)
{
    int cur = 1;
    int counter = 0;
    Node * tmp = head;
    int sred = 0;
    while(tmp != nullptr)
    {
        ///cout<<"cur = "<<cur<<" index = "<<index<<"\t raznica = "<<(cur%index)<<endl;
        if(cur%index == 0)
        {
            sred += tmp->data;
            counter++;
        }
        tmp = tmp->next;
        cur++;
    }
    sred = sred/counter;
    //cout<<endl<<sred<<endl;
    Node * przedCurrent = head;
    Node * current = head;
    while(current != nullptr)
    {
        /*cout<<"przedCurrent = "<<przedCurrent->data<<endl;
        cout<<"current = "<<current->data<<endl;
        cout<<"----------------"<<endl;*/
        //cout<<"curr elem = "<<current->data<<"\t sred = "<<sred;
        if(current->data > sred)
        {
            //cout<<"  delete element "<<current->data<<endl;
            if(current == head)
            {
                Node * toDelete = head;
                head = head->next;
                delete toDelete;
            }
            else
            {
                Node * toDelete = current;
                przedCurrent->next = current->next;
                //current->next = nullptr;
                delete toDelete;
            }
            current = przedCurrent->next;
            Size--;
        }
        else
        {
            //cout<<endl;
            przedCurrent = current;
            current = current->next;
        }
        //cout<<"----------"<<endl;
    }
}


void lista_lacona::przeniesTrojki()
{
    /// Если длинна шнура меньше чем одно деление шнура
    if(Size <= 3)
    {
        return;
    }
    else
    {
        /// Если нужно будет изменять первую тройку
        Node * previousFirst = nullptr;
        Node * first = head;
        Node * last = head->next->next;
        int counter = 0;
        /// Если после первого изменения, новая "первая" тройка подлежит изменению
        while(counter < (Size/3) && first->data != first->next->data && first->next->data != last->data && first->data != last->data)
        {
            head = last->next;
            tail->next = last;
            tail->next->next = first->next;
            tail->next->next->next = first;
            tail->next->next->next->next = nullptr;
            tail = first;
            first = head;
            last = head->next->next;
            counter++;
        }
        /// Если "первые" тройки больше не нужно изменять и длинна шнура позволяет переставить указатели на следующую тройку
        if(Size >= 6)
        {
            previousFirst = head->next->next;
            first = previousFirst->next;
            last = first->next->next;
        }
        /// Начинаем проверку шнура без учета "первой" тройки и отнимаем от длинны шнура деленной на 3 переменную которая отвечает за то,
        /// сколько "первых" троек мы переставили в конец, что-бы не доходить к ним, тем самым не входя в бесконечный цикл
        for(int i = 1; i < (Size/3)-counter; i++)
        {
            if(first->data != first->next->data && first->next->data != last->data && first->data != last->data)
            {
                previousFirst->next = last->next;
                tail->next = last;
                tail->next->next = first->next;
                tail->next->next->next = first;
                tail->next->next->next->next = nullptr;
                tail = first;
            }
            previousFirst = head->next->next;
            first = previousFirst->next;
            last = first->next->next;
        }
    }
}

/*void lista_lacona::wymenPary(lista_lacona &L2)
{
    if(Size < 4 && L2.Size < 4)
    {
        return;
    }
    else
    {
        Node * l1_previous_first = head->next->next;
        Node * l1_seconde = l1_previous_first->next;

        Node * l2_previous_first = L2.head->next->next;
        Node * l2_seconde = l2_previous_first->next;

        while(true)
        {
            cout<<"size = "<<Size/4<<endl;
            cout<<"iterator = "<<i<<endl;
            cout<<"l1_previous_first = "<<l1_previous_first->data<<endl;
            cout<<"l1_seconde = "<<l1_seconde->data<<endl;
            cout<<"-----------------"<<endl;
            cout<<"l2_previous_first = "<<l2_previous_first->data<<endl;
            cout<<"l2_seconde = "<<l2_seconde->data<<endl;
            cout<<endl;
            cout<<endl;

            l1_previous_first = l1_seconde->next->next->next;
            l1_seconde = l1_previous_first->next;

            l2_previous_first = l2_seconde->next->next->next;
            l2_seconde = l2_previous_first->next;
            i++;
        }
    }
}*/

void lista_lacona::test()
{
    Node * first = head;
    Node * seconde = first->next;
    //Node * three = seconde->next;

    while(seconde->next != nullptr && seconde->next->next != nullptr )
    {
        cout<<"first = "<<first->data<<endl;
        cout<<"seconde = "<<seconde->data<<endl;
        //cout<<"three = "<<three->data<<endl;
        cout<<"----------------"<<endl;

        first = seconde->next;
        seconde = first->next;

        /*if(seconde->next != nullptr && seconde->next->next != nullptr )
        {
            first = seconde->next;
            seconde = first->next;
            //three = seconde->next;
        }
        else
        {
            return;
        }*/
    }
    /*
    while(succ!=NULL && succ->next!=NULL && succ->next->next!=NULL && succ->next->next->next!=NULL)
    {
        Node* first=succ;
        Node* second=succ->next;
        Node* third=succ->next->next;
        Node* four=succ->next->next->next;

        cout<<"first is "<<first->dane<<endl;
        cout<<"second is "<<second->dane<<endl;
        cout<<"third is "<<third->dane<<endl;
        cout<<"four is "<<four->dane<<endl;
        cout<<endl;
    }
    */
}












