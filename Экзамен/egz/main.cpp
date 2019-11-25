#include <iostream>
#include <fstream>
#include <string>
#include "kontener.h"
#include "osoba.h"


using namespace std;

int main()
{
    ifstream plikOsoby("osoby.txt");
    ifstream plikPesel("pesel.txt");

    List<Osoba> l1;
    while(!plikOsoby.eof() && !plikPesel.eof())
    {
        string name;
        string surname;
        string pesel;

        bool ok1,ok2 = true;

        ///  ��������� �� �������
        plikOsoby>>surname;

        if(!plikOsoby)
        {
            surname = "DO WERIFICACJI";
            ok1 = false;
        }
        else
        {
            /// �������� ������ ������ ����� �������
            char c = plikOsoby.get();
            if(c == ' ')/// ���� �� ���� ������ ���� ������
            {
                getline(plikOsoby, name);/// �������� ��� �����
                if(name.size() == 0)/// ���� ��� ������, ������ ����� �����������, ������ � ��������!
                {
                    name = "DO WEREFIKACJI";
                    ok1 = false;
                }
            }
            /// ���� �� �� ������, ������ ����� �����������, ������ � ��������!
            else
            {
                name = "DO WEREFIKACJI";
                ok1 = false;
            }
        }
        cout<<name<<" "<<surname<<endl;



        getline(plikPesel, pesel);

        Osoba newOsoba;

        newOsoba.setName(name);
        newOsoba.setSurname(surname);
        newOsoba.setPesel(pesel);
        newOsoba.setDenU(getDU(pesel));


        l1.addElement(newOsoba);
    }

    if(!plikOsoby.eof() || !plikPesel.eof())
    {
        cout << "Niezgodna liczba linii w plikach!" << endl;
    }

    plikOsoby.close();
    plikPesel.close();

    ofstream rez("wynik.txt");

    while(l1.getSize())
    {
        try
        {
            Osoba o = l1.pop();
            rez<<o.getD()<<endl;
            rez<<o.getName()<<endl;
            rez<<o.getSurname()<<endl<<endl;

        }
        catch(...)
        {
            cout<<"brak elementow";
        }
    }
    rez.close();



        //l1.wypisz();
    return 0;
}






