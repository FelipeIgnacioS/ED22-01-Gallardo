#ifndef PEOPLE_H
#define PEOPLE_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class People
{
private:
    int xComienzo; 
    int yComienzo; 
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
    int entrys;
    int leaves;
    int id;

public:
    People(); //constructor sin parametros
    People(cv::Rect&); //constructor con entrada de rectangulo de la persona
    People(int xc, int yc, int x, int y, int xf, int yf);//ingresando los puntos manualmente;
    int getXComienzo(); 
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    int getYCentro();
    void sumL(); //sumar una entrada
    void sumE(); //sumas una salida
    int getEntry(); //obtener cantidad de entradas
    int getLeave(); //obtener cantidad de salidas
    int getID(); //obtener identificador de la persona
    void setID(int i);
    void actualizarPuntos(int xc, int yc, int x, int y, int xf, int yf);
};

#endif