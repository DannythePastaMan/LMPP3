//
// Created by daniel on 3/20/18.
//

#ifndef MATRIZLISTAS_FILEMAKEROPERACIONES_H
#define MATRIZLISTAS_FILEMAKEROPERACIONES_H

#include "ListaMatriz.h"
#include <vector>
#include <iostream>

class FileMakerOperaciones {
public:
    FileMakerOperaciones();
    ListaMatriz SumaMatrices(ListaMatriz, ListaMatriz);
    ListaMatriz RestaMatrices(ListaMatriz, ListaMatriz);
    ListaMatriz MultiplyMatrices(ListaMatriz, ListaMatriz);
    int DeterminanteMatriz(ListaMatriz);
};


#endif //MATRIZLISTAS_FILEMAKEROPERACIONES_H
