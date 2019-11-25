#ifndef bib_IBAN_znany
#define bib_IBAN_znany
#include <iostream>
#include <string>


using namespace std;

struct IBAN
{
private:
    string numerKonta;
public:
    bool operator < (IBAN ib);
    bool operator > (IBAN ib);

    void setIBAN(string _iban){numerKonta = _iban;}

    string getNumerKonta(){return numerKonta;}
};

bool czyIBAN(IBAN ib);
bool sprawdzanieCyfryKontroliIBAN(IBAN ib);
#endif // bib_IBAN_znany

