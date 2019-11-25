
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

using namespace std;

struct Student
{

private:

    string surname = "None";
    string names = "None";
    int index = 0;
    float mark = 2.0;

    //invariants:
    //surname is not empty
    //names is not empty
    //index is 0 or is 6-digit positive integer value
    //mark is real value between 2 and 5

public:

    void setSurname(string);
    //pre: the argument is non-empty
    //post: the argument value is student's surname

    void setNames(string);
    //pre: the argument is non-empty and can contain many names separated by single spaces
    //post: the argument value is student's name(s)

    void setIndex(int);
    //pre: the argument is 6-digit positive integer value
    //post: the argument value is student's index

    void setMark(float);
    //pre: the argument is a real value between 2 and 5
    //post: the argument value is student's mark

    string getSurname();
    //pre: none
    //return: the current student's surname

    string getNames();
    //pre: none
    //return: the current student's name(s)

    string getShortNames();
    //pre: none
    //return: the current student's name first letters separated by dots

    int getIndex();
    //pre: none
    //return: the current student's index

    float getMark();
    //pre: none
    //return: the current student's mark

    bool operator<(const Student &st);
    //pre: none
    //return: true if the student's index is lower than the argument's index, false otherwise

};

    bool czyPoprawnyIndeks(int _index);
    bool czyPoprawnaOcena(float _ocena);

#endif // STUDENT_H_INCLUDED
