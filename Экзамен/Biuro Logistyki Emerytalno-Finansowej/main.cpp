#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Lista.h"
#include "struktura.h"
using namespace std;

class zlyPesel
{
    public: string e;
};


int main()
{
    Emeryt E;
    Lista l;

    string osoby = "osoby.txt";
    string pesele = "pesele.txt";
    string wyniki = "wyniki.txt";
    string Nazwisko1, Imie1, Pesel1;

    ifstream plik1;
    ifstream plik2;
    plik1.open(osoby.c_str());
    plik2.open(pesele.c_str());

    try
    {
        if(!plik1.good()) cout<<"Blad otwarcia pliku.";
        if(!plik2.good()) cout<<"Blad otwarcia pliku.";

        string linia1;
        string linia2;
        int spacja = 0;
        int liczba=0;

        while(getline(plik1, linia1))
        {
            Nazwisko1=dajNazwisko(linia1);
            Imie1 = dajImie(linia1);

            if(linia1.find(" "))
                    spacja==1;

            for (int i=0; i<linia1.length(); i++)
            {
                if(isdigit(linia1[i]))
                    liczba++;
            }

             if(linia1.length()<6 || spacja==0 || liczba!=0)
             {
                 linia1="DO WERYFIKACJI";
             }

             E.wstaw1(Nazwisko1, Imie1);


        }
        while (getline(plik2, linia2))
        {
            try
            {
                Pesel1=dajPesel(linia2);

                if (!kontrolaPesel(pesel))
                {
                    zlyPesel d;
                    d.e = linia2;
                    throw d;

                }

                E.wstaw1(Pesel1);
                l.wstaw(E);
            }

            catch(exception &d)
                {
                    cout << pesel << ":" << d.what() << endl;
                    continue;
                }
        }

        if(!plik1.eof() || !plik2.eof())
            {
                cout << "Niezgodna liczba linii w plikach!" << endl;
            }

        ofstream plik3; plik3.open(wyniki.c_str());
        l.wypisz();

        for(int i=l.rozmiar(); i>0; i--)
        {
            E=l.Pobierz();
            string pom = E.dajPesel();

            plik3<<E.dajDateUrodzenia(pom)<<endl;
            plik3<<E.dajImie()<<endl;
            plik3<<E.dajNazwisko()<<endl;
            plik3<<endl;
        }

        plik1.close();
        plik2.close();
        plik3.close();

    }
    catch (exception &d)
    {
        cout<< d.what()<<endl;
    }



    return 0;
}
