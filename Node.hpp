#ifndef ED22-01-GALLARDO_NODE_H
#define ED22-01-GALLARDO_NODE_H
#include "People.hpp"

class Node{
    private:
    People persona;
    Node* next;

    public:
    Node (People p);
    
    void setNext(Node* node);
    Node *getNext();
    People getPeople();
    ~Node();
    
};

#endif //ED22-01-GALLARDO_NODE_H