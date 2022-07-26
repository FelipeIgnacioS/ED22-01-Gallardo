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

float distancia(int x1, int y1, int x2, int y2) {
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));;
    return dist;
}

void guardMenu() {
    cout << "Bienvenido al menu de 'GUARDIAS'" << endl;
    
    int option;
    cin >> option;
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
        cout << "Introduzca una opcion del 1 al 5" << endl;
        switch (option)
        {
        case1:
            cout << "Ha elegido la opcion de detectar personas" << endl;
            cargarImagenes();
            cargado = true;
            bool op = false;
            while (!op)
            {
                cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                string opcion;
                cin >> opcion;
                if (opcion == "1") {
                    op = true;
                }
                if (opcion == "2") {
                    op = true;
                    eleccion = true;
                }
            }
        case2:
            cout << "Obteniendo las personas que han salido del edificio " << endl;
            if (cargado)
            {
                obtenerSalidas();
                bool op1 = false;
                while (!op1)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion1;
                    cin >> opcion1;
                    if (opcion1 == "1") {
                        op1 = true;
                    }
                    if (opcion1 == "2") {
                        op1 = true;
                        eleccion = true;
                    }
                }
            }
            else {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        case3:
            cout << "Obteniendo las personas que han entrado al edificio" << endl;
            if (cargado)
            {
                obtenerEntradas();
                bool op2 = false;
                while (!op2)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion2;
                    cin >> opcion2;
                    if (opcion2 == "1") {
                        op2 = true;
                    }
                    if (opcion2 == "2") {
                        op2 = true;
                        eleccion = true;
                    }
                }
            }
            else {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        case4:
            cout << "Obteniendo el flujo promedio de las entradas del edifcio" << endl;
            if (cargado)
            {
                flujoEntrada();
                bool op3 = false;
                while (!op3)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion3;
                    cin >> opcion3;
                    if (opcion3 == "1") {
                        op3 = true;
                    }
                    if (opcion3 == "2") {
                        op3 = true;
                        eleccion = true;
                    }
                }
            }
            else {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }
        case5:
            cout << "Obteniendo el flujo promedio de las salidas del edificio" << endl;
            if (cargado)
            {
                flujoSalida();
                bool op4 = false;
                while (!op4)
                {
                    cout << "Para elegir otra opcion ingrese '1' para salir del sistema ingrese '2'" << endl;
                    string opcion4;
                    cin >> opcion4;
                    if (opcion4 == "1") {
                        op4 = true;
                    }
                    if (opcion4 == "2") {
                        op4 = true;
                        eleccion = true;
                    }
                }
            }
            else {
                cout << "Para poder elegir esta opcion primero debe cargar las imagenes" << endl;
            }

        default:
            cout << "Ingrese solo las opciones mencionadas" << endl;
            break;
        }
    }
    
}

void adminMenu() {
    cout << "Bienvenido al menu de 'ADMINISTRADOR'" << endl;
    string option = "1";
    bool op = false;
    string path;
    vector<string> seleccion;
    while (!op)
    {
        //Se da a eleigr la opcion entre 3 path con imagenes para evitar la entrada de una ruta larga por teclado
        cout << "Los path disponibles son los siguientes" << endl;
        cout << "PATH[1] -> 1" << endl;
        cout << "PATH[2] -> 2" << endl;
        cout << "PATH[3] -> 3" << endl;
        cout << "Ingrese una opcion del 1 al 3" << endl;
        cin >> path;
        if (path == "1" || path == "2" || path == "3") {
            op = true;
            break;
        }
        cout << "Ingrese una opcion valida" << endl;
    }
    vector<String> path1;
    vector<String> path2;
    vector<String> path3;
    /*rellenar vectoresPath*/
    if (path == "1")seleccion = path1;
    if (path == "2")seleccion = path2;
    if (path == "3")seleccion = path3;
}

void menu() {
    cout << "Bienvenido/a al sistema de vigilancia del edificio" <<endl;
    string option = "-1";
    bool op = false;
    
    while (!op) {
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
}