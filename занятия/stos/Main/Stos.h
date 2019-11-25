#include <iostream>
struct Stos {


  private:
      struct Node{
        int data = 0;
        Node * next;

        Node(int d = 0, Node * n=nullptr)
        {
            data = d;
            next = n;
        }
      };

    ///pola stosu
    int Size = 0;
    Node * head = nullptr;
    Node * tail = nullptr;

  public:
    Stos(Stos &s);
    Stos() = default;
    ~Stos();
    void wypisz();
    void wloz(int a);
    void wlozDoSrodku(int data, int index);
    void usunZSrodku(int index);
    void clear();
    int zdejmi();
    int getSize();

    Node * getTail(){ return tail; }
    Node * getHead(){ return head; }

    bool operator==(Stos& s);
    Stos& operator=(Stos& s);

};





