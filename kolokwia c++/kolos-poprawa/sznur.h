#ifndef sznur_h
#define sznur_h
#include<iostream>
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
    void usun();
};
#endif // sznur_h
