//
// Created by daniel on 3/19/18.
//

#ifndef MATRIZLISTAS_NODO_H
#define MATRIZLISTAS_NODO_H

class Nodo {
public:
    Nodo *abajo;
    Nodo *sig;
    int dato;

    Nodo();
    explicit Nodo(int dato);
};


#endif //MATRIZLISTAS_NODO_H
