struct Kolejka
{
private:
    int * dane;
    int ileJest;

public:
    Kolejka();
    ~Kolejka();

    void wypisz();
    void wstaw(int a);
    void ocyscTablice();

    int zdejmi();
    int rozmiarTablicy();
};
