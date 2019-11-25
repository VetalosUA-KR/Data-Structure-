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
    if(poczatek==NULL || ileJest<3) return;
    Box*lazik=poczatek;
    Box*lazPrzed=NULL;

    int powturzenia=ileJest/3;
    if(lazik->dane!=lazik->nast->dane)
    {
        for(int i=0;i<2;i++)
        {
            poczatek=poczatek->nast;
            delete lazik;
            lazik=poczatek;
            ileJest--;
        }
        lazik=poczatek->nast;
        lazPrzed=poczatek;
        powturzenia--;
    }

    for(int e=0;e<powturzenia;e++)
    {
        if(lazik->dane!=lazik->nast->dane)
        {
            if(lazPrzed==NULL) lazPrzed=poczatek;
            for(int i=0;i<2;i++)
            {
                lazPrzed->nast=lazik->nast;
                delete lazik;
                lazik=lazPrzed->nast;
                ileJest--;
            }
            lazPrzed=lazik;
            lazik=lazik->nast;
            continue;
        }
        else if(lazik->dane==lazik->nast->dane)
        {
            if(lazPrzed==NULL) lazPrzed=poczatek;
            lazik=lazik->nast;
            while(lazPrzed->nast!=lazik)lazPrzed=lazPrzed->nast;
            for(int i=0;i<2;i++)
            {
                lazPrzed->nast=lazik->nast;
                delete lazik;
                lazik=lazPrzed->nast;
                ileJest--;
            }
            continue;
        }
    }
}

void Sznur::przeniesSkrajne()
{
    int m=4;
    cout<<endl<<"podaj m: ";cin >> m;
    if(ileJest<2*m && ileJest%2==0)return;
    if(ileJest<2*m+1 && ileJest%2!=0)return;
    Box*lewa=poczatek;
    Box*prawa=poczatek->nast;
    Box*lazik=poczatek;
    Box*srodek=NULL;
    int powturzenia=ileJest/2-1;

    for(int i=0;i<powturzenia;i++)
    {
        lewa=lewa->nast;
        prawa=prawa->nast;
    }
    if(ileJest%2!=0)
    {
        srodek=prawa;
        prawa=prawa->nast;
    }

    if(ileJest%2==0)
    {
        for(int t=0;t<m;t++)
        {
            poczatek=poczatek->nast;
            lewa->nast=lazik;
            lazik->nast=prawa;
            prawa=lazik;
            lazik=poczatek;
        }
        lewa=poczatek;
        prawa=poczatek->nast;

        for(int i=0;i<powturzenia;i++)
        {
            lewa=lewa->nast;
            prawa=prawa->nast;
        }
        for(int o=0;o<=powturzenia-m;o++)
        {
            lewa->nast=prawa->nast;
            koniec->nast=prawa;
            prawa->nast=NULL;
            koniec=prawa;
            prawa=lewa->nast;
        }
    }
    else
    {
        for(int t=0;t<m;t++)
        {
            poczatek=poczatek->nast;
            lewa->nast=lazik;
            lazik->nast=srodek;
            srodek=lazik;
            lazik=poczatek;
        }
        lewa=poczatek;
        prawa=poczatek->nast;

        for(int i=0;i<powturzenia;i++)
        {
            lewa=lewa->nast;
            prawa=prawa->nast;
        }
        srodek=prawa;
        prawa=prawa->nast;
        for(int o=0;o<=powturzenia-m;o++)
        {
            srodek->nast=prawa->nast;
            koniec->nast=prawa;
            prawa->nast=NULL;
            koniec=prawa;
            prawa=srodek->nast;
        }
    }


}
