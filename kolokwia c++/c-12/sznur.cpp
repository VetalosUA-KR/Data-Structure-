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
    Box*lazik=poczatek;
    while(lazik!=NULL)
    {
        cout<<lazik->dane<<" ";
        lazik=lazik->nast;
    }
}

void Sznur::wstaw(int liczba)
{
    Box*nowy;
    try{nowy=new Box(liczba);}
    catch (exception&e){throw range_error("brak miejsca");}

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

void Sznur::usun(int k,int m)
{
    if(poczatek!=NULL)
    {
        Box*lazik=poczatek;
        Box*skoczek;
        Box*lazik0;
        for(int i=0;i<m;i++)
        {
            poczatek=poczatek->nast;
            delete lazik;
            lazik=poczatek;
            if(poczatek==NULL)return;
        }

        skoczek=poczatek;
        lazik0=poczatek;
        while(lazik->nast!=NULL)
        {
            int wieksze=0;
            while(skoczek!=NULL)
            {
                if(skoczek->dane>k)
                {
                    wieksze++;
                }

                if(wieksze>=2)
                {
                    if(skoczek->nast!=NULL)
                        skoczek=skoczek->nast;
                    break;
                }
                skoczek=skoczek->nast;
                if(skoczek==NULL)return;
            }
            lazik=skoczek;
            while(lazik0->nast!=skoczek)
            {
                if(lazik0->nast!=NULL)
                    lazik0=lazik0->nast;
            }
            for(int i=0;i<m;i++)
            {
                lazik0->nast=lazik->nast;
                delete lazik;
                lazik=lazik0->nast;
                if(lazik==NULL)
                {
                    skoczek=NULL;
                    return;
                }
                skoczek=lazik;
            }
        }
    }
}
