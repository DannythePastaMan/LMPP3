//
// Created by daniel on 3/21/18.
//

#include "ListaMatriz.h"
#include "FileMakerOperaciones.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ListaMatriz::ListaMatriz() {
    this->inicio = nullptr;
    this->ncolum = ncolum;
    this->nfilas = nfilas;
}

ListaMatriz ListaMatriz::CrearMatriz(Matriz m) {
    ListaMatriz Lista = ListaMatriz();
    auto *nuevo = new Nodo;
    vector<Nodo*>ListaNodos;

    for (int i = 0; i <m.nfilas ; ++i) {
        for (int j = 0; j < m.ncolum; ++j) {
            nuevo->dato = m.Matriz[i][j];
            nuevo->sig = nullptr;
            nuevo->abajo = nullptr;
            ListaNodos.push_back(nuevo);
        }
    }

    for (int k = 0; k < ListaNodos.size(); ++k) {
        if(k == ListaNodos.size() - 1){
            ListaNodos[k]->abajo = nullptr;
        }

        else if((k+1) % m.ncolum == 0){
            if(k != 0){
                ListaNodos[k]->sig = nullptr;
                ListaNodos[k]->abajo = ListaNodos[k + m.ncolum];
            }
        }

        else if(k >= (ListaNodos.size() - m.ncolum)){
            ListaNodos[k]->sig = ListaNodos[k + 1];
            ListaNodos[k]->abajo = nullptr;
        }

        else{
            ListaNodos[k]->sig = ListaNodos[k+1];
            ListaNodos[k]->abajo = ListaNodos[k + m.ncolum];
        }
    }

    Lista.inicio = ListaNodos[0];
    Lista.nfilas = m.nfilas;
    Lista.ncolum = m.ncolum;

    return Lista;
}
void ListaMatriz::printMatrix() {
    auto *aux = inicio;
    auto *aux2 = inicio;

    cout<<"*****Matriz*****"<<endl;
 while(aux->abajo != nullptr){
     while(aux2->sig != nullptr){
                cout << aux2->dato << endl;
                aux2= aux2->sig;
        }
            cout<<aux2->dato;
            aux2 = aux->abajo;
            aux = aux->abajo;
            cout<<"\n"<<endl;
        }

        while(aux2->sig != nullptr){
                cout<<aux2->dato<<endl;
                aux2 = aux2->sig;
            }
            cout<<aux2->dato<<endl;
        }

ListaMatriz ListaMatriz::ReadandWriteOnFile() {
    ListaMatriz LR = ListaMatriz();
    Matriz m = Matriz();
    fstream archive;
    string archivename;
    int nfila, ncolum;

    cout << "Nom archivo: ";
    cin >> archivename;

    archive.open(archivename.c_str(), ios::app);

    if(archive.fail()){
        cout<<"Archive could not be opened"<<endl;
        exit(1);
    }

    cout << "Digite numero de filas: ";
    cin >> nfila;

    cout << "Ingrese numero de columnas: ";
    cin >> ncolum;

    vector<vector<int>> Matriz(static_cast<unsigned long>(nfila));

if(archive.good()) {
    for (int i = 0; i < nfila; ++i) {
        Matriz[i] = vector<int>(static_cast<unsigned long>(ncolum));
    }
    for (int i = 0; i < nfila; ++i){
        for (int j = 0; j < ncolum; ++j) {
            cout<<"Digite mumeros a almacenar en matriz["<<i<<"]["<<j<<"]: ";
            cin>>Matriz[i][j];
            archive<<Matriz[i][j];
        }
    }
    m.archive = archivename;
    m.nfilas = nfila;
    m.ncolum = ncolum;

}
    archive.close();
    LR = LR.CrearMatriz(m);
    return LR;
}
