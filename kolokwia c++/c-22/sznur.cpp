#include"sznur.h"
#include<iostream>
#include<stdexcept>
using namespace std;

Sznur::Sznur()
{
    poczatek=NULL;
    koniec=NULL;
    ileJest=0;
}

void Sznur::wypisz()
{
    Box*lazik;
    lazik=poczatek;
    while(lazik!=NULL)
    {
        cout<<lazik->dane<<" ";
        lazik=lazik->nast;
    }
}

void Sznur::wstaw(int liczba)
{
    Box*nowy;
    nowy=new Box(liczba);
    if(poczatek==NULL)
    {
        poczatek=nowy;
        koniec=nowy;
    }
    else
    {
        koniec->nast=nowy;
        koniec=nowy;
    }
ileJest++;
}

void Sznur::usun()
{
    if(poczatek!=NULL)
    {
        Box*lazik=poczatek;
        int mini=lazik->dane;
        int maks=lazik->dane;
        while(lazik!=NULL)
        {
            if(lazik->dane<mini)
            {
                mini=lazik->dane;
            }
            else if(lazik->dane>maks)
            {
                maks=lazik->dane;
            }
            lazik=lazik->nast;
        }
        int niemaks=mini;
        int niemini=maks;
        lazik=poczatek;
        while(lazik!=NULL)
        {
            if(lazik->dane!=mini && lazik->dane<niemini)
            {
                niemini=lazik->dane;
            }
            if(lazik->dane!=maks && lazik->dane>niemaks)
            {
                niemaks=lazik->dane;
            }
            lazik=lazik->nast;
        }
        cout<<niemini<<" "<<niemaks<<endl;


        lazik=poczatek;
        int suma=0;
        int ilosc=0;
        while(lazik!=NULL)
        {
            if(lazik->dane==niemini)
            {
                suma=suma+niemini;
                ilosc++;
            }
            else if(lazik->dane==niemaks)
            {
                suma=suma+niemaks;
                ilosc++;
            }
            lazik=lazik->nast;
        }
        float srednia=float(suma)/ilosc;
        cout<<srednia<<endl;

        Box*lazik0=NULL;
        lazik=poczatek;

        while(lazik!=NULL)
        {
            if(poczatek->dane>srednia)
            {
                poczatek=poczatek->nast;
                delete lazik;
                lazik=poczatek->nast;
                continue;
            }

            if(lazik->dane>srednia)
            {
                if(poczatek->nast==lazik)
                {
                    poczatek->nast=lazik->nast;
                    delete lazik;
                    lazik=poczatek->nast;
                    lazik0=poczatek;
                }
                else
                {
                    lazik0->nast=lazik->nast;
                    delete lazik;
                    lazik=lazik0->nast;
                    continue;
                }
            }
            else
            {
                lazik0=lazik;
                lazik=lazik->nast;
            }
        }
    }
}
