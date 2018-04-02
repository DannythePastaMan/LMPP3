//
// Created by daniel on 4/2/18.
//

#ifndef MATRIZLISTAS_FILEMAKERLISTA_H
#define MATRIZLISTAS_FILEMAKERLISTA_H

#include <iostream>
#include <vector>
#include <fstream>

struct Nodo{
    Nodo *sig;
    Nodo *abajo;
    int nfilas, ncolum, value;
};

struct Matrix{
    int nfilas;
    int ncolum;
    std::vector<std::vector<int>> Matriz;
    std::string archivename;
};

class FileMakerLista {
public:
    Nodo *inicioMatriz;
    int nfilas, ncolum;
    FileMakerLista():inicioMatriz(nullptr){

    }

    void printLista();
    std::vector<std::vector<int>>Read(std::string archivename, int nfilas, int ncolum);
    FileMakerLista Lista(Matrix m);
    FileMakerLista CargaraArchivo();
};


#endif //MATRIZLISTAS_FILEMAKERLISTA_H
