#ifndef KONTEINER_H_
#define KONTEINER_H_

#include <iostream>
#include <string>
#include "dane.h"
using namespace std;

struct lista
{
private:
	struct Node
	{
		Student dane;
		Node* next;

		Node(Student d, Node* n=nullptr)
		{
			dane=d;
			next=n;
		}
	};

	Node* head;
	int ilosc;
public:
	void wstaw(Student s);
	lista();
	int rozmiar();
	Student pop();

};


#endif /* KONTEINER_H_ */
