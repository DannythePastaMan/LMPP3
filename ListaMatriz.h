//
// Created by daniel on 4/2/18.
//

#ifndef LISTAMATRIZ_LISTAMATRIZ_H
#define LISTAMATRIZ_LISTAMATRIZ_H

struct Nodo{
    Nodo *sig;
    Nodo *abajo;
    int value;
};
class ListaMatriz {
public:
    Nodo *inicioMatriz;
    int nfilas, ncolum;
    ListaMatriz() : inicioMatriz(nullptr){

    }
    void printLista();
};


#endif //LISTAMATRIZ_LISTAMATRIZ_H
