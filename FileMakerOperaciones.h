//
// Created by daniel on 3/20/18.
//

#ifndef MATRIZLISTAS_FILEMAKEROPERACIONES_H
#define MATRIZLISTAS_FILEMAKEROPERACIONES_H

#include "ListaMatriz.h"

class FileMakerOperaciones {
public:
    FileMakerOperaciones();
    int *ReadfromFiles(std::string, int, int);
    ListaMatriz SumaMatrices(ListaMatriz, ListaMatriz);
    ListaMatriz RestaMatrices(ListaMatriz, ListaMatriz);
    ListaMatriz MultiplyMatrices(ListaMatriz, ListaMatriz);
    int DeterminanteMatriz(ListaMatriz);
};


#endif //MATRIZLISTAS_FILEMAKEROPERACIONES_H
