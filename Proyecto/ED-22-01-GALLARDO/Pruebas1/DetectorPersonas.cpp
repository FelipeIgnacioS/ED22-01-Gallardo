#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.h"
#include "People.h"
#include "LinkedList.h"
#include "Nodo.h"
#include "Punto.h"

using namespace cv;
using namespace std;



void detector()
{
    int entrys = 0; //entradas del lugar
    int leaves = 0; //saldias del lugar
    float horas;
    int cantImagenes = 21;
    LinkedList l1 = LinkedList(); //almacenara las # id para columnas
    vector<Punto> l2; //almacenara los centroides

    int id = 1;
    for (size_t i = 0; i < cantImagenes; i++) //cantiadad de frames a analizar // fotos // videos
    {
        Detector detector;
        Mat imagen;
        imagen = imread(""); //insertar imagenes
        detector.toggleMode();
        cout << detector.modeName() << endl;
        //vector<People> found = detector.detect(imagen);
        LinkedList* lista1 = new LinkedList();
        *lista1 = detector.detect(imagen);
        l1.Reset(); //hacemos un reset de las variables para saber si estan actualizadas o no
        
        for ( i = 0; i < lista1->size(); i++)
        {
            People p = lista1->getNodo(i)->getPeople();
            rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
            circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
            Punto punto = Punto(p.getXCentro(), p.getYCentro());
        }
        
        /*
        for (vector<People>::iterator i = found.begin(); i != found.end(); ++i)
        {
            People& p = *i;
            rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
            circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);    
            Punto punto = Punto(p.getXCentro(), p.getYCentro());
            l2.push_back(punto); //agregamos a un vector el punto
            Nodo* n = new Nodo(p); //creamos un nodo con la persona
            l1.add(n); //agregamos una persona a la lista
            p.setID(id); //asignamos un id a la persona
            id++;
        }
        int a = l2.size();
        int b = l1.size();
        float matriz[a][b]; //matriz que contendra las distancias entre #id y centroides
        


        //llenar la matriz que contendra las distancias entre centroides encontrados, y #id identificaciones de personas
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                Punto p = l2[j];
                matriz[i][j] = distancia(l1.getNodo(i)->getPeople().getXCentro(),l1.getNodo(i)->getPeople().getYCentro(),p.getX(),p.getY());
            }
        }

        vector<bool> auxbool; //vector auxiliar que contendra si una persona ha actualizado su posicion
        for (int j = 0; j < auxbool.size(); j++)
        {
            if (!auxbool[i])
            {
                //eliminar(); //una persona ha entrado o ha salido
            }
        }
        if (auxbool.size()<l1.size())
        {
            //agregar
        }
        imshow("Detector de personas", imagen);
        waitKey(0);
    */
    }
    


    /*
       se debe recorrer el vector de personas identificando a cada una con sus centroides correspondientes, al pasar al siguiente frame hay que reconocer si una persona se ha movido a traves de una matriz que contendra
       las distancias entre cada centroide y las personas, la que tenga menor distancia correspondera a una persona, al haber una distancia minima querra decir que se ha movido, en caso de que desaparezca una persona, habra
       un centroide menos, y se debera elminar la persona que tenga una distancia mayor correspondiente a los centroides que hayan, querra decir que salio o entro del lugar, en caso de que aparezca una nueva persona, habra un
       centroide mas de los identificadores que tengamos en la lista, tendremos que asignar el centroide a la persona nueva. Todo esto se ve a traves de la matriz.

    */



}