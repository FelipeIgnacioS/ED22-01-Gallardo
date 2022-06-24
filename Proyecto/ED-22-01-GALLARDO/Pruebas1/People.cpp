#include "People.h"

People::People() {

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
