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
    this->inicioMatriz = nullptr;
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

    Lista.inicioMatriz = reinterpret_cast<ListaMatriz *>(ListaNodos[0]);
    Lista.nfilas = m.nfilas;
    Lista.ncolum = m.ncolum;

    return Lista;
}
void ListaMatriz::printMatrix() {
    auto *aux = reinterpret_cast<Nodo *>(inicioMatriz);
    auto *aux2 = reinterpret_cast<Nodo *>(inicioMatriz);

    cout<<"*****Matriz*****"<<endl;
    for (int i = 0; i < nfilas; ++i) {
        for (int j = 0; j < ncolum; ++j) {
            if (inicio->sig != nullptr && inicio->abajo) {
                cout << aux2->dato << endl;
                aux = aux->sig;
            }
        }
            cout<<aux2->dato;
            aux2 = aux->abajo;
            aux = aux->abajo;
            cout<<"\n"<<endl;
        }

        for (int k = 0; k < nfilas; ++k) {
            if(aux2->sig != nullptr){
                cout<<aux2->dato<<endl;
                aux2 = aux2->sig;
            }
            cout<<aux2->dato<<endl;
        }
    }

ListaMatriz ListaMatriz::ReadandWriteOnFile(string archivename, int nfila, int ncolum) {
    ListaMatriz LR = ListaMatriz();
    Matriz m = Matriz();
    fstream archive;
    FileMakerOperaciones FMO;

    cout << "Nom archivo: ";
    cin >> archivename;

    archive.open(archivename.c_str(), ios::out);

    if(archive.fail()){
        cout<<"Archive could not be opened"<<endl;
        exit(1);
    }

    cout << "Digite numero de filas: ";
    cin >> nfila;

    cout << "Ingrese numero de columnas: ";
    cin >> ncolum;

    vector<vector<int>> Matriz(static_cast<unsigned long>(nfila));

    for (int i = 0; i < nfila; ++i) {
        Matriz[i] = vector<int>(static_cast<unsigned long>(ncolum));
    }
    for (int i = 0; i < nfila; ++i){
        for (int j = 0; j < ncolum; ++j) {
            cout<<"Dijite mumeros a almacenar en matriz["<<i<<"]["<<j<<"]: ";
            cin>>Matriz[i][j];
            archive<<Matriz[i][j];
        }
    }

    archive.close();
}
