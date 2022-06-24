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

};

#endif // !LINKEDLIST_H
