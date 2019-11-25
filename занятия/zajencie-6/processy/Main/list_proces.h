#include "process.h"
struct list_proces{
  private:
    struct Node{
        Process data;
        Node * next;
        Node (Process d, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
      };
        Node * head = nullptr; /// poczatek
        Node * tail = nullptr; /// ostatni wezel
        int Size = 0;
    public:
    list_proces() = default;
    ~list_proces();
    void wypisz();
    void addElement(Process np);
    void pszestawNaPaczatek(int proc_ID);
    int getHead(){return head->data.getPID();}
};
