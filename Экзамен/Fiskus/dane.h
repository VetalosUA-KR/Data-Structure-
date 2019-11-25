#ifndef DANE_H_
#define DANE_H_

#include <iostream>
#include <string>
#include "kontener.h"
using namespace std;

struct Student
{
private:
	string name;
	string surname;
	string nip;
	float tax;

public:

	void setName(string n)
	{
		name=n;
	}

	void setSurname(string ser)
	{
		surname=ser;
	}

	void setNip(string ni)
	{
		nip=ni;
	}

	void setTax(float tx)
	{
		tax=tx;
	}

	string getName()
	{
		return name;
	}

	string getSurname()
	{
		return surname;
	}

	string getNip()
	{
		return nip;
	}

	float getTax()
	{
		return tax;
	}

	bool operator < (const Student &st);
};

bool checkNip(string nip);
bool checkSurname(string sur);
bool checkName(string n);





#endif /* DANE_H_ */

