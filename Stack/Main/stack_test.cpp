#include <iostream>
#include "unbounded_stack.h"

using namespace std;

Stack::~Stack()
{
    clear();
   /* ///Во временную переменную сохраняем адрес первого элемента списка
    Node *temp = head;
    ///Теперь первым элементом нашего списка будет второй(адрес которого до этого хранился в pNext )
    head = head->next;
    ///Удаляем первый элемент деинкрементируем размер списка
    delete temp;*/
}

Stack::Stack(const Stack&)
{
    cout<<"Create elemt's stack with parametrs"<<endl;
}

bool Stack::empty() const
{
    if(head == nullptr) return true;
    else return false;
}

/// add elent to stak on top, increment counter by 1
void Stack::push(int val)
{
    /// KOLEJKA ?
    /**if(head == nullptr)
    {
        head = new Node(val);
    }
    else
    {
        Node * current = this->head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(val);
    }*/

    /// STEK ?
    head = new Node(val, head);
    counter++;
}

/// delet top element
int Stack::pop()
{
    if(counter > 0)
    {
        int v = head->value;
        Node * tmp = head;
        head = head->next;
        delete tmp;
        counter --;
        return v;
        /**Node *temp = head;
        for(int i = 0; i < counter-2; i++)
        {
            temp = temp->next;
        }
        return temp->value;
        temp->next = nullptr;
        delete temp;
        counter--;*/
    }
    else
    {
        cout<<"newozmozno udalit";
        return 0;
    }
}

void Stack::clear()
{
    while(counter)
    {
        pop();
    }
}

void Stack::print () const
{
    Node * current = this->head;
    int _count = 0;
    while(_count < counter)
    {
        //cout<<current->next<<" - \t"<<current->value<<endl;
        cout<<current->value<<" ";
        current = current->next;
        _count++;
    }
    cout<<endl;
}

int Stack::size() const
{
    return counter;
}

/// return top value
int Stack::top() const
{
    /**Node * current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    return current->value;*/
    return head->value;
}

int Stack::operator [](const int index)
{
    Node * current = head;
    int count = 0;
    while(current->next != nullptr)
    {
        if(count == index)
        {
            return current->value;
        }
        current = current->next;
        count++;
    }
}

Stack& Stack::operator=(const Stack&s)
{
    /*if(this != &s)
    {

    }*/
    //this->counter = 10;
    // return *this;
    /*Stack * test;
    test->counter = 10;
    cout<<test->counter;*/
    //Stack test;
    /*Node * current = this->head;
    for(int i = 0; i < this->counter; i++)
    {
        if(newS->head == nullptr)
        {
            newS->head = new Node(current->value);
        }
        else
        {
            Node * targ = newS->head;
            while(targ->next != nullptr)
            {
                targ = targ->next;
            }
            targ->next = new Node(current->value);
        }
        current = current->next;
    }*/
//    return &test;
    /*if(head == nullptr)
    {
        head = new Node(val);
    }
    else
    {
        Node * current = this->head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(val);
    }*/
}

void Stack::operator==(const Stack&) const
{
    cout<<counter;
}







