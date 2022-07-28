#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;
class Punto {

private:
	int xComen;
	int yComen;
	int xCen;
	int yCen;
	int xFin;
	int yFin;

public:
	Punto(int xc, int yc, int x, int y, int xf, int yf);
	Punto();
	int getXc();
	int getYc();
	int getX();
	int getY();
	int getXf();
	int getYf();
};

#endif