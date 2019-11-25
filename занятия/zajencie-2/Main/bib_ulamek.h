#ifndef BIB_ULAMEK
#define BIB_ULAMEK
struct Ulamek
{

    private:
    int licz; /// должны ли они быть публичными ?
    int mian;

    public:
    Ulamek (int l=0, int m=1);
    void wypisz();
    void skroc();
    void ulamekDoWspolnegoMianownika(int ul1, int ul2);

    /// перегрузка операторов
    bool operator == (Ulamek u);    ///     +
    bool operator > (Ulamek u);     ///     +
    bool operator < (Ulamek u);     ///     +

    Ulamek operator + (Ulamek u);   ///     +
    Ulamek operator - (Ulamek u);   ///     +
    Ulamek operator * (Ulamek u);   ///     +
    Ulamek operator / (Ulamek u);   ///     +
};
#endif // BIB_ULAMKI

