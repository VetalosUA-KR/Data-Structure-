#ifndef sznur_h
#define sznur_h
#include<iostream>
using namespace std;

struct Sznur
{
private:
    struct Box
    {
        int dane;
        Box*nast;
        Box(int liczba,Box*adres=NULL)
        {
            dane=liczba;
            nast=adres;
        }
    };
    Box*poczatek;
    Box*koniec;
    int ileJest;
public:
    Sznur();
    void wstaw(int liczba);
    void wypisz();
    void usun();
};
#endif // sznur_h
