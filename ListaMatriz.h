//
// Created by daniel on 3/21/18.
//

#ifndef MATRIZLISTAS_MATRIZ_H
#define MATRIZLISTAS_MATRIZ_H

#include <iostream>

#include "Nodo.h"
struct Matriz{
    int nfilas, ncolum;
    int **punteromatriz;
    std::string archive;
};

class ListaMatriz {
public:
    ListaMatriz *inicioMatriz;
    Nodo *inicio;
    int nfilas, ncolum;
    ListaMatriz CrearMatriz(Matriz);
    void printMatrix();
    ListaMatriz cargarMatriz();
    ListaMatriz();
};


#endif //MATRIZLISTAS_MATRIZ_H


