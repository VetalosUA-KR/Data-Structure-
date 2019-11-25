#ifndef bib_IBAN_zna
#define bib_IBAN_zna
#include <iostream>


using namespace std;

template <typename T>
struct List
{
private:
    struct Node
    {
        T data;
        Node * next;
        Node (T d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
    };

    int size = 0;
    Node * head = nullptr;

public:
    List()=default;
    void addElement(T data);
    void wypisz();
    T pop();
    int getSize(){return size;}
};


template<typename T>
void List<T>::addElement(T data)
{
    Node * newElenemt = new Node(data);
    if(head == nullptr)
    {
        head = newElenemt;
    }
    else
    {

        if(head->data > data)
        {
            newElenemt->next = head;
            head = newElenemt;
        }
        else
        {
            Node * tmp = head;
            while(tmp->next != nullptr && tmp->next->data < data)
            {
                tmp = tmp->next;
            }
            newElenemt->next = tmp->next;
            tmp->next = newElenemt;
        }
    }
    size++;
}

template <typename T>
void List<T>::wypisz()
{
    Node * tmp = head;
    while(tmp != nullptr)
    {
        cout<<tmp->data.getName()<<endl;
        tmp = tmp->next;
    }
}

template <typename T>
T List<T>::pop()
{
    if(head != nullptr)
    {
        Node * killer = head;
        T rez = killer->data;
        head = head->next;
        delete killer;
        size --;
        return rez;

    }
}



#endif




