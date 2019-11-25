struct dwukierunkowa_lista
{
private:
    struct Node
    {
        int data;
        Node * next;
        Node * previouse;
        Node (int d, Node * n = nullptr, Node * p = nullptr)
        {
            data = d;
            next = n;
            previouse = p;
        }
    };
    Node * head = nullptr;
    int size = 0;
public:
    Node * last = nullptr;
    dwukierunkowa_lista()=default;
    void addElement(int d);
    void wypiszZPoczatka();
    void wypiszZKonca();
    void deleToIndex(int index);
    void addToIndex(int index, int data);
};
