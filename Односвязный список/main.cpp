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




///Перегруженый оператор []
///Возвращает значение которое находится под индексом который передали
template<typename T>
T & List<T>::operator[](const int index)
{
    int counter = 0;
    Node * current = this->head; /// Указываем на адрес первого элемента в нашем списке
    ///Доходим до конца списка
    while(current != nullptr)
    {
        ///если дошли до нужного элемента возвращаем его данные
        if(counter == index)
        {
            return current->data;
        }
        ///если нет указываем на адрес следующего элемента и увеличиваем счетчик
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

///Удаление первого элемента элемента списка (того который был записан самым ПЕРВЫМ !)
template<typename T>
void List<T>::pop_front()
{
    ///Во временную переменную сохраняем адрес первого элемента списка
    Node *temp = head;
    ///Теперь первым элементом нашего списка будет второй(адрес которого до этого хранился в pNext )
    head = head->pNext;
    ///Удаляем первый элемент деинкрементируем размер списка
    delete temp;
    Size --;
}


///Удаление последнего элемента списка (того который был записан ПОСЛЕДНИМ !)
template<typename T>
void List<T>::pop_back()
{
    /// Удаление по индексу
    removeAt(Size-1);
}


///Добавление элемента в конец списка
template<typename T>
void List<T>::push_back(T data)
{
    ///Если список пустой то это будет первый элемент
    if(head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        ///Сохраняем адрес первого элемента списка
        Node * current = this->head;
        ///Доходим до конца списка
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        ///в адресе следующего элемента(который создаем) создаем новый элемент
        current->pNext = new Node(data);
    }

    Size++;
}


///Добавление элемента в начало списка
template<typename T>
void List<T>::push_front(T data)
{
    /// Указатель который до этого указывал на первый элемент списка теперь будет указывать на только что созданый
    /// конструктор вторым параметром принимает адрес следующего элемента
    /// вторым параметром передаем текущий элемент, который был первым, а сейча будет вторым
    head = new Node(data, head);
    Size++;
}


///Добавление элемента по индексу
template<typename T>
void List<T>::insert(T data, int index)
{
    if(index == 0)
    {
        push_front(data);
    }
    else
    {
        /// Поочередно переходим через все элементы ДО элемента который находится перед тем который нам нужен
        Node * previous = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        /// записываем как следующий элемент, вновь созданый
        /// следующим элементом которого будет тот который до этого указывал на элемент указаный как индекс
        /// если раньше 1 указывал на 2 то помещая эелемент между 1 и 2  (1   Х  2) связь которая указывала (1 -> 2) теперь указывает (Х -> 2)
        previous->pNext = new Node(data, previous->pNext);
        Size++;
    }
}


///Удаление элемента по заданому индексу
template<typename T>
void List<T>::removeAt(int index)
{
    if(index == 0)
    {
        pop_front();
    }
    else
    {
        /// Доходим до элемента которой находится ПЕРЕД тем который нам нужен
        Node *previous = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        ///Сохраняем его во врменную переменную
        Node *toDelete = previous->pNext;
        /// при удаление второго элемента (1 -> 2 -> 3)
        /// связь которая указывала (2 -> 3) теперь указывает (1 -> 3)
        previous->pNext = toDelete->pNext;
        /// удаляем элемент инкрементируя размер списка
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










