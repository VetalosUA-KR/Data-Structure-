#ifndef BIB_MACIERZ
#define BIB_MACIERZ
struct Macierz
{
    int W;
    int K;
    double ** t;

    Macierz(int w=0, int k=0);
    ~Macierz();
    void wypisz();
    void zapisz();
};
#endif //
