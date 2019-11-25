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
    try
    {
        nowy=new Box(liczba);
    }
    catch(exception&e)
    {
        throw range_error("nie mozna dopisac");
    }

    if(poczatek==NULL)
    {
        poczatek=nowy;
        koniec=nowy;
    }
    else
    {
        if(liczba>=poczatek->dane)
        {
            nowy->nast=poczatek;
            poczatek=nowy;
        }
        else if(liczba<=koniec->dane)
        {
            koniec->nast=nowy;
            koniec=nowy;
        }
        else
        {
            Box*lazik=poczatek->nast;
            Box*lazP=poczatek;
            while(true)
            {
                if(lazP->dane>=liczba && lazik->dane<=liczba)
                {
                    lazP->nast=nowy;
                    nowy->nast=lazik;
                    break;
                }
                lazP=lazP->nast;
                lazik=lazik->nast;
            }

        }
    }
    ileJest++;
}


void Sznur::usun()
{
    if(poczatek==NULL || ileJest<4) return;
    Box*lazik=poczatek;
    Box*lazPrzed=NULL;
    Box*skoczek=poczatek;
    int sumaSkr=0;
    int sumaSr=0;

    int powturzenia=ileJest/4;

    for(int i=0;i<powturzenia;i++)
    {
        sumaSkr=0;
        sumaSr=0;
        if(lazPrzed==NULL)
        {
            for(int e=0;e<4;e++)
            {
                if(e==0 || e==3) sumaSkr=sumaSkr+skoczek->dane;
                if(e==1 || e==2) sumaSr=sumaSr+skoczek->dane;

                if(skoczek->nast!=NULL) skoczek=skoczek->nast;
            }
            if(sumaSkr==sumaSr)
            {
                for(int r=0;r<4;r++)
                {
                    lazik=lazik->nast;
                    delete poczatek;
                    poczatek=lazik;
                }
            }
            else
            {
                poczatek=poczatek->nast;
                delete lazik;
                lazik=poczatek->nast->nast;
                poczatek->nast->nast=skoczek;
                delete lazik;
                lazik=skoczek;
                lazPrzed=poczatek->nast;
            }
        }
        else
        {
            for(int e=0;e<4;e++)
            {
                if(e==0 || e==3) sumaSkr=sumaSkr+skoczek->dane;
                if(e==1 || e==2) sumaSr=sumaSr+skoczek->dane;

                if(skoczek->nast!=NULL) skoczek=skoczek->nast;
            }

            if(sumaSkr==sumaSr)
            {
                for(int r=0;r<4;r++)
                {
                    lazPrzed->nast=lazik->nast;
                    delete lazik;
                    lazik=lazPrzed->nast;
                }
            }

            else
            {
                lazPrzed->nast=lazik->nast;
                delete lazik;
                lazik=lazPrzed->nast->nast->nast;
                lazPrzed->nast->nast->nast=skoczek;
                delete lazik;
                lazik=skoczek;
                lazPrzed=lazPrzed->nast->nast;
            }

        }

    }

}
