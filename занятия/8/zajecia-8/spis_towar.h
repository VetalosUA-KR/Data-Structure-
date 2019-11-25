
#include "towar.h"
struct spis_tow
{
private:
    struct Node
    {
        Towar dane;
        Node * next;
        //kostruckt
        Node(Towar d, Node * n = nullptr)
        {
            dane = d;
            next = n;
        }
    };
    Node * pocz = nullptr;
    int Size = 0;
public:
    spis_tow() = default;
    void vstaw (Towar t);
    void vstawRoznowartosciowo (Towar t);
    float zdejmiZaKodem(int n, float ile);
    void skompresuj();
    void wypisz();

};
