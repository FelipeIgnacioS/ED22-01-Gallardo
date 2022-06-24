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
    People();
    People(cv::Rect&);
    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    int getYCentro();
    void sumL();
    void sumE();
    int getEntry();
    int getLeave();
    int getID();
 
};

#endif