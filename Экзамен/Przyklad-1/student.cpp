#include "student.h"
#include <sstream>
#include <string>
#include<iostream>


using namespace std;


/**
    Metods
*/
bool Student::operator < (const Student &st)
{
    if(this->index <= st.index)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool czyPoprawnaOcena(float _ocena)
{
    if(_ocena >= 2 && _ocena <= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool czyPoprawnyIndeks(int index)
{
    ///????????
}




/**
    SETTERS
*/
void Student::setSurname(string _surname)
{
    surname = _surname;
}
void Student::setNames(string _names)
{
    names = _names;
}
void Student::setIndex(int _index)
{
    index = _index;
}
void Student::setMark(float _mark)
{
    mark = _mark;
}

///****************************
/**
    GETTERS
*/
string Student::getSurname()
{
    return surname;
}
string Student::getNames()
{
    return names;
}
string Student::getShortNames()
{
    string shortName = "";
    string nam;
    istringstream x(names);
    //x<<names;
    while(x >> nam)
    {
        nam = nam.substr(0,1);
        shortName += nam+".";
    }
    return shortName;
}
int Student::getIndex()
{
    return index;
}
float Student::getMark()
{
    return mark;
}













