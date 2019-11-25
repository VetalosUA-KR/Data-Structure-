
struct lista_lacona
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
    Node * tail = nullptr;
    int Size = 0;
public:
    lista_lacona()=default;
    void wypisz();
    void wstaw(int data);
    void usun(int index);
    void przeniesTrojki();
    void wymenPary(lista_lacona &L2);
    void test();

    int getHead(){ return head->data; }
    int getTail(){ return tail->data; }
};

