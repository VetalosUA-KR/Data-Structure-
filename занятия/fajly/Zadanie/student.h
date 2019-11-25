#include <string>

using namespace std;
struct student
{
private:
    string ime;
    string nazwisko;
    int numer_indeksu;
    int rok_studiow;
    int wiek;
    float srednia_ocena;
public:
    student(string i = "ime", string n = "nazwisko", int ni = 0, int rs = 0, int w = 0, float so = 0)
    {
        ime = i;
        nazwisko = n;
        numer_indeksu = ni;
        rok_studiow = rs;
        wiek = w;
        srednia_ocena = so;

    }
    void dopiszDoPliku(string nazwaPliku);

    void setName(string n) {ime = n;}
    void setNazwisko(string n){nazwisko = n;}
    void setNumer_indeksu(int n){ numer_indeksu = n;}
    void setRok_studiow(int n){rok_studiow = n;}
    void setWiek(int n){ wiek = n;}
    void setSrednia_ocena(float n){ srednia_ocena = n;}
    void wypiszPolaStudenta();
};

void wypiszLudziZRoku(string nazwaPliku, int rok);
float sredniaWiekuOsub(string nazwaPliku);
student najwiekszaSrednia(string nazmwaPliku);
void upozadkujWedlugIndeksu(string plikWej, string plikWyn);
