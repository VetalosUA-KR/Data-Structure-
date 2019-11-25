#include <string>
using namespace std;

/* OSOBA */

struct Osoba {
    string imie;
    string nazwisko;
    int pesel[11];
    int wzrost;

/// Konstruktor
Osoba(string im = "vitalii", string naz = "voitenko", string pes = "93093012375", int wz = 190);

/// Metody
void wypisz ();
void zmienWzrost(int nowyWzrost);
void zmienNazwisko(string noweNazwisko);

};

/* GRUPA */

struct Grupa {

    Osoba listOsob[30];
    int ilosOsob = 0;
    //Grupa(int _ileOsob);

    ///Metod
    void wypiszGrupe ();
    bool CzyJestMezczyzna ();
    void wypiszZaMisecem (int mes[]);
    int SredniWzrost ();
};


