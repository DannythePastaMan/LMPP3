//
// Created by daniel on 3/19/18.
//

#include "Nodo.h"
#include <iostream>

Nodo::Nodo() {
    this->sig = nullptr;
    this->abajo = nullptr;
}

Nodo::Nodo(int dato) {
    this->dato = dato;
}
