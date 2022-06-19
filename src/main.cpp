#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    Mat image;
    image = imread("C:/Users/pipen/Downloads/4155.png");
    if ( !image.data )
    {
        //Indicar un error
        printf("No image data \n");
        return -1;
    }
    namedWindow("Mi ventana", WINDOW_AUTOSIZE );

    imshow("Mi ventana", image);

    waitKey(0);

    return 0;

}