struct Towar
{
    private:
    int kod;
    float ilosc;

    public:

        bool operator <= (Towar t);
        void wypiszTowar();
        Towar(int k = 0, float il = 0)
        {
            kod = k;
            ilosc = il;
        }

        /// getters
        int getKod() { return kod; }
        float getIlosc() { return ilosc; }

        /// setters
        void setIlosc(float ile) { ilosc = ile; }
};

