#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "People.h"
using namespace std;

class Nodo {

private:
    People persona;
    Nodo* next;
    bool act; // booleano que tiene el estado si la persona a cambiado de punto, si ha cambiado de posicion es un true, en el caso de que no false;

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
    //cambia la variable act a false;
    void reset();
    //cambia la variabla act a true;
    void actualizar();
};

#endif 