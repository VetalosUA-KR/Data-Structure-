#ifndef Process_znany

#define Process_znany
struct Process {
  private:
      unsigned int PID;
      unsigned int l_watkow;
  public:
    Process(int p = 0, int l_w = 1);
    /// gettery:
    int getPID();
    int getL_wantwos();
    /// settery:
    void setPID(int p);
    void setWantki(int lw);
};
#endif
