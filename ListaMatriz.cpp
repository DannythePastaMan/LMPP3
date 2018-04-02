//
// Created by daniel on 4/2/18.
//

#include "ListaMatriz.h"
#include <iostream>
using namespace std;

void ListaMatriz::printLista() {
    Nodo *aux = inicioMatriz;
    Nodo *temp = inicioMatriz;

    while (aux->abajo != NULL) {
        while (temp->abajo != NULL) {
            cout << temp->value << " ";
            temp = temp->sig;
        }
        cout << temp->value << " ";
        temp = inicioMatriz->abajo;
        aux = inicioMatriz->abajo;
        cout << endl;
    }

    while (temp->sig != NULL) {
        cout << temp->value << " ";
        temp = temp->sig;
    }
    cout << temp->value << " ";
    cout << endl;
}