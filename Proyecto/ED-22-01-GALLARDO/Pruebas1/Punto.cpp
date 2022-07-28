#include "Punto.h"
using namespace std;


Punto::Punto(int xc, int yc, int x, int y, int xf, int yf) {
	xComen = xc;
	yComen = yc;
	xCen = x;
	yCen = y;
	xFin = xf;
	yFin = yf;
}

Punto::Punto() {
	xComen = 0;
	yComen = 0;
	xCen = 0;
	yCen = 0;
	xFin = 0;
	yFin = 0;
}


int Punto::getXc() {
	return xComen;
}

int Punto::getYc() {
	return yComen;
}

int Punto::getX() {
	return xCen;
}

int Punto::getY() {
	return yCen;
}

int Punto::getXf() {
	return xFin;
}

int Punto::getYf() {
	return yFin;
}

