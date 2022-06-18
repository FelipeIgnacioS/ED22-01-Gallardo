#ifndef ED22-01-GALLARDO_NODE_H
#define ED22-01-GALLARDO_NODE_H

Class Node{
    private:
    Persona persona;
    Node* next;

    public:
    Node();
    Node (Persona p);
    
    void setNext(Node* node);
    Node *getNext();
    ~Node();
    
};

#endif //ED22-01-GALLARDO_NODE_H