#ifndef STRUKTRA_H_INCLUDED
#define STRUKTRA_H_INCLUDED
#include <iostream>
#include <stdexcept>
using namespace std;


struct Emeryt
{
    private:
        string imie;
        string nazwisko;
        string pesel;

    public:
        Emeryt(string _imie=" ", string _nazwisko=" ", string _pesel=" ")
        {
            imie = _imie;
            nazwisko = _nazwisko;
            pesel = _pesel;
        }

        void wstaw1(string _imie, string _nazwisko, string _pesel)
        {
            imie = _imie;
            nazwisko = _nazwisko;
            pesel = _pesel;
        }

        void wypisz1 ()
        {
            cout<< imie << " " << nazwisko << " " << pesel << " "<< endl;
        }

        string dajDateUrodzenia(string s)
        {
            string kropka= ".";
            string data = s.substr(4,2)+kropka;
            string zero = "0";
            string jeden = "1";
            string dwadziescia = "20";
            string dziewietnascie = "19";


            if (pesel[2]==2)
                data = data+zero+s.substr(3,1)+kropka;
            else if (pesel[2]==3)
                data=data+jeden + s.substr(3,1)+kropka;
            else
                data=data+s.substr(2,2)+kropka;


            if (pesel[2]==2 || pesel[2]==3)
                data=data+dwadziescia + s.substr(0,2);
            else
                data=data+dziewietnascie + s.substr(0,2);

            return data;

        }

        string dajImie() {return imie;}
        string dajNazwisko() {return nazwisko;}
        string dajPesel() {return pesel;}

        bool operator < (Emeryt pes)
        {
            if(pesel>pes.pesel)
            {
                return false;
            }
            else if(pesel[2]==2 || pesel[2]==3)
            {
                return true;
            }
            else return true;
        }

        bool kontrolaPesel(string pesel)
            {
                if(pesel.length() != 10)
                    return false;
                else
                    {
                        int suma=0;
                        int wagi[11]={1,3,7,9,1,3,7,9,1,3,1};
                        for (int i=0; i<11; i++)
                            suma= suma + (wagi[i]*pesel[i]);

                        if(suma%10 != 0)
                            return false;
                        else return true;
                    }

            }

};




#endif //STRUKTRA_H_INCLUDED

