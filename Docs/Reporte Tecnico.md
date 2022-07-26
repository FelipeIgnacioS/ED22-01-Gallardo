![UCN](https://github.com/FelipeIgnacioS/ED22-01-Gallardo/blob/main/Docs/images/60x60-ucn-negro.png)

# Informe Tecnico

## Curso: Estrcutura de datos.

## Deteccion de Personas y conteo.

## Alumnos:
   * Felipe Gallardo

## Resumen:
<En el siguiente taller se desarrollará un software para satisfacer los requerimientos de tráfico de personas para un mejor sistema de vigilancia de la entrada de un edifico, para esto se utilizara una IDE como medio de desarrollo para el software, apoyado de librerías como OpenCv para la identificación de las distintas personas. Los objetivos del software son el conteo de las personas que ingresan y salen, la frecuencia con que lo hace cada individuo para así poder identificarlos y proveerle al guardia una mejor supervisión del flujo de personas que hay en el edificio y así evitar cualquier tipo de conducta extraña dentro de la empresa.

## 1 Introducción.

En el presente informe, referente al proyecto de detección de personas y conteo, el sofware desarrollado responderá a la problemática de vigilancia y control de flujo de personas dentro de un edifcio, o algún lugar que se establezca en el programa, permitiendo saber las personas que han entrado o salido de un sector, obtener algún indicio sobre alguna conducta sospechosa de algún individuo viendo la cantidad de veces que ha entrado o salido, obtener un flujo de personas por hora que ingresan o parten de cierto lugar, todo esto permitiendo a la persona encargada de la seguridad del lugar obtener un informe más detallado de lo que sucede en una entrada de un recinto

### 1.1 Descripción del problema

Una empresa requiere de un sistema de vigilancia para la entrada y salida de su edificio, donde se tiene una cámara que detecta personas, se requiere llevar un conteo de individuos para lograr supervisar de mejor manera el flujo de entrada y salida dentro del edifcio.

### 1.2 Objetivos

#### 1.2.1 Obejtivos Generales

El objetivo General es desarrolar un software que permita cumplir con los requerimientos de la empresa, en cuanto a la supevisión de la entrada al edificio.

#### 1.2.2 Objetivos Específicos

  1. Investigar el funcionamiento de librerias utilizadas para el procesamiento de imágenes y videos
  2. Estudiar el reconocimiento de distintos individuos a través de un software
  3. Implementar los métodos investigados y estudiados a través de el lenguaje de programación "c++", para el desarrollo        del software
  4. Analizar resultados y proponer mejoras para el funcionamiento del software creado

### 1.3 Solución Propuesta

Desarrolar un programa que permita satisfacer los requerimientos del cliente

## 2 Materiales y métodos

Se espera desarrollar el proyecto a través de una investigación previa, utilizando una IDE como medio para crear el programa utilizando librerias como openCV.

### 2.1 Instalación

Para el desarrollo de software se utilizó CMake para el control del proceso de compilación del software, también se utilizó la biblioteca OpenCV para la detección de individuos, como IDE se uso Visual Studio Code, en cuanto a la instalación; comenzando por la IDE para su instalación se descargó el software directo desde la página de Visual Studio, también añadiendo las extensiones de C/C++, para CMake se hizo una descarga desde su página y una instalación similar a la de Visual Studio y por último para OpenCV se hizo una instalación del programa y además una edición de las variables de entorno agregando las de openCV para el correcto funcionamiento. Esta fue la primera opción del desarrollo del software, al presentar problemas de compilación y errores con Cmake se optó por otra alternativa la cual fue la siguiente:
Hubo un cambio de IDE con respecto a Visual studio code, se utilizó ahora Visual Studio 2022, el cual fue descargado directo desde su página, a este se le agregó las extensiones del lenguaje de c++. Para el openCv se hizo la instalación al igual que en el primer método, es decir, haciendo una descarga directa desde su página.
Dentro del proyecto ya creado se realizaron distintas modificaciones para el correcto funcionamiento de OpenCv, en primer lugar, en las propiedades de depuración, se incluyeron directorios adicionales, los cuales son los de OpenCv, luego en la opción de "Linker" se agregaron directorios de librerías y por último, en el input se agregaron dependencias de OpenCv, y con esto queda configurado correctamente.

### 2.2 Diseño

En el siguiente diagrama se refleja cómo se trabajara con la clase Persona y Nodo. La clase Persona será almacenada en un Nodo, los cuales serán agregados a distintas listas enlazadas simples, una contendrá las personas únicas que han entrado y la otra lista enlazada tendrá las personas únicas que han salido. También habrá una lista con las personas únicas, además de varibales que contengan la cantidad de personas que entran y salen, además de la variable que contendrá el tiempo, para poder calcular el flujo de personas/hora.

![Image Text](https://github.com/FelipeIgnacioS/ED22-01-Gallardo/blob/main/Docs/images/Diagrama.png) 

Hubo un cambio de diseño debido a los requerimientos, se tendran nodos con personas dentros para que sean almancenadas dentro de una lista enlazada simple, ocuparemos matrices para el guardado de distancias entre puntos y personas, se usaran vectores para el guardado de puntos.

### 2.3 Implementación

En cuanto a la implementación se crearon las siguientes clases:

Clase People : Contendrá las posiciones necesarias para el calculo del centroide de la persona, también tendrá contadores de entrada y de salida, ademas de un identificador

Clase Nodo : Contendrá a un objeto tipo Persona, esta clase sera necesaria para la implementación en una lista

Clase LinkedList: Lista de enlace simple, cuenta con un first de referencia, tiene método de ingreso de nodos, orden de la lista, y de impresión

Clase Detector: Clase necesaria que recibirá una imagen o vídeo la cual procesara para poder identificar los individuos.

## 3 Resultados
Como resultado se logró el reconocimiento de personas a través de la librería de OpenCV, identificando cada una de estas, se logró el almacenamiento de cada una de estas mediante listas enlazadas simples, no se logro implementar todos los puntos a cabalidad, pero sí desarrollando una gran parte de la lógica que conlleva  el proceso del movimiento de las personas a través de imágenes o videos/frames, reconociendo el movimiento de sus centroides a través de cada uno de estos.
## 4 Conclusiones 
Finalizando con el reporte, se necesita una mayor investigación de las posibles soluciones, y en consideración a lo anteriormente mencionado, también se notó la falta de conocimientos previos con respecto a herramientas como OpenCv, CMake, Visual Studio, asimismo al manejo de la sintaxis de un nuevo lenguaje. Se consiguió adquirir nuevos conocimientos en estas tecnologías, que se seguirán desarrollando a través del tiempo. Se adquirió nuevos conocimientos con respecto a tecnologías no empleadas anteriormente, se dio un salto grande de conocimientos que serán una gran herramienta de apoyo para futuros proyectos.
# Anexos
1. ADRIAN ROSEBROCK OpenCV People Counter https://pyimagesearch.com/2018/08/13/opencv-people-counter/ fecha de acceso: 10/06/2022
