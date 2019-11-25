
#include <iostream>
#include <string>
#include "kontener.h"
#include "dane.h"
using namespace std;

bool checkNip(string nip)
{
	if(nip.length()!=10)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool checkSurname(string sur)
{
	if(sur.length()==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool checkName(string n)
{
	if(n.length()==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Student::operator <(const Student &st)
{
	if(this->nip > st.nip)
	{
		return false;
	}
	else
	{
		return true;
	}

}

Student lista::pop()
{
	while(head!=nullptr)
	{
		Node* killer=head;
		head=head->next;
		ilosc--;
		return killer->dane;
	}
}


