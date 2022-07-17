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
bool LinkedList::exists(Nodo* n) {
	Nodo* aux = first;
	if (aux->getPeople().getID() == n->getPeople().getID()) return false;

	while (aux->getNext() != nullptr) {
		if (aux->getPeople().getID() == n->getPeople().getID())return false;
		aux = aux->getNext();
	}return true;
}
void LinkedList::ordenarEntriess()
{
	Nodo* current = first;
	Nodo* index = nullptr;
	People temp;
	if (first == nullptr)return;

	else {
		while (current != nullptr) {
			index = current->getNext();
			while (index != nullptr) {
				if (current->getPeople().getEntry() < index->getPeople().getEntry()) {
					temp = current->getPeople();
					current->setPeople(index->getPeople());
					index->setPeople(temp);
				}
				index = index->getNext();
			}
			current = current->getNext();
		}
	}
}

void LinkedList::ordenarLeaves()
{
	Nodo* current = first;
	Nodo* index = nullptr;
	People temp;
	if (first == nullptr)return;
	else {
		while (current != nullptr) {
			index = current->getNext();
			while (index != nullptr) {
				if (current->getPeople().getLeave() < index->getPeople().getLeave()) {
					temp = current->getPeople();
					current->setPeople(index->getPeople());
					index->setPeople(temp);
				}
				index = index->getNext();
			}
			current = current->getNext();
		}
	}
}

void LinkedList::MostrarPersonasE(int cant)
{
	ordenarEntriess();
	if (cant < sizel) {
		printf("La cantidad requerida es mayor que la cantidad de personas que han entrado ");
	}
	else {
		Nodo* current = first;
		if (first == nullptr) {
			printf("No hay personas en la lista");
			return;
		}
		for (int i = 0; i < cant; i++)
		{
			People p = current->getPeople();
			printf("La persona de id: ", p.getID(), "Ha entrado: ", p.getEntry(), " veces\n");
			current = current->getNext();
		} 
	}
}
void LinkedList::MostrarPersonasL(int cant)
{
	ordenarLeaves();
	if (cant < sizel) {
		printf("La cantidad requerida es mayor que la cantidad de personas que han salido ");
	}
	else {
		Nodo* current = first;
		if (first == nullptr) {
			printf("No hay personas en la lista");
			return;
		}
		for (int i = 0; i < cant; i++)
		{
			People p = current->getPeople();
			printf("La persona de id: ", p.getID(), "Ha salido: ", p.getLeave(), " veces\n");
			current = current->getNext();
		}
	}
}

LinkedList::~LinkedList() {}