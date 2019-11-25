#include "spis_towar.h"
#include <iostream>

using namespace std;

void spis_tow::vstaw(Towar t)
{
    Node * newTow = new Node(t);
    if(pocz == nullptr)
    {
        pocz = newTow;
    }
    else if(pocz->dane <= t)
    {
        newTow->next = pocz;
        pocz = newTow;
    }
    else
    {
        Node * zaszuk = nullptr;
        Node * szuk = pocz;
        while(szuk != nullptr && t <= szuk->dane)
        {
            zaszuk = szuk;
            szuk = zaszuk->next;
        }
        newTow->next = szuk;
        zaszuk->next = newTow;
    }
    Size++;
}

void spis_tow::vstawRoznowartosciowo(Towar t)
{
    Node * newTow = new Node(t);
    if(pocz == nullptr)
    {
        pocz = newTow;
    }
    else
    {
        newTow->next = pocz;
        pocz = newTow;
    }
    Size++;
}

void spis_tow::skompresuj()
{
    if(pocz == nullptr && pocz->next == nullptr)
    {
        return;
    }
    else
    {
        Node * wsk = pocz;
        Node * przedwsk = pocz->next;
        while(przedwsk != nullptr)
        {
            if(wsk->dane.getKod() == przedwsk->dane.getKod())
            {
                wsk->dane.setIlosc(wsk->dane.getIlosc() + przedwsk->dane.getIlosc());
                wsk->next = przedwsk->next;
                delete przedwsk;
                Size--;
                przedwsk = wsk->next;
            }
            else
            {
                wsk = przedwsk;
                przedwsk = przedwsk->next;
            }
        }
    }
}

float spis_tow::zdejmiZaKodem(int n, float ile)
{
    if(pocz->dane.getKod() == n)
    {
        if(pocz->dane.getIlosc() - ile <= 0) /// *********************
        {
            Node * toDelete = pocz;
            float wart = pocz->dane.getIlosc();
            pocz = pocz->next;
            delete toDelete;
            Size--;
            return wart;
        }
        else
        {
            pocz->dane.setIlosc(pocz->dane.getIlosc() - ile);
        }
    }
    Node * przed_tmp = pocz;
    Node * tmp = pocz->next;
    while (tmp != nullptr)
    {
        if(tmp->dane.getKod() == n)
        {
            if(tmp->dane.getIlosc() - ile <= 0)
            {
                float wart = tmp->dane.getIlosc();
                przed_tmp->next = tmp->next;
                delete tmp;
                Size--;
                return wart;
            }
            else
            {
                tmp->dane.setIlosc(tmp->dane.getIlosc() - ile);
            }
        }
        przed_tmp = tmp;
        tmp = tmp->next;
    }
}

void spis_tow::wypisz()
{
    Node * tmp = pocz;
    while(tmp != nullptr)
    {
        cout<<"kod towaru = "<<tmp->dane.getKod()<<"\t"<<"ilosc towaru = "<< tmp->dane.getIlosc()<<endl;
        tmp = tmp->next;
    }
}

