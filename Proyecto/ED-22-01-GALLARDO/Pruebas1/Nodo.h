#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "People.h"
using namespace std;

class Nodo {

private:
    People persona;
    Nodo* next;

public:
    Nodo();
    Nodo(People p);

    void setNext(Nodo* Nodo);
    Nodo* getNext();
    People getPeople();
    ~Nodo();

};

#endif 