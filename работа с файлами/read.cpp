#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
ifstream - чтения данных из файла
*/

int main()
{
    string path = "myFile.txt";

    ifstream fin;
    fin.open(path);
    if(!fin.is_open())
    {
        cout<<"can't open file"<<endl;
    }
    else
    {
        cout<<"file is open"<<endl;

        string str;

        while(!fin.eof())
        {
            str="";
            getline(fin, str);
            cout<<str<<endl;
        }

    }
    fin.close();


    return 0;
}



















