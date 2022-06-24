#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Nodo.h"

class LinkedList {
private:
	Nodo* first;
	int sizel;

public:
	LinkedList();
	~LinkedList();
	bool empty();
	int size();
	void add(Nodo* n);
	void add_ord_entry(Nodo* n);
	void add_ord_leave(Nodo* n);
	bool exists(Nodo* n);
	void ordenarEntriess();
	void ordenarLeaves();
	void MostrarPersonasL(int cant);
	void MostrarPersonasE(int cant);
};

#endif // !LINKEDLIST_H
