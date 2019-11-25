#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include <iostream>
#include <string>

using namespace std;

struct NIP
{
private:
    string _nip;
    string nazwa;
public:
    void setNIP(string A_nip){ _nip = A_nip;}
    void setNazwa(string _nazwa) {nazwa = _nazwa;}

    string getNazwa() { return nazwa; }
    string getNIP(){ return _nip; }
};
    string zdejmiPodatek(NIP _nip);
    bool cyfraKontroli(NIP _nip);

#endif
