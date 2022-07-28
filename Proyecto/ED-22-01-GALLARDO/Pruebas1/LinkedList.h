#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Nodo.h"

class LinkedList {
private:
	Nodo* first;
	int sizel;

public:
	LinkedList(); //constructor de la LinkedList
	~LinkedList(); //destructor de la LinkedList
	bool empty(); //Devuelve un booleano, true si la lista esta vacia, false si tiene algun elemento
	int size(); //Devuelve la cantidad de elementos en una lista
	void add(Nodo* n); //agrega un nodo a la lista
	bool exists(Nodo* n); // pregunta si existe algun elemento en la lista
	void ordenarEntriess(); //ordena la lista de mayor a menor segun la cantidad de entradas
	void ordenarLeaves(); //ordena la lista de mayor a menor segun la cantidad de salidas
	void MostrarPersonasL(int cant); //imprime  x cantidad de elementos de la lista por orden de salidas
	void MostrarPersonasE(int cant); //imprime  x cantidad de elementos de la lista por orden de entradas
	Nodo* getNodo(int a);
	void Reset();
	void del(int d);
};

#endif // !LINKEDLIST_H
