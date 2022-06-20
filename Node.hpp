#ifndef ED22-01-GALLARDO_NODE_H
#define ED22-01-GALLARDO_NODE_H
#include "People.hpp"

class Node{
    private:
    People p;
    Node* next;

    public:
    Node (People p);
    
    void setNext(Node* node);
    Node *getNext();
    People getPeople(People* p);
    ~Node();
    
};

#endif //ED22-01-GALLARDO_NODE_H