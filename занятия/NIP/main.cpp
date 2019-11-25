#include <iostream>
#include <string>
#include <fstream>
#include "bib_nip.h"
#include "lista_nip.h"
#include <cstdlib>


using namespace std;

int main()
{

    const int SIZE = 3;
    string miasta[SIZE] = {"piotrkow.txt", "radomsko.txt", "tomaszow.txt"};
    string kody[SIZE] = {"771", "772", "773"};
    lista_nip kolejka_nip[SIZE];

    ifstream plik;
    string nazwaPliku;
    cout<<"Podaj nazwe pliku: ";
    cin>>nazwaPliku;
    plik.open(nazwaPliku);

    if(!plik.is_open())
    {
        cout<<"nie ma takiego pliku"<<endl;
    }
    else
    {
        while(!plik.eof())
        {
            NIP _nip;
            string linia;
            getline(plik, linia);

            /// сделать проверку на правильность прочитаных данных
            string nip = linia.substr(0, 10);
            string nazwa = linia.substr(10);

            _nip.setNIP(nip);
            _nip.setNazwa(nazwa);

            string currentKod = nip.substr(0,3);
            for(int i = 0; i < SIZE; i++)
            {
                if(currentKod == kody[i])
                {
                    kolejka_nip[i].wstaw(_nip);
                    cyfraKontroli(_nip);
                }
            }
        }
        plik.close();

        ofstream plik2;
        for(int i = 0; i < SIZE; i++)
        {
            plik2.open(miasta[i]);
            while(true)
            {
                try
                {
                    NIP current_nip = kolejka_nip[i].zdejmi();
                    plik2<<current_nip.getNazwa()<<endl;
                }
                catch(...)
                {
                    break;
                }
            }
            plik2.close();
        }


    }


    return 0;
}
