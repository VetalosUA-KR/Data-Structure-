#include "towar.h"
#include <iostream>

using namespace std;

bool Towar::operator<=(Towar t)
{
    if(t.getKod() <= this->getKod())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Towar::wypiszTowar()
{

}

