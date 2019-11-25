#ifndef List_H
#define List_H

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T> //requires any type T with operator<
struct List
{

private:

    struct Node
    {
        T value;
        Node* next;
        Node(T v, Node* n = nullptr)
        {
            value = v;
            next = n;
        }
    };

    Node* head = nullptr;
    int counter = 0;

    //invariants:
    //if nonempty, head points to the first node (the lowest one)
    //the next for the first node points to the second node, etc.
    //the next for the last node is null
    //counter is at least 0 (empty list) and it is the number of nodes (size of the list)

public:

    //constructors

    List() = default;
    //pre: none
    //post: the list is empty

    //destructor

    ~List();
    //pre: none
    //post: none

    //modifiers

    void insert(T _data);
    //pre: none
    //post: the argument value is inserted in the ascending order, size is increased by 1

    T pop();
    //pre: the list is not empty
    //post: the lowest value is removed, size is decreased by 1
    //return: the lowest value

    void clear();
    //pre: none
    //post: the list is empty

    //selectors

    int size() const;
    //pre: none
    //return: the current size of the list

};


template<typename T>
List<T>::~List()
{
    clear();
}
template<typename T>
void List<T>::insert(T _data)
{
    Node * newElement = new Node(_data);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
        cout<<"test ";
        if(_data < head->value)
        {
            newElement->next = head;
            head = newElement;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->value < _data)
            {
                tmp = tmp->next;
            }
            newElement->next = tmp->next;
            tmp->next = newElement;
        }
    }
    counter++;
}

template<typename T>
T List<T>::pop()
{
    if(head != nullptr)
    {
        Node * toDelete = head;
        T toReturn = head->value;
        head = head->next;
        delete toDelete;
        return toReturn;
    }
}

/**template<typename T>
void List<T>::insert(T v)
{
    Node* pred = nullptr;
    Node* succ = head;

    while(succ != nullptr && succ->value < v) //operator< required for T
    {
        pred = succ;
        succ = succ->next;
    }

    Node* creator = new Node(v, succ);
    if(pred != nullptr)
        pred->next = creator;
    else
        head = creator;

    counter++;
}

template<typename T>
T List<T>::pop()
{
    if(counter == 0)
        throw logic_error("Empty list.");

    Node* killer = head;
    T result = killer->value;
    head = killer->next;

    delete killer;
    counter--;

    return result;
}*/

template<typename T>
void List<T>::clear()
{
    while(head != nullptr)
    {
        Node* killer = head;
        head = killer->next;
        delete killer;
    }

    counter = 0;
}

template<typename T>
int List<T>::size() const
{
    return counter;
}

#endif

