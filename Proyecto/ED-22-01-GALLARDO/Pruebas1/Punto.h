#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;
class Punto {

private:
	int x;
	int y;

public:
	Punto(int x, int y);
	Punto();
	int getX();
	int getY();
};

#endif