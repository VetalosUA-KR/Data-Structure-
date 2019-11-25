
#ifndef STOSY_TAB_ZNANE
#define STOSY_TAB_ZNANE
struct Stos {
  private:
      int max_rozmiar_stosu;
      int * dane;
      int ileJest;

  public:
    Stos(int mrs);
    ~Stos();
    void wypisz();
    void wloz(int a);
    int zdejmi();
    int rozmiarStosu();
};
#endif // STOSY_TAB_ZNANE
