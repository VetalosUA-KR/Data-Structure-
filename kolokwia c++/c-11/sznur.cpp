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
        cout<<lazik->dane<<", ";
        lazik=lazik->nast;
    }
}

void Sznur::wstaw(int liczba)
{
    Box*nowy;
    try
    {nowy=new Box(liczba);}
    catch(exception&e){throw range_error("sznur pelen");}
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

Sznur::~Sznur()
{
    Box*kiler;
    while(poczatek==NULL)
    {
        kiler=poczatek;
        poczatek=poczatek->nast;
        delete kiler;
    }
    koniec=NULL;
    ileJest=0;
}

void Sznur::usun()
{
    Box*lazik;
    lazik=poczatek;
    Box*skoczek=poczatek;
    Box*lazik0=NULL;
    while(skoczek->nast!=NULL)
    {
        int mini=skoczek->dane;
        for(int i=0;i<3;i++)
        {
            if(skoczek->dane<mini)
            {
                mini=skoczek->dane;
            }
            if(skoczek->nast!=NULL)
                skoczek=skoczek->nast;
        }

        for(int e=0;e<3;e++)
        {
            if(poczatek->dane>mini && lazik0==NULL)
            {
                poczatek=poczatek->nast;
                delete lazik;
                if(lazik->nast!=NULL)
                lazik=poczatek->nast;
                continue;
            }
            if(lazik->dane>mini && lazik!=poczatek)
            {
                if(poczatek->nast==lazik)
                {
                    if(lazik->nast!=NULL)
                        poczatek->nast=lazik->nast;
                    else poczatek->nast=NULL;
                    delete lazik;
                    if(poczatek->nast!=NULL)
                        lazik=poczatek->nast;
                    lazik0=poczatek;
                    continue;
                }
                else if(lazik->dane>mini)
                {
                    if(lazik->nast!=NULL)
                        lazik0->nast=lazik->nast;
                    else lazik0->nast=NULL;
                    delete lazik;
                    if(lazik0->nast!=NULL)
                    lazik=lazik0->nast;
                    continue;
                }
                continue;
            }
            else
            {
                lazik0=lazik;
                if(lazik->nast!=NULL)
                lazik=lazik->nast;
            }
        }
        lazik=skoczek;
    }
}
