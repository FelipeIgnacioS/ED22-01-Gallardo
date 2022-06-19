#ifndef ED22-01-GALLARDO_NODE_H
#define ED22-01-GALLARDO_NODE_H

Class Node{
    private:
    Person p;
    Node* next;

    public:
    Node (Person p);
    
    void setNext(Node* node);
    Node *getNext();
    People getPeople(People* p);
    ~Node();
    
};

#endif //ED22-01-GALLARDO_NODE_H