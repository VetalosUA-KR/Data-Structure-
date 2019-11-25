#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**
ofstream - запись в файл
*/

int main ()
{
    string path = "myFile.txt";
    ofstream fout;
    fout.open(path, ofstream::app);

    if(!fout.is_open())
    {
        cout<<"error opened file"<<endl;
    }
    else
    {
        for(int i = 1; i < 6; i++)
        {
            cout<<"enter "<<i<<" number ";
            int a;
            cin>>a;
            fout<<a;
            fout<<"\n";
        }
    }


    fout.close();


    return 0;
}
