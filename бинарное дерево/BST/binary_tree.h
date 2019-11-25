struct binary_tree
{
private:
    struct Node
    {
        int data;
        Node * parent;
        Node * left;
        Node * right;
        Node(int d, Node * p = nullptr, Node * l = nullptr, Node * r = nullptr)
        {
            data = d;
            parent = p;
            left = l;
            right = r;
        }
    };

    int size = 0;
    Node * maxValue = nullptr;
    Node * minValue = nullptr;
public:
    Node * root = nullptr;
    binary_tree()=default;
    void wypisz(Node * current, int l);
    void addElement(int data);
    void usun(int data);

    void leftRotation();
    void rightRotation();
    void wypiszPrzezKolejku();

};
