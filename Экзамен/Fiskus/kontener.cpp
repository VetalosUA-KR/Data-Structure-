#include <iostream>
#include "kontener.h"
#include "dane.h"
using namespace std;

lista::lista()
{
	head=nullptr;
	ilosc=0;
}

void lista::wstaw(Student s)
{
	Node* nowy_element=new Node(s);

	if(head==nullptr)
	{
		head=nowy_element;
	}
	else if(head->dane < s)
    {
        nowy_element->next = head;
        head = nowy_element;
    }
	else
	{
		Node* szuk=head;
		Node* zaszuk=nullptr;

		while(szuk!=nullptr && s < szuk->dane)
		{
			zaszuk=szuk;
			szuk=szuk->next;
		}

		nowy_element->next=szuk;
		zaszuk->next=nowy_element;
		/*Node * tmp = head;
		while(tmp->next != nullptr && tmp->next->dane < s)
        {
            tmp = tmp->next;
        }
        nowy_element->next = tmp->next;
        tmp->next = nowy_element;*/
	}
	ilosc++;
}

int lista::rozmiar()
{
	return ilosc;
}

