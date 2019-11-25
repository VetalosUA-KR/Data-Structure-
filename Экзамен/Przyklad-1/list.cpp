#include "list.h"




/**template<typename T>
void List<T>::insert(T _data)
{
    Node * newElement = new Node(_data);
    if(head == nullptr)
    {
        head = newElement;
    }
    else
    {
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
}*/






