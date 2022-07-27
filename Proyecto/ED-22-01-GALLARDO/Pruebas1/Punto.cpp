#include "Punto.h"
using namespace std;

Punto::Punto(int a, int b) {
	x = a;
	y = b;
}

Punto::Punto() {
	x = 0;
	y = 0;
}

int Punto::getX() {
	return x;
}
int Punto::getY() {
	return y;
}