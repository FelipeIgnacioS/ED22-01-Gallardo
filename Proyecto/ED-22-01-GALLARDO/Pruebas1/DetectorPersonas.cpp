/*
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

}
*/