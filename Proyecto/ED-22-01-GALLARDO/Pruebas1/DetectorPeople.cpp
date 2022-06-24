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

int main(int argc, char** argv)
{

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

    return 0;
}