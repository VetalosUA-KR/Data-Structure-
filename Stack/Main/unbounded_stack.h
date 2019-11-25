#ifndef Stack_H
#define Stack_H

struct Stack {

private:

    struct Node
    {
        int value;
        Node* next;
        Node(int v, Node* n = nullptr)
        {
            value = v;
            next = n;
        }
    };

    Node* head = nullptr;
    int counter = 0;

    //invariants:
    //if nonempty, head points to the first node (it contains the top value)
    //the next for the first node points to the second node, etc.
    //the next for the last node is null
    //counter is at least 0 (empty stack) and it is the number of nodes (size of the stack)

public:

    //constructors
    Stack() = default;
    //pre: none
    //post: the stack is empty

    Stack(const Stack&);
    //pre: none
    //post: the stack is the copy of the argument

    //destructor

    ~Stack();
    //pre: none
    //post: none

    //modifiers

    void push(int val);
    //pre: none
    //post: the argument value is on top, size is increased by 1

    int pop();
    //pre: the stack is not empty
    //post: the top value is removed,Stack size is decreased by 1
    //return: the top value

    void clear();
    //pre: none
    //post: the stack is empty

    //selectors

    int top() const;
    //pre: the stack is not empty
    //return: the top value

    int size() const;
    //pre: none
    //return: the current size of the stack

    void print() const;
    //pre: none
    //return: none, the contents of the stack is printed, from top to bottom

    //queries

    bool empty() const;
    //pre: none
    //return: true if the stack is empty, false otherwise

    //operators
    int operator [](const int index);

    Stack& operator=(const Stack&);
    //pre: none
    //post: the stack is the copy of the argument
    //return: the reference to the stack

    void operator==(const Stack&) const;
    //pre: none
    //return: true if the contents of the stack is the same as the contents of the argument, false otherwise

};

#endif

