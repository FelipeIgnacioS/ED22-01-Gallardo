#include "Nodo.h"

using namespace std;

Nodo::Nodo() {

}

Nodo::Nodo(People p) {
	persona = p;
	next = nullptr;
}

void Nodo::setNext(Nodo* Nodo)
{
	next = Nodo;
}

Nodo* Nodo::getNext() {
	return next;
}

People Nodo::getPeople() {
	return persona;
}

Nodo::~Nodo(){}

void Nodo::setPeople(People p)
{
	this->persona = p;
}
