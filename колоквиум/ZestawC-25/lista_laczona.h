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
    Node * head = nullptr;
    int Size = 0;
public:
    lista_laczona()=default;
    void addElement(int d);
    void wypisz();
    void usunCiagi(int K);
    void usunNadmiar(int n);
    //void usunF(int K);
};

