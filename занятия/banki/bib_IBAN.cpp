#include <iostream>
#include <string>
#include "bib_IBAN.h"
#include "bib_lista.h"
#include <cstdlib>

bool czyIBAN(IBAN ib)
{
    string argumentKontroli = ib.getNumerKonta().substr(0,2);
    string numerKonta = ib.getNumerKonta().substr(2,26);
    if(/*argumentKontroli == "PL" && */numerKonta.length()==26)
    {
        for(int i = 0; i < numerKonta.length(); i++)
        {
            int dig = numerKonta[i]-'0';
            if(dig < 0 || dig > 9)
            {
                return false;
            }
        }
        return true;
    }
    else {return false;}
}

bool IBAN::operator < (IBAN ib)
{
    string argumentKontroli = ib.numerKonta.substr(2, 2);
    string thisKontroli = this->numerKonta.substr(2, 2);
    int ak = stoi(argumentKontroli);
    int tk = stoi(thisKontroli);


    if(tk <= ak)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool IBAN::operator > (IBAN ib)
{
    string argumentKontroli = ib.numerKonta.substr(2, 2);
    string thisKontroli = this->numerKonta.substr(2, 2);
    int ak = stoi(argumentKontroli);
    int tk = stoi(thisKontroli);


    if(tk <= ak)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool sprawdzanieCyfryKontroliIBAN(IBAN ib)///&
{
    /// - 7
    if(ib.getNumerKonta().length() == 28)
    {
        string numKota = ib.getNumerKonta();
        string KK = numKota.substr(2,2);
        string d1 = numKota.substr(0,1);
        string d2 = numKota.substr(1,1);
        int chislo1 = d1[0]-55;
        int chislo2 = d2[0]-55;
        //cout<<numKota<<endl;
        //cout<<chislo1<<endl;
        string itog = numKota.substr(4, 28)+to_string(chislo1)+to_string(chislo2)+KK;
        //cout<<itog<<endl;
        //cout<<"d1 = "<<d1[0]-'0'<<"\t d2 = "<<d2[0]-'0'<<endl;
        int liczba = itog[0]-'0';
        for(unsigned i = 1; i < itog.length(); i++)
        {
            liczba = liczba*10+itog[i]-'0';
            liczba = liczba%97;
        }
        cout<<liczba<<endl;


    }







}





