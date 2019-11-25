struct list_sort{
  private:
      struct Node {
        int data;
        Node * next;
        Node (int d = 0, Node * n = nullptr)
        {
            data = d;
            next = n;
        }
      }  ;
    Node * first = nullptr;
    int Size = 0;
  public:
    list_sort() = default;
    ~list_sort();
    void wypisz();
    void addELement(int data);


    void deletElement(int data);
    void deletWszystkieElement(int data);
};
