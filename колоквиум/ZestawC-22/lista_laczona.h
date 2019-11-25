struct lista_laczona
{
private:
    struct Node
    {
        int data;
        Node * next;
        Node(int d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
    };
    int size = 0;
    Node * head = nullptr;
    Node * tail = nullptr;
public:
    lista_laczona()=default;
    void addElement(int data);
    void wypisz();
    void usun();
    void przeniesZKrokiem(int k);


    int getHead() { return head->data; }
    int getTail() { return tail->data; }

};

