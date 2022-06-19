#include "People.hpp"

People::People(cv::Rect&){
    xComienzo = r.x;
    yComienzo = r.y;
    xFin = r.x + r.width;
    yFin = r.y + r.height;
    xCentro = r.x + ((float)r.width/2.0);
    yCentro = r.y + ((float)r.height/2.0);;
}

int People::getXComienzo(){
    return xComienzo;
}

int People::getYComienzo(){
    return yComienzo;
}

int People::getXFin(){
    return xFin;
}

int People::getYFin(){
    return yFin;
}

int People::getXCentro(){
    return xCentro;
}

int People::getYCentro(){
    return yCentro;
}

void People::sumEntry(){
    this->entry++;
}
void People::sumLeave(){
    this->leave++;
}