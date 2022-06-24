#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	first = nullptr;
	sizel = 0;
}

bool LinkedList::empty() {
	if (sizel == 0)return true;
	return false;
}

int LinkedList::size() {
	return sizel;
}

void LinkedList::add(Nodo* newNode) {
	Nodo* aux = first;
	if (!first) {
		first = newNode;
	}
	else {
		newNode->setNext(first);
		first = newNode;
		while (aux) {
			aux = aux->getNext();
		}
	}
	sizel++;
}
void LinkedList::add_ord_entry(Nodo* n) {
	Nodo* aux = first;

	if (!first) {
		first = n;
	}
	else {
		People p1 = first->getPeople();
		People p2 = n->getPeople();
		if (p1.getEntry() > p2.getEntry()) {
			n->setNext(first);
			first = n;
		}
		else {
			while ((aux->getNext() != nullptr) && (aux->getNext()->getPeople().getEntry() < p2.getEntry())) {
				aux = aux->getNext();
			}
		}
	}sizel++;
}

void LinkedList::add_ord_leave(Nodo* n) {
	Nodo* aux = first;

	if (!first) {
		first = n;
	}
	else {
		People p1 = first->getPeople();
		People p2 = n->getPeople();
		if (p1.getLeave() > p2.getLeave()) {
			n->setNext(first);
			first = n;
		}
		else {
			while ((aux->getNext() != nullptr) && (aux->getNext()->getPeople().getLeave() < p2.getLeave())) {
				aux = aux->getNext();
			}
		}
	}sizel++;
}

LinkedList::~LinkedList() {}

