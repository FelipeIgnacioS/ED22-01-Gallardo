#include "People.h"

People::People() {
    xComienzo = 0;
    yComienzo = 0;
    xFin = 0;
    yFin = 0;
    xCentro = 0;
    yCentro = 0;
    entrys = 0;
    leaves = 0;
    id = 0;
}
People::People(cv::Rect& r) {
    xComienzo = r.x;
    yComienzo = r.y;
    xFin = r.x + r.width;
    yFin = r.y + r.height;
    xCentro = r.x + ((float)r.width / 2.0);
    yCentro = r.y + ((float)r.height / 2.0);;
    entrys = 0;
    leaves = 0;
    id = 0;
}

People::People(int xc, int yc, int x, int y, int xf, int yf) {
    xComienzo = xc;
    yComienzo = yc;
    xFin = xf;
    yFin = yf;
    xCentro = x;
    yCentro = y;
    entrys = 0;
    leaves = 0;
    id = 0;
}

int People::getXComienzo() {
    return xComienzo;
}

int People::getYComienzo() {
    return yComienzo;
}

int People::getXFin() {
    return xFin;
}

int People::getYFin() {
    return yFin;
}

int People::getXCentro() {
    return xCentro;
}

int People::getYCentro() {
    return yCentro;
}

void People::sumE() {
    entrys++;
}
void People::sumL() {
    leaves++;
};
int People::getEntry() {
    return entrys;
}
int People::getLeave() {
    return leaves;
}
int People::getID() {
    return id;
}

void People::setID(int i) {
    this->id = i;
}

void People::actualizarPuntos (int xc, int yc, int x, int y, int xf, int yf){
    xComienzo = xc;
    yComienzo = yc;
    xFin = xf;
    yFin = yf;
    xCentro = x;
    yCentro = y;
}