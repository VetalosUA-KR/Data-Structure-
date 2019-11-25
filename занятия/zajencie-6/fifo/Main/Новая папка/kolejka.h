struct Kolejka {
private:
    struct Node {
        int data = 0;
        Node * next;
        Node (int d = 0, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
    };
    int Size = 0;
    Node * head = nullptr;
    Node * tail = nullptr; /// First element to out (last entered element)
public:
    Kolejka() = default;
    Kolejka(Kolejka &k);
    ~Kolejka();
    void add_Element(int val);
    void wypisz();
    void usun();

    bool operator==(Kolejka &k);
    Kolejka & operator=(Kolejka &k);
    int getElement();

    /// Getters - Setters
    int getHead();
    int getTail();
    int getSize();

};
