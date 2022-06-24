#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include "Detector.h"
#include "People.h"

using namespace cv;
using namespace std;

int main()
{
    int entrys = 0;
    int leaves = 0;
    float horas; //time[s] /3600
    int entriesDiff = 0;
    int leavesDiff = 0;

    Detector detector;
    Mat imagen;
    imagen = imread("");
    detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<People> found = detector.detect(imagen);
    for (vector<People>::iterator i = found.begin(); i != found.end(); ++i)
    {
        People& p = *i;
        cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;

        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
    }

    imshow("People detector", imagen);
    waitKey(0);

    linkedList personasDistintas = new LinkedList();
    linkedList personasDistintasEntries = new LinkedList();
    LinkedList personasDistintasLeaves = new LinkedList();

    /*contador de personas
    Persona p = new Persona();
    Nodo n = new Nodo(p);
    if (!personasDistintas.exits(n)){
        personasDistintas.add(p);
    }
    //entrada

    if(personasDistintasEntries.exists(n)){
        p.sumE();
    }else{
        personasDistintasEntries.add_ord_entry(p);
        p.sumE;
        entrysDiff++;
    }entrys++;

    //salida
     if(personasDistintasLeaves.exists(n)){
        p.sumL();
    }else{
        personasDistintasLeaves.add_ord_leave(p);
        p.sumL();
        leavesDiff++;
    }leaves++;

    */
    return 0;
}