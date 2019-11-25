#include <iostream>
#include "Osoba.h"

bool Osoba::operator > (Osoba &osoba)
{
    //cout<<"test";
    if(getDate(this->getPesel()) > getDate(osoba.getPesel()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Osoba::operator < (Osoba &osoba)
{
    //cout<<"test";
    if(getDate(this->getPesel()) < getDate(osoba.getPesel()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Osoba::getDate(string pes)
{
    string mm = pes.substr(2,2);
    string yyyy = pes.substr(0,2);
    string dd = pes.substr(4,2);
    if(stoi(mm) > 12 && stoi(mm) < 12+25)
    {
        string y = "20"+yyyy;
        yyyy = y;

        int m = stoi(mm);
        m-=20;
        mm = "0"+to_string(m);
    }
    else if(stoi(mm) > 12+20)
    {
        string y = "21"+yyyy;
        yyyy = y;

        int m = stoi(mm);
        m-=40;
        mm = "0"+to_string(m);
    }
    else
    {
        string y = "19"+yyyy;
        yyyy = y;
    }

    string Sdate = yyyy+mm+dd;
    int Idate = stoi(Sdate);
    return Idate;

}

string getDU(string pes)
{
    string mm = pes.substr(2,2);
    string yyyy = pes.substr(0,2);
    string dd = pes.substr(4,2);
    if(stoi(mm) > 12 && stoi(mm) < 12+25)
    {
        string y = "20"+yyyy;
        yyyy = y;

        int m = stoi(mm);
        m-=20;
        mm = "0"+to_string(m);
    }
    else if(stoi(mm) > 12+20)
    {
        string y = "21"+yyyy;
        yyyy = y;

        int m = stoi(mm);
        m-=40;
        mm = "0"+to_string(m);
    }
    else
    {
        string y = "19"+yyyy;
        yyyy = y;
    }

    string Sdate = dd+"."+mm+"."+yyyy;
    return Sdate;
}





