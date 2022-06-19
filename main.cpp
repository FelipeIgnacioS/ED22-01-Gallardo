#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.hpp"
#include "People.hpp"

using namespace cv;
using namespace std;


void sortListsHigher(LinkedList* l){

}


int main(int argc, char** argv)
{
    /*
    Detector detector;
    Mat imagen;
    imagen = imread("");
    detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<People> found = detector.detect(imagen);
    for (vector<People>::iterator i = found.begin(); i != found.end(); ++i)
    {
        People &p = *i;
        cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;
        //detector.adjustRect(r);
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
    }
    
    imshow("People detector", imagen);
    waitKey(0);
    */

        //requerimientos
    int countLeave; //contador de personas que salen
    int countEntry; //contador de personas que entran
    int entryDifferent; //contador de personas distintas que entran
    int leaveDifferent; //contador de personas distintas que salen
    int countHours; //contador del tiempo
    // LinkedList Entrys = new LinkedList(); //lista que contienen a las personas que han entrado
    // LinkedList Leaves = new LinkedList(); //lista que contiene a las personas que han salido
    // LinkedList EntrysDiff = new LinkedList(); //lista de personas unicas que entran

    return 0;
 }