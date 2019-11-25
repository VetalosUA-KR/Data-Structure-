#include <iostream>
#include <string>
#include <fstream>
#include "kontener.h"
#include "dane.h"
using namespace std;

int main()
{
	lista ls;

	ifstream file1("podatnicy.txt");
	ifstream file2("rozliczenia.txt");

	/*string nazwa1;
	string nazwa2;

	cout<<"Podaj nazwe pierwszego pliku: ";
	cin>>nazwa1;
	cout<<"Podaj nazwe drugiego pliku: ";
	cin>>nazwa2;

	file1.open(nazwa1);
	file2.open(nazwa2);*/
	if(!file1.is_open() && !file2.is_open())
	{
		cout<<"Nie ma takich plikow "<<endl;
	}
	else
	{
		while(!file1.eof() && !file2.eof())
		{
			string surname;
			string name;
			string nip;
			string linia;
			float tax;

			getline(file1,nip);
			/*getline(file1, name);
			getline(file1, linia);

			cout<<"nip = "<<nip<<endl;
			cout<<"name = "<<name<<endl;
			cout<<endl;*/
			if(checkNip(nip))
			{
				getline(file1,name);

				if(checkSurname(name))
				{
					unsigned pos;
					pos=name.find(' ',0);

					surname=name.substr(0,pos);
					name=name.substr(pos+1);
					age = name.substr(name.length()-2);

					getline(file1,linia);

					file2 >> tax;

					Student s;

					s.setSurname(surname);
					s.setName(name);
					s.setNip(nip);
					s.setTax(tax);

					ls.wstaw(s);
				}
			}
		}
		file1.close();
		file2.close();

		ofstream out("wyniki.txt");

		while(ls.rozmiar() != 0)
		{
		cout<<ls.rozmiar();
			Student s=ls.pop();
			//cout<<s.getName()<<endl;
			out<<s.getSurname()<<endl;
			out<<s.getName()<<endl;
			out<<s.getNip()<<endl;
			out<<s.getTax()<<endl;
			out<<endl;
		}

		out.close();
	}

	return 0;
}
