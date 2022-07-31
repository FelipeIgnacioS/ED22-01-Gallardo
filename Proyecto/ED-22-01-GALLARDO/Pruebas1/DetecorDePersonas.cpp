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

#include <ctime> //libreria para tiempo

using namespace cv;
using namespace std;

float distancia(int x1, int y1, int x2, int y2) 
{
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));;
    if (dist<0) //distancia siempre positiva
    {
        dist = -dist;
    }
    return dist;
}

void cargarImagenes(vector<String> imagenes, int& entrys, int& leaves, float& horas, float& flujoE, float& flujoS)
{
    //tiempo
    clock_t t;
    t = clock();


    //cargar imagenes
    Detector detector;
    Mat imagen;

    LinkedList* listaIdentidades = new LinkedList();

    //for que contiene la cantidad de frames
    for (int j = 0; j < imagenes.size(); j++)
    {

        imagen = imread(imagenes[j]);
        detector.toggleMode();

        LinkedList* lista1 = new LinkedList();
        *lista1 = detector.detect(imagen); //cantidad de personas en la imagen.
        vector<Punto> puntos; //puntos de cada frame
        for (int i = 0; i < lista1->size(); i++)
        {
            People p = lista1->getNodo(i)->getPeople();
            //dibujo de el rectangulo de la imagen de los puntos del rectangulo y centroide
            rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
            circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
            Punto pun = Punto(p.getXComienzo(), p.getYComienzo(), p.getXCentro(), p.getYCentro(), p.getXFin(), p.getYFin());
            puntos.push_back(pun);
        }
        if (listaIdentidades->empty()) //caso para el primer frame o imagen ingresada al sistema
        {
            for (int a = 0; a < lista1->size(); a++)
            {
                listaIdentidades->add(lista1->getNodo(a));
                entrys++; //asumiendo que las personas que inician en el video estan entrando
            }
        }

        else
        {
            float matrizDistancias[20][20];//se crea una matriz de 20x20 ya que c++ no permite crear una matriz con valores variables;
            int filas = puntos.size();
            int col = listaIdentidades->size();
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    int xiden = listaIdentidades->getNodo(j)->getPeople().getXCentro(); //punto x de la identidad
                    int yiden = listaIdentidades->getNodo(j)->getPeople().getYCentro(); //punto y de la identidad
                    int xp = puntos[i].getX(); //punto xCentro 
                    int yp = puntos[i].getY(); //punto yCentro
                    matrizDistancias[i][j] = distancia(xiden, yiden, xp, yp); //llenar matriz con las distancias
                }
            }

            if (filas == col)
            {
                //actualizar distancias ya que no hay un punto nuevo o un punto menos para agregar o quitar identidades

                for (int i = 0; i < filas; i++)
                {
                    float menor = 99999999;
                    int xC, yC, x, y, xF, yF;
                    People p;
                    for (int j = 0; j < col; j++)
                    {
                        if (matrizDistancias[i][j] < menor)
                        {
                            menor = matrizDistancias[i][j];
                            xC = puntos[i].getXc();
                            yC = puntos[i].getYc();
                            x = puntos[i].getX();
                            y = puntos[i].getY();
                            xF = puntos[i].getX();
                            yF = puntos[i].getYf();
                            p = listaIdentidades->getNodo(j)->getPeople();
                        }
                    }
                    //actualizamos la identidad con sus nuevos puntos
                    p.actualizarPuntos(xC, yC, x, y, xF, yF);
                }
            }

            else
            {
                //en caso de que no sean iguales las filas y columnas quiere decir que un punto se agrego o punto se fue
                //habra que eliminar o agregar una identidad nueva
                vector<bool> actualizados; //vector de tamaño de las identidades, true en caso de haber actualizado sus distancias, falso en el caso de que no

                if (filas > col) //si las filas son mayores que las columnas quiere decir que una nueva persona ingreso al edifcio
                {
                    entrys++;
                    for (int a = 0; a < puntos.size(); a++) //llenamos el vector de false del tamaño de la cantidad de puntos, se le asignaran true si fueron asignados a alguna entidad
                    {
                        actualizados[a] = false;
                    }

                    for (int i = 0; i < col; i++)
                    {
                        float menor = 9999;
                        int xC, yC, x, y, xF, yF;
                        int cont;
                        People p;
                        for (int j = 0; j < filas; j++)
                        {
                            if (matrizDistancias[j][i] < menor)
                            {
                                menor = matrizDistancias[j][i];
                                xC = puntos[j].getXc();
                                yC = puntos[j].getYc();
                                x = puntos[j].getX();
                                y = puntos[j].getY();
                                xF = puntos[j].getX();
                                yF = puntos[j].getYf();
                                p = listaIdentidades->getNodo(i)->getPeople();
                                cont = j;
                            }
                            p.actualizarPuntos(xC, yC, x, y, xF, yF); //actualizamos el punto
                            actualizados[cont] = true; //convertimos a true la posicion del punto
                        }
                    }
                    for (int b = 0; b < puntos.size(); b++) //recorremos el vector de booleanos
                    {
                        if (!actualizados[b]) //si uno de los booleanos es false entonces creamos una nueva persona y le asignamos el punto
                        {
                            Punto pun = puntos[b];
                            People p = People(pun.getXc(), pun.getYc(), pun.getX(), pun.getY(), pun.getXf(), pun.getYf());
                            Nodo* n = new Nodo(p);
                            listaIdentidades->add(n); //agregamos la nueva persona a la lista de identidades
                        }
                    }
                }
                else //en el caso de que las filas sean menores que las columnas quiere decir que una persona salio del edificio
                {
                    leaves++;
                    for (int a = 0; a < listaIdentidades->size(); a++) //llenamos el vector de false del tamaño de las identidades presentes en la linked list
                    {
                        actualizados[a] = false;
                    }

                    for (int i = 0; i < filas; i++)
                    {
                        float menor = 99999999;
                        int xC, yC, x, y, xF, yF;
                        People p;
                        int cont;
                        for (int j = 0; j < col; j++)
                        {
                            if (matrizDistancias[i][j] < menor)
                            {
                                menor = matrizDistancias[i][j];
                                xC = puntos[i].getXc();
                                yC = puntos[i].getYc();
                                x = puntos[i].getX();
                                y = puntos[i].getY();
                                xF = puntos[i].getX();
                                yF = puntos[i].getYf();
                                p = listaIdentidades->getNodo(j)->getPeople();
                                cont = j;
                            }
                        }
                        //actualizamos la identidad con sus nuevos puntos
                        p.actualizarPuntos(xC, yC, x, y, xF, yF); //actualizamos el punto
                        actualizados[cont] = true;
                    }
                    for (int b = 0; b < puntos.size(); b++) //recorremos el vector de booleanos
                    {
                        if (!actualizados[b]) //si uno de los booleanos es false entonces eliminamos a la personas una 
                        {
                            listaIdentidades->del(b); //eliminamos el nodo en la posicion que no se actualizo debido a que salio
                        }
                    }
                }
            }
        }
    }

    t = clock() - t;
    t = float(t) / CLOCKS_PER_SEC; //tiempo en segundos

    horas = t/3600;   
    //la funcion horas funciona como temporizador de la ejecucion del codigo para el calculo de tiempo transcurrido de frames, en caso de que lo ingresado al vector de imagenes sea frames por segundos, solo se contarian la cantidad de frames y se dividirian en horas
}

void guardMenu(vector<String> imagenes, int& entrys, int& leaves, float& horas, float& flujoE, float& flujoS)
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
            cargarImagenes(imagenes,entrys,leaves,horas,flujoE,flujoS);
            cout << "Imagenes cargadas" << endl;
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
                //leaves
                cout << "La cantidad de personas que han salido del edifcio son: " << leaves << endl;
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
                cout << "La cantidad de personas que han entrado al edificio son: " << entrys << endl;
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
                cout << "El flujo de personas que entraron por hora es de: " << flujoE << endl;
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
                cout << "El flujo de personas que salieron por hora es de: " << flujoS << endl;
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

void adminMenu(vector<String>& selecc) 
{
    cout << "Bienvenido al menu de 'ADMINISTRADOR'" << endl;
    string option = "1";
    bool op = false;
    string path;
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
    path1.push_back("1"); //ingresar imagenes a cada path (rutas)
    path1.push_back("2");
    vector<String> path2;
    path2.push_back("2");
    path2.push_back("2");
    vector<String> path3;
    path3.push_back("2");
    path3.push_back("2");
    /*rellenar vectoresPath*/
    if (path == "1") 
    {
        selecc.push_back(""); //ingresar rutas de imagenes
    }
    if (path == "2")
    {
        selecc.push_back(""); //ingresar ruta de imagenes
    }
    if (path == "3") 
    {
        selecc.push_back(""); //ingresar rutas de imagenes
    }
}


int main(int argc, char** argv) {
    
    int entrys = 0; //entradas
    int leaves = 0; //salidas
    float horas = 0; //horas
    float flujoE = 0; //flujoEntrada
    float flujoS = 0; //flujoSalida


    vector<string> imagenes;
    //path predeterminado
    imagenes.push_back("C:/Users/pipen/OneDrive/Escritorio/ED22-01-Gallardo/ED22-01-Gallardo/Path/PathPredeterminado/image0292.png"); //llenar con el path predeterminado
    imagenes.push_back("C:/Users/pipen/OneDrive/Escritorio/ED22-01-Gallardo/ED22-01-Gallardo/Path/PathPredeterminado/image0293.png");
    //menu
    cout << "Bienvenido/a al sistema de vigilancia del edificio" << endl;
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
            guardMenu(imagenes,entrys,leaves,horas,flujoE,flujoS);
            op = true;
        }
        if (option == "2")
        {
            adminMenu(imagenes);
            
        }
        if (option == "3")
        {
            op = true;
        }
    }
    cout << "Cerrando programa..." << endl;

    return 0;

}