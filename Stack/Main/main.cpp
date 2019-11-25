#include <iostream>
#include "unbounded_stack.h"


using namespace std;

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.print();
    s1.clear();
    //Stack s2 = s1;

    //s2 = s1;
    /**cout<<"rozmiar = "<<s1.size()<<endl;
    cout<<"czy pusty? "<<s1.empty()<<endl;
    s1.clear();
     cout<<"rozmiar = "<<s1.size()<<endl;
    cout<<"czy pusty? "<<s1.empty()<<endl;*/

    /*s1.print(); //5 4 3 2 1
    cout << "Size: " << s1.size() << endl; //5
    cout << "Pop: " << s1.pop() << endl; //5
    cout << "Size: " << s1.size() << endl; //4
    cout << "Top: " << s1.top() << endl; //4
    s1.print(); //4 3 2 1*/

   //cout<<s1[3];
  //  s2.print();

    /*cout<<s1.top()<<" <- top value"<<endl;
    cout<<s1.getHead()->value<<" <- head value"<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.print();
    cout<<s1.top()<<" <- top value"<<endl;
    cout<<s1.getHead()->value<<" <- head value"<<endl;*/




    /*cout<<"size "<<s1.size()<<endl;
    cout<<s1.top()<<" <- top value"<<endl;

    s1.pop();
    s1.pop();

    s1.print();
    cout<<"size "<<s1.size()<<endl;*/

    //cout<<s1.empty()<<"\t(1-pusty     0-niepusty)"<<endl;

    //s1 == s2;

    /*s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.print(); //5 4 3 2 1
    cout << "Size: " << s1.size() << endl; //5
    cout << "Pop: " << s1.pop() << endl; //5
    cout << "Size: " << s1.size() << endl; //4
    cout << "Top: " << s1.top() << endl; //4
    s1.print(); //4 3 2 1

    Stack s2 = s1;

    s2.print(); //4 3 2 1
    s2.push(6);
    s2.print(); //6 4 3 2 1

    s1 = s2;

    if(s1 == s2)
        cout << "The stacks are equal." << endl; //yes

    cout << "Pop: " << s1.pop() <<endl; //6
    s1.print(); //4 3 2 1
    s2.print(); //6 4 3 2 1

    s2.clear();
    s1.print(); //4 3 2 1
    s2.print(); //empty*/

    return 0;
}
