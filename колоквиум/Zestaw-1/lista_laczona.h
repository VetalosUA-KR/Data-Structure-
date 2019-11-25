struct lista_laczona
{
private:
    struct Node
    {
        int data;
        Node * next;
        Node (int d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
    };
    Node * head = nullptr;
    int size = 0;
public:
    lista_laczona()=default;
    ~lista_laczona();
    void wypis();
    void addElement(int d);
    void usun1();
    void usun2();
};
