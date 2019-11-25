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
        Box(int dane, Box*adres=NULL)
        {
            this->dane=dane;
            this->nast=nast;
        }
    };
    Box*poczatek;
    Box*koniec;
    int ileJest;

public:
    Sznur();
    ~Sznur();
    void wypisz();
    void wstaw(int liczba);
    void usun();

};
#endif // sznur_h
