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

public:
    lista_laczona()=default;
    void addElement(int data);
    void wypisz();
    void usunPlus(int k);
};

