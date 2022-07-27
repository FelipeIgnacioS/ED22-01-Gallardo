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

float distancia(int x1, int y1, int x2, int y2) 
{
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));;
    return dist;
}

void guardMenu() 
{
    cout << "Bienvenido al menu de 'GUARDIA'" << endl;
    
    string option;
    bool eleccion = false;
    bool cargado = false;
    while (!eleccion)
    {
        cout << "Las acciones disponibles son" << endl;
        cout << "1.-Detectar peronas" << endl;
        cout << "2.-Obtener las peronas que han salido del edificio" << endl;
        cout << "3.-Obtener las personas que han entrado al edificio" << endl;
        cout << "4.-Obtener el flujo promedio de las entradas al edificio" << endl;
        cout << "5.-Obtener el flujo promedio de las salidas del edicio" << endl;
        cout << "6.-Salir del sistema" << endl;
        cout << "Introduzca una opcion del 1 al 6" << endl;
        cin >> option;

        if (option == "1")
        {
            cout << "Ha elegido la opcion de detectar personas" << endl;
            cout << "cargando imagenes" << endl;
            //cargarImagenes();
            cargado = true;
            bool op = false;
            while (!op)
            {
                cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                string opcion;
                cin >> opcion;
                if (opcion == "1")
                {
                    op = true;
                }
                if (opcion == "2")
                {
                    op = true;
                    eleccion = true;
                }
            }
        }

        else if (option == "2")
        {
            
            if (cargado)
            {
                cout << "Obteniendo las personas que han salido del edificio " << endl;
                //obtenerSalidas();
                bool op1 = false;
                while (!op1)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion1;
                    cin >> opcion1;
                    if (opcion1 == "1")
                    {
                        op1 = true;
                    }
                    if (opcion1 == "2")
                    {
                        op1 = true;
                        eleccion = true;
                    }
                }
            }
            else
            {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        }

        else if (option == "3")
        {
            
            if (cargado)
            {
                cout << "Obteniendo las personas que han entrado al edificio" << endl;
                //obtenerEntradas();
                bool op2 = false;
                while (!op2)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion2;
                    cin >> opcion2;
                    if (opcion2 == "1")
                    {
                        op2 = true;
                    }
                    if (opcion2 == "2")
                    {
                        op2 = true;
                        eleccion = true;
                    }
                }
            }
            else
            {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        }

        else if (option == "4")
        {
            
            if (cargado)
            {
                cout << "Obteniendo el flujo promedio de las entradas del edifcio" << endl;
                //flujoEntrada();
                bool op3 = false;
                while (!op3)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion3;
                    cin >> opcion3;
                    if (opcion3 == "1")
                    {
                        op3 = true;
                    }
                    if (opcion3 == "2")
                    {
                        op3 = true;
                        eleccion = true;
                    }
                }
            }
            else
            {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        }

        else if (option == "5")
        {
            
            if (cargado)
            {
                cout << "Obteniendo el flujo promedio de las salidas del edificio" << endl;
                //flujoSalida();
                bool op4 = false;
                while (!op4)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion4;
                    cin >> opcion4;
                    if (opcion4 == "1")
                    {
                        op4 = true;
                    }
                    if (opcion4 == "2")
                    {
                        op4 = true;
                        eleccion = true;
                    }
                }
            }
            else
            {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        }

        else if (option == "6")
        {
            break;
        }

        else
        {
            cout << "Ingrese una opcion correcta" << endl;
        }
    }
}

vector<String> adminMenu() 
{
    cout << "Bienvenido al menu de 'ADMINISTRADOR'" << endl;
    string option = "1";
    bool op = false;
    string path;
    vector<string> seleccion;
    while (!op)
    {
        //Se da a eleigr la opcion entre 3 path con imagenes para evitar la entrada de una ruta larga por teclado
        cout << "Los path disponibles son los siguientes" << endl;
        cout << "[1] -> Path 1" << endl;
        cout << "[2] -> Path 2" << endl;
        cout << "[3] -> Path 3" << endl;
        cout << "Ingrese una opcion del 1 al 3" << endl;
        cin >> path;
        if (path == "1" || path == "2" || path == "3") {
            op = true;
            break;
        }
        cout << "Ingrese una opcion valida" << endl;
    }
    vector<String> path1;
    path1.push_back("1");
    path1.push_back("2");
    vector<String> path2;
    path2.push_back("2");
    path2.push_back("2");
    vector<String> path3;
    path3.push_back("2");
    path3.push_back("2");
    /*rellenar vectoresPath*/
    if (path == "1")seleccion = path1;
    if (path == "2")seleccion = path2;
    if (path == "3")seleccion = path3;

    return seleccion;
}

void menu()     
{
    cout << "Bienvenido/a al sistema de vigilancia del edificio" <<endl;
    string option = "-1";
    bool op = false;
    
    while (!op) 
    {
        cout << "Para ingresar en el modo 'GUARDIA' pulse 1 " << endl;
        cout << "Para ingresar en el modo 'ADMINISTRADOR' pulse 2 " << endl;
        cout << "Para Salir del programa pulse 3" << endl;
        cin >> option;
        if (option == "1")
        {
            guardMenu();
            op = true;
        }
        if (option == "2")
        {
            adminMenu();
            op = true;
        }
        if (option == "3")
        {
            op = true;
        }
    }
    cout << "Cerrando programa..." << endl;
 }


void cargarImagenes() {

}


void obtenerSalidas() {

}


void obtenerEntradas() {

}

void flujoEntrada() {

}

void flujoSalida() {

}

int main(int argc, char** argv) {
    menu();

    int entrys = 0; //entradas al recinto
    int leaves = 0; //salidas del recinto
    float tiempo;
    Detector detector;
    Mat imagen;
    vector<String> imagenes;
    imagenes.push_back("C:/Users/pipen/OneDrive/Escritorio/ED22-01-Gallardo/ED22-01-Gallardo/Imagen/image1679.png");
    imagen = imread(imagenes[0]);
    detector.toggleMode();
    cout << detector.modeName() << endl;

    
    LinkedList* lista1 = new LinkedList();
    *lista1 = detector.detect(imagen);
    for (int i = 0; i < lista1->size(); i++)
    {
        People p = lista1->getNodo(i)->getPeople();
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
    }

    imshow("People detector", imagen);
    waitKey(0);

    return 0;


}