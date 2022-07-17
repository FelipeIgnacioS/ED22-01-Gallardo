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

    //Enlazar el proximo del nodo actual
    void setNext(Nodo* Nodo);
    //obtener el nodo anidado al actual
    Nodo* getNext();
    //obtener el objeto persona del nodo
    People getPeople();
    //eliminar nodo
    ~Nodo();
    //agregar personas
    void setPeople(People p);
};

#endif 