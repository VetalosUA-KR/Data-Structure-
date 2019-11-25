#include<iostream>
#include "bib_macierza.h"

using namespace std;

Macierz::Macierz(int w, int k)
{
    /*kolumn = kol;
    wiersz = wier;
    macierz[wier][kol];
    //macierz[0][0] = 10;
    cout<<&macierz[0][0]<<endl;
    cout<<&macierz[0][0]<<endl;
    cout<<&macierz[0][1]<<endl;
    cout<<&macierz[1][0]<<endl;*/
    t = new double *[W=w];
    for(int i = 0; i < W; i++)
    {
        t[i] = new double[K=k];
    }
}

Macierz::~Macierz()
{
    for(int i = 0; i < W; i++)
    {
        delete [] t[i];
    }
    delete [] t;
}

void Macierz::zapisz()
{
    cout<<"Podaj liczby do macierzy"<<endl;
    int l;
    for(int w = 0; w < W; w++)
    {
        for(int k = 0; k < K; k++)
        {
            cin>>l;
            t[w][k] = l;
        }
    }
}

void Macierz::wypisz()
{
    for(int w = 0; w < W; w++)
    {
        for(int k = 0; k < K; k++)
        {
            cout<<t[w][k]<<" ";
        }
        cout<<endl;
    }
}
