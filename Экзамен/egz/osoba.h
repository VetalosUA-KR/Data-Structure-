#ifndef bib_IBAN_znany
#define bib_IBAN_znany
#include <string>

using namespace std;

struct Osoba
{
private:
    string name;
    string surname;
    string pesel;
    string denU;

public:

    void setName(string n){name = n;}
    void setSurname(string sn){surname = sn;}
    void setPesel(string p){pesel = p;}
    void setDenU(string u){denU = u;}

    string getName(){return name;}
    string getSurname(){return surname;}
    string getPesel(){return pesel;}
    string getD(){return denU;}

bool operator < (Osoba &osoba);
bool operator > (Osoba &osoba);
int getDate(string pes);
};
string getDU(string pes);

#endif
