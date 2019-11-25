
#include "bib_ulamek.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/// Funkcji pomocnicze

int NWD(int l1, int l2)
{
    int b;
    if(l1 % l2 == 0)
    {
        return l2;
    }
    else
    {
        b = l1 % l2;
        return NWD(l2, b);
    }
}

int NWW (int l1, int l2)
{
    return (l1*l2)/NWD(l1,l2);
}


/// Implementacji funkcii biblioteki

Ulamek::Ulamek(int l, int m)
{
    if(m == 0) throw range_error("zerovy mianownik");

    licz = l;
    mian = m;

    if(m < 0)
    {
        licz = -licz;
        mian = -mian;
    }
}

Ulamek Ulamek::operator / (Ulamek u)
{
    Ulamek wyn;
    wyn.licz = licz * u.mian;
    wyn.mian = u.licz * mian;
    return wyn;
}

Ulamek Ulamek::operator * (Ulamek u)
{
    Ulamek wyn;
    wyn.licz = licz * u.licz;
    wyn.mian = mian * u.mian;
    return wyn;
}

Ulamek Ulamek::operator - (Ulamek u)
{
    Ulamek wyn;
    Ulamek kopia1(licz, mian);
    Ulamek kopia2(u.licz, u.mian);
    /*cout<<"ulamek 1 = "<<kopia1.licz<<"/"<<kopia1.mian<<endl;
    cout<<"ulamek 2 = "<<kopia2.licz<<"/"<<kopia2.mian<<endl;
    cout<<endl;*/
    int m1 = kopia1.mian;
    int m2 = kopia2.mian;
    kopia1.ulamekDoWspolnegoMianownika(m1, m2);
    kopia2.ulamekDoWspolnegoMianownika(m2, m1);
    /*cout<<"ulamek 1 = "<<kopia1.licz<<"/"<<kopia1.mian<<endl;
    cout<<"ulamek 2 = "<<kopia2.licz<<"/"<<kopia2.mian<<endl;
    cout<<endl;*/
    wyn.licz = kopia1.licz - kopia2.licz;
    wyn.mian = m1 * m2;


    return wyn;
}

Ulamek Ulamek::operator + (Ulamek u)
{
    Ulamek wyn;
    Ulamek kopia1(licz, mian);
    Ulamek kopia2(u.licz, u.mian);
    /*cout<<"ulamek 1 = "<<kopia1.licz<<"/"<<kopia1.mian<<endl;
    cout<<"ulamek 2 = "<<kopia2.licz<<"/"<<kopia2.mian<<endl;
    cout<<endl;*/
    int m1 = kopia1.mian;
    int m2 = kopia2.mian;
    kopia1.ulamekDoWspolnegoMianownika(m1, m2);
    kopia2.ulamekDoWspolnegoMianownika(m2, m1);
    /*cout<<"ulamek 1 = "<<kopia1.licz<<"/"<<kopia1.mian<<endl;
    cout<<"ulamek 2 = "<<kopia2.licz<<"/"<<kopia2.mian<<endl;
    cout<<endl;*/
    wyn.licz = kopia1.licz + kopia2.licz;
    wyn.mian = m1 * m2;


    return wyn;
}

bool Ulamek::operator == (Ulamek u)
{
    Ulamek kopia1(licz, mian);
    Ulamek kopia2(u.licz, u.mian);
    kopia1.skroc();
    kopia2.skroc();

    if(kopia1.licz == kopia2.licz && kopia1.mian == kopia2.mian)
    {
        return true;
    }
    else return false;
}

bool Ulamek::operator > (Ulamek u)
{
    Ulamek kopia1(licz, mian);
    Ulamek kopia2(u.licz, u.mian);
    kopia1.skroc();
    kopia2.skroc();
    int m1 = kopia1.mian;
    int m2 = kopia2.mian;
    kopia1.ulamekDoWspolnegoMianownika(m1, m2);
    kopia2.ulamekDoWspolnegoMianownika(m2, m1);

        if(kopia1.licz > kopia2.licz)
        {
            return true;
        }
        else return false;

}

bool Ulamek::operator < (Ulamek u)
{
    Ulamek kopia1(licz, mian);
    Ulamek kopia2(u.licz, u.mian);

    kopia1.skroc();
    kopia2.skroc();

    kopia1.ulamekDoWspolnegoMianownika(kopia1.mian, kopia2.mian);
    kopia2.ulamekDoWspolnegoMianownika(kopia1.mian, kopia2.mian);

        if(kopia1.licz < kopia2.licz)
        {
            return true;
        }
        else return false;

}


void Ulamek::skroc()
{
    int l = licz;
    int m = mian;
    licz = l/NWD(l,m);
    mian = m/NWD(l,m);
}


void Ulamek::ulamekDoWspolnegoMianownika(int ul1, int ul2)
{
    //cout<<licz<<" * "<<ul2<<endl;
    licz = licz*ul2;
    mian = NWW(ul1,ul2);

}

void Ulamek::wypisz()
{
    cout<<"licznik -> "<<licz<<endl;
    cout<<"mianowki -> "<<mian<<endl;
}


