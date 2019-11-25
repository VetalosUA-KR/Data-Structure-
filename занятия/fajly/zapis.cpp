#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string nazwa;
    /*cout<<"Podaj nazwy pliku -> ";
    cin>>nazwa;*/
    ofstream pl;
    pl.open("myFile.txt", ios::out|ios::app);

    pl<<"test1"<<endl;
    pl<<"test2"<<endl;


    pl.close();

    return 0;
}

