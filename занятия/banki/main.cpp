#include <iostream>
#include <string>
#include <fstream>
#include "bib_IBAN.h"
#include "bib_lista.h"
#include <cstdlib>

using namespace std;

int main()
{
    IBAN
    string wiek1 = "29.09.1993";
    string wiek2 = "30.09.1993";

    string rez = wiek1.substr(0, 2)+wiek1.substr(3, 2)+wiek1.substr(6);
    string rez2 = wiek2.substr(0, 2)+wiek2.substr(3, 2)+wiek2.substr(6);

    int w1 = stoi(rez);
    int w2 = stoi(rez2);
    if(w1 > w2)
    {
        cout<<"w1   mladsze";
    }
    else
    {
        cout<<"w1   starsze";
    }

    const int SIZE = 4;
    string banki[SIZE] = {"1040","1460","2440","3240"};
    lista tablica_list[SIZE];


    ifstream pl;
    string nazwaPliku;
    cout<<"Podaj nazwe pliku: ";
    cin>>nazwaPliku;
    pl.open(nazwaPliku);
    IBAN _ib;

    if(!pl.is_open())
    {
        cout<<" BLAD "<<endl;
    }
    else
    {
        while(!pl.eof())
        {
            string linia;
            pl>>linia;
            //string numBanku = linia.substr(3,4);
            //cout<<linia<<endl;
            _ib.setIBAN(linia);
            //cout<<czyIBAN(_ib)<<" czyIBAN "<<endl;
            if(czyIBAN(_ib) && sprawdzanieCyfryKontroliIBAN(_ib))
            {
                string numBanku = linia.substr(4,4);
                for(int i = 0; i < SIZE; i++)
                {
                    if(numBanku == banki[i])
                    {
                        tablica_list[i].wstaw(_ib);
                        break;
                    }
                }


            }
            else
            {
                cout<<"blad"<<endl;
            }

            //cout<<_ib.numerKonta<<" ttt"<<endl;
            //l1.wstaw(_ib);
        }

    }

    /// сравнить значение с ИБАН списка и вписать в соответсвующие файлы
    for(int i = 0; i < SIZE; i++)
    {
        ofstream plik;
        plik.open(banki[i]+".txt");

        while(true)
        {

            try
            {
                string numKota = tablica_list[i].zdejmiPierwszy().getNumerKonta();
                //string numBanku = ib.numerKonta.substr(4, 4);

                //cout<<numBanku<<"\t"<<banki[j]<<endl;


                plik<<numKota<<endl;
            }
            catch(...)
            {
                break;
            }


        }
        plik.close();
    }
    //cout<<l1.zdejmiPierwszy()->getNumerKonta();

    return 0;
}
