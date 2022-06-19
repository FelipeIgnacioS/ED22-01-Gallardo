#ifndef PEOPLE_H
#define PEOPLE_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class Persona
{
private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
public:
    Persona(cv::Rect&);

    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    int getYCentro();
};

#endif