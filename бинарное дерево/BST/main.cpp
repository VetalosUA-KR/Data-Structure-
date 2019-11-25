#include <iostream>
#include "binary_tree.h"

using namespace std;

int main()
{
    binary_tree bt;

    /*bt.addElement(34);
    bt.addElement(30);
    bt.addElement(41);
    bt.addElement(21);
    bt.addElement(32);
    bt.addElement(39);
    bt.addElement(45);
    bt.addElement(15);
    bt.addElement(24);
    bt.addElement(31);
    bt.addElement(33);
    bt.addElement(36);
    bt.addElement(40);
    bt.addElement(43);
    bt.addElement(48);
    bt.usun(41);*/

    /*bt.addElement(10);
    bt.addElement(7);
    bt.addElement(17);
    bt.addElement(5);
    bt.addElement(8);
    bt.addElement(11);
    bt.addElement(20);
    bt.addElement(18);
    bt.addElement(29);
    bt.addElement(19);
    bt.leftRotation();*/

    bt.addElement(20);
    bt.addElement(18);
    bt.addElement(29);
    bt.addElement(16);
    bt.addElement(19);
    bt.addElement(22);
    bt.addElement(31);
    bt.addElement(13);
    bt.addElement(10);
    bt.addElement(14);
    bt.rightRotation();


    bt.wypisz(bt.root, 0);

    return 0;
}








