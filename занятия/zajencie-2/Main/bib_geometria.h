#ifndef BIB_GEOMETRIA
#define BIB_GEOMETRIA

struct Punkt {

    int x;
    int y;

    Punkt(int _x = 0, int _y = 0);
    //Punkt();

    void wypis();
};

struct Prosta{
    int a;
    int b;

    Prosta(int _a = 0, int _b = 0);

    bool czyPunktLezeNaProstej(Punkt p1);
    Prosta prostaPrzez_2_punkty(Punkt p1, Punkt p2);
    void wypis();

};
#endif
