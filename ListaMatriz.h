//
// Created by daniel on 3/21/18.
//

#ifndef MATRIZLISTAS_MATRIZ_H
#define MATRIZLISTAS_MATRIZ_H

#include <iostream>
#include <vector>

#include "Nodo.h"

struct Matriz{
    int nfilas, ncolum;
    std::vector<std::vector<int>> Matriz;
    std::string archive;
};

class ListaMatriz {
public:
    ListaMatriz *inicioMatriz;
    Nodo *inicio;
    int nfilas, ncolum;
    ListaMatriz CrearMatriz(Matriz);
    void printMatrix();
    ListaMatriz ReadandWriteOnFile(std::string, int, int);
    ListaMatriz();
};


#endif //MATRIZLISTAS_MATRIZ_H


