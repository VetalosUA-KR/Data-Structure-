#include <iostream>
#include <string>

using namespace std;

template<typename T>
class List
{
    public:
        List();
        ~List();

        void pop_front();
        void pop_back();
        void push_back(T data);
        void push_front(T data);
        void clear();
        void insert(T data, int index);
        void removeAt(int index);
        int retH(){return head->data;}


        int GetSize(){ return Size; }

        T& operator [](const int index);

    private:
        //template<typename U>   /// ******************************
        class Node
        {
        public:
            Node *pNext;
            T data;

            Node(T data = T(), Node *pNext = nullptr)
            {
                this->data = data;
                this->pNext = pNext;
            }
        };

    int Size;
    Node *head;
};




///������������ �������� []
///���������� �������� ������� ��������� ��� �������� ������� ��������
template<typename T>
T & List<T>::operator[](const int index)
{
    int counter = 0;
    Node * current = this->head; /// ��������� �� ����� ������� �������� � ����� ������
    ///������� �� ����� ������
    while(current != nullptr)
    {
        ///���� ����� �� ������� �������� ���������� ��� ������
        if(counter == index)
        {
            return current->data;
        }
        ///���� ��� ��������� �� ����� ���������� �������� � ����������� �������
        current = current->pNext;
        counter++;
    }
}

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

///�������� ������� �������� �������� ������ (���� ������� ��� ������� ����� ������ !)
template<typename T>
void List<T>::pop_front()
{
    ///�� ��������� ���������� ��������� ����� ������� �������� ������
    Node *temp = head;
    ///������ ������ ��������� ������ ������ ����� ������(����� �������� �� ����� �������� � pNext )
    head = head->pNext;
    ///������� ������ ������� ���������������� ������ ������
    delete temp;
    Size --;
}


///�������� ���������� �������� ������ (���� ������� ��� ������� ��������� !)
template<typename T>
void List<T>::pop_back()
{
    /// �������� �� �������
    removeAt(Size-1);
}


///���������� �������� � ����� ������
template<typename T>
void List<T>::push_back(T data)
{
    ///���� ������ ������ �� ��� ����� ������ �������
    if(head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        ///��������� ����� ������� �������� ������
        Node * current = this->head;
        ///������� �� ����� ������
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        ///� ������ ���������� ��������(������� �������) ������� ����� �������
        current->pNext = new Node(data);
    }

    Size++;
}


///���������� �������� � ������ ������
template<typename T>
void List<T>::push_front(T data)
{
    /// ��������� ������� �� ����� �������� �� ������ ������� ������ ������ ����� ��������� �� ������ ��� ��������
    /// ����������� ������ ���������� ��������� ����� ���������� ��������
    /// ������ ���������� �������� ������� �������, ������� ��� ������, � ����� ����� ������
    head = new Node(data, head);
    Size++;
}


///���������� �������� �� �������
template<typename T>
void List<T>::insert(T data, int index)
{
    if(index == 0)
    {
        push_front(data);
    }
    else
    {
        /// ���������� ��������� ����� ��� �������� �� �������� ������� ��������� ����� ��� ������� ��� �����
        Node * previous = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        /// ���������� ��� ��������� �������, ����� ��������
        /// ��������� ��������� �������� ����� ��� ������� �� ����� �������� �� ������� �������� ��� ������
        /// ���� ������ 1 �������� �� 2 �� ������� �������� ����� 1 � 2  (1   �  2) ����� ������� ��������� (1 -> 2) ������ ��������� (� -> 2)
        previous->pNext = new Node(data, previous->pNext);
        Size++;
    }
}


///�������� �������� �� �������� �������
template<typename T>
void List<T>::removeAt(int index)
{
    if(index == 0)
    {
        pop_front();
    }
    else
    {
        /// ������� �� �������� ������� ��������� ����� ��� ������� ��� �����
        Node *previous = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        ///��������� ��� �� �������� ����������
        Node *toDelete = previous->pNext;
        /// ��� �������� ������� �������� (1 -> 2 -> 3)
        /// ����� ������� ��������� (2 -> 3) ������ ��������� (1 -> 3)
        previous->pNext = toDelete->pNext;
        /// ������� ������� ������������� ������ ������
        delete toDelete;
        Size--;
    }
}


int main ()
{


    List<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    cout<<lst.retH()<<" <- head value"<<endl;

    for(int i = 0; i < lst.GetSize(); i++)
    {
        cout<<lst[i]<<endl;
    }
    cout<<"delete element "<<endl<<endl;
    lst.pop_front();

    for(int i = 0; i < lst.GetSize(); i++)
    {
        cout<<lst[i]<<endl;
    }
    cout<<lst.retH()<<" <- head value"<<endl;
    /*cout<<"add element a 2 mesto "<<endl<<endl;
    lst.insert(100, 1);
     for(int i = 0; i < lst.GetSize(); i++)
    {
        cout<<lst[i]<<endl;
    }*/

    /*cout<<endl<<"ilosc elementow w liste = "<<lst.GetSize()<<endl<<"wykonanie metody clear"<<endl<<endl;
    lst.clear();

    for(int i = 0; i < lst.GetSize(); i++)
    {
        cout<<lst[i]<<endl;
    }
    cout<<endl<<"elementow w liste zostalo -> "<<lst.GetSize()<<endl;*/

    return 0;
}










