#ifndef ED22-01-GALLARDO_LINKEDLIST_H
#define ED22-01-GALLARDO_LINKEDLIST_H
#include "Node.hpp"

class LinkedList{
    private:
    Node* first;

    public:
    LinkedList(Node node);
    bool empty();
    int size();
};

#endif
