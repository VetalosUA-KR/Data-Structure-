#include <iostream>
#include "process.h"

Process::Process(int p, int l_w)
{
    PID = p;
    l_watkow = l_w;
}

int Process::getPID()
{
    return PID;
}
void Process::setPID(int p)
{
    PID = p;
}

int Process::getL_wantwos()
{
    return l_watkow;
}

void Process::setWantki (int w)
{
    l_watkow = w;
}
