#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string nazwa;
    /*cout<<"Podaj nazwy pliku -> ";
    cin>>nazwa;*/
    ifstream pl;
    pl.open("1.cpp");

    if(!pl)
    {
        throw runtime_error("zla nazwa pliku");
    }
    else
    {
        char znak;
        while(!pl.eof())
        {
            pl.get(znak);
            cout<<znak;
        }
    }

    pl.close();

    return 0;
}

