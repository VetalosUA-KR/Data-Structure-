#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    student s1;

    string status;

    string _name;
    string _nazwisko;
    int _numer_indeksu;
    int _rok_studiow;
    int _wiek;
    float _srednia_ocena;

    cout<<"1 - tworzenie nowego studenta"<<endl;
    cout<<"2 - wyswietlic studentow po zadanemu roku"<<endl;
    cout<<"3 - wyswietlic sredni wiek wszystkich studentow"<<endl;
    cout<<"9 - wyjscie z programy"<<endl;
    cin>>status;
    while(status != "9")
    {
        if(status == "1")
        {
            while(true)
            {
                cout<<"wpisz \"new\" dla stworzenia nowego uzytkownika, \"exit\" dla wyjscia "<<endl;
                cin>>status;
                if(status == "new")
                {
                    cout<<"podaj imie studenta -> "; cin>>_name; cout<<endl;
                    cout<<"podaj nazwisko studenta -> "; cin>>_nazwisko; cout<<endl;
                    cout<<"podaj numer indeksu studenta -> "; cin>>_numer_indeksu; cout<<endl;
                    cout<<"podaj rok studiow studenta -> "; cin>>_rok_studiow; cout<<endl;
                    cout<<"podaj wiek studenta -> "; cin>>_wiek; cout<<endl;
                    cout<<"podaj srednia ocena studenta -> "; cin>>_srednia_ocena; cout<<endl;
                    s1.setName(_name);
                    s1.setNazwisko(_nazwisko);
                    s1.setNumer_indeksu(_numer_indeksu);
                    s1.setRok_studiow(_rok_studiow);
                    s1.setWiek(_wiek);
                    s1.setSrednia_ocena(_srednia_ocena);
                    s1.dopiszDoPliku("lista_studentow.txt");
                }
                else
                {
                    status = "0";
                    break;
                }
            }
        }
        if(status == "2")
        {
            int _rok;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"wypisanie studentow po zadanemu roku"<<endl;
            cout<<"podaj rok -> "; cin>>_rok;
            wypiszLudziZRoku("lista_studentow.txt", _rok);
            cout<<"--------------------------------------------------"<<endl;
            status = "0";
        }
        if(status == "3")
        {
            cout<<"--------------------------------------------------"<<endl;
            cout<<"sriedni wiek studentow = "<<sredniaWiekuOsub("lista_studentow.txt")<<endl;
            cout<<"--------------------------------------------------"<<endl;
            status = "0";
        }
        if(status == "0")
        {
            cout<<"1 - tworzenie nowego studenta"<<endl;
            cout<<"2 - wyswietlic studentow po zadanemu roku"<<endl;
            cout<<"3 - wyswietlic sredni wiek wszystkich studentow"<<endl;
            cout<<"9 - wyjscie z programy"<<endl;
            cin>>status;
        }
    }

    return 0;
}
