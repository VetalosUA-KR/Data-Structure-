#ifndef sznur_h
#define sznur_h
#include<iostream>
#include<stdexcept>
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
    void wypisz();
    void wstaw(int liczba);
    void usun(int k,int m);
};
#endif // sznur_h
