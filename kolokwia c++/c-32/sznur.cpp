#include "sznur.h"
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
    try
    {
        nowy=new Box(liczba);
    }
    catch(exception&e)
    {
        throw range_error("brak");
    }

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
    if(ileJest<4)return;

    Box*lazSum=poczatek;
    Box*lazik=poczatek;
    Box*lazPrzed=NULL;
    int liczPow=ileJest/4;

    for(int l=0;l<liczPow;l++)
    {
        int suma=0;
        for(int i=0;i<4;i++)
        {
            suma=suma+lazSum->dane;
            if(lazSum->nast!=NULL)
                lazSum=lazSum->nast;
        }

        if(suma%2==0)
        {
            if(lazPrzed==NULL)
            {
                for(int w=0;w<2;w++)
                {
                    poczatek=poczatek->nast;
                    delete lazik;
                    lazik=poczatek;
                }
                lazPrzed=poczatek;
                lazik=lazSum;
                continue;
            }
            else
            {
                for(int r=0;r<2;r++)
                {
                    lazPrzed->nast=lazik->nast;
                    delete lazik;
                    lazik=lazPrzed->nast;
                }
                lazik=lazSum;
                continue;
            }
        }
        else if(suma%2!=0)
        {
            if(lazPrzed==NULL)
            {
                lazik=lazik->nast->nast;
                lazPrzed=poczatek->nast;
                for(int t=0;t<2;t++)
                {
                    lazPrzed->nast=lazik->nast;
                    delete lazik;
                    lazik=lazPrzed->nast;
                }
                continue;
            }
            else
            {
                lazPrzed=lazik->nast;
                lazik=lazik->nast->nast;
                for(int t=0;t<2;t++)
                {
                    lazPrzed->nast=lazik->nast;
                    delete lazik;
                    lazik=lazPrzed->nast;
                }
            }
            continue;
        }

        while(lazPrzed->nast!=lazSum)
        {
            lazPrzed=lazPrzed->nast;
        }
    }
}
