//
// Created by daniel on 4/2/18.
//

#ifndef LISTAMATRIZ_FILEMAKEROPERACIONES_H
#define LISTAMATRIZ_FILEMAKEROPERACIONES_H

#include "ListaMatriz.h"
#include "Nodo.h"
#include <iostream>
#include <vector>

class FileMakerOperaciones {
public:
    ListaMatriz Add(ListaMatriz, ListaMatriz);
    ListaMatriz Sub(ListaMatriz, ListaMatriz);
    ListaMatriz Multi(ListaMatriz, ListaMatriz);
    int Det(ListaMatriz);
    FileMakerOperaciones();

};


#endif //LISTAMATRIZ_FILEMAKEROPERACIONES_H
