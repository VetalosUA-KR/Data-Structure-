#include <iostream>
#include "student.h"
#include <fstream>
#include <sstream>


student najwiekszaSrednia(string nazmwaPliku)
{

}

/**
dopisanie do pliku przedanego jako parametr nowego studenta
*/
void student::dopiszDoPliku(string nazwaPliku)
{
    ofstream file;
    file.open(nazwaPliku, ios::out|ios::app);

    file<<ime<<" "<<nazwisko<<" "<<numer_indeksu<<" "<<rok_studiow<<" "<<wiek<<" "<<srednia_ocena<<"\n";

    file.close();
}

/**
obliczanie sriedniego wieku wszystkich studentow z pliku przedanego jako parametr i zwrocienie tej wartosci
*/
float sredniaWiekuOsub(string nazwaPliku)
{
    ifstream file;
    file.open(nazwaPliku);
    float sredniaWieku = 0;
    int ileOsob = 0;

    if(!file){ throw runtime_error("nie ma takiego failu"); }
    else
    {
        string pole;
        while(!file.eof())          /// можно ли использовать stringstream
        {
            pole="";
            getline(file, pole);
            string word;
            stringstream x;
            x << pole;
                int i = 0;
            while(x >> word)
            {
                if(i == 4)
                {
                    ileOsob++;
                    sredniaWieku += stoi(word);
                }
                i++;
            }
        }
    }
    return sredniaWieku/ileOsob;
}


/**
wypisanie z pliku przedanego jako parametr wszystkich studentow ktorie jest studentami roku co bedzie ukazany jako 2-i parametr
*/
void wypiszLudziZRoku(string nazwaPliku, int rok)
{
    ifstream file;
    file.open(nazwaPliku);

    if(!file){ throw runtime_error("nie ma takiego failu"); }
    else
    {


        string imie;
        string nazwisko;
        int index;
        int rokStudiow;
        int wiek;
        float srednia;

        while(!file.eof())
        {
            file>>imie;
            if(!file){break;}
            file>>nazwisko;
            if(!file){break;}
            file>>index;
            if(!file){break;}
            file>>rokStudiow;
            if(!file){break;}
            file>>wiek;
            if(!file){break;}
            file>>srednia;
            if(rokStudiow == rok)
            {
                student s;
                s.setName(imie);
                s.setNazwisko(nazwisko);
                s.setNumer_indeksu(index);
                s.setRok_studiow(rokStudiow);
                s.setWiek(wiek);
                s.setSrednia_ocena(srednia);
                s.wypiszPolaStudenta();
            }
            /*pole="";
            getline(file, pole);
            string word;
            stringstream x;
            x << pole;
            while(x >> word)
            {
                if(word == rok)
                {
                    cout<<pole<<endl;
                }
            }*/

        }
    }
    file.close();
}

void student::wypiszPolaStudenta()
{
    cout<<ime<<" "<<nazwisko<<" "<<numer_indeksu<<" "<<rok_studiow<<" "<<wiek<<" "<<srednia_ocena<<endl;
}


/**
int main(){
    const int N = 256;      //Максимальная длина строки

    char S[N] = "Hello, i am string\nHow are you?\n-All OK!";  //Строка-предложение
    char word[N] = {};          //Буфер для считывания строки

    stringstream x;        //Создание потоковой переменной
    x << S;                //Перенос строки в поток

    while (x >> word) cout << word << '\n';  //выборка слов
    cin.get();
}
}*/
