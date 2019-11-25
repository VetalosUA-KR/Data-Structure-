struct kolejka
{
private:
    struct KolejkaNode
    {
        ///binary_tree.Node * bNode;
        KolejkaNode * next;
        KolejkaNode(KolejkaNode * n = nullptr)
        {
            ///bNode = bn;
            next = n;
        }
    };


public:
    KolejkaNode * head = nullptr;
    kolejka()=default;
    void addElement(/**binary_tree.Node * bn*/);
    void pop();
};
