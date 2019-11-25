#include "plik.h"
struct Folder
{
private:
    struct Node
    {
        Plik file;
        Node * next;

        Node(Plik f, Node * n = nullptr)
        {
            file = f;
            next = n;
        }
    };

    Node * first = nullptr;
    int Size = 0;
public:
    Folder()=default;
};
