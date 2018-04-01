//
// Created by daniel on 3/21/18.
//

#include "ListaMatriz.h"
#include "FileMakerOperaciones.h"
#include <iostream>
#include <string>
#include <stdlib.h>
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
            nuevo->dato = m.punteromatriz[i][j];
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
    Nodo *aux = reinterpret_cast<Nodo *>(inicioMatriz);
    Nodo *aux2 = reinterpret_cast<Nodo *>(inicioMatriz);

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

ListaMatriz ListaMatriz::cargarMatriz() {
    ListaMatriz LR = ListaMatriz();
    ofstream archive;
    string archivename;
    int nfila, ncolum;
    Matriz m;
    FileMakerOperaciones FMO;

    cout<<"Ingrese archivo donde desea cargar la matriz: "<<endl;
    getline(cin, archivename);
    archive.open(archivename.c_str(), ios::out);

    if(archive.fail()){
        cout<<"Archive not found|";
        exit(1);
    }

    ifstream file(archivename);

    cout<<"Digite numero de filas: ";
    cin>>nfila;

    cout<<"Ingrese numero de columnas: ";
    cin>>ncolum;

    if(file.good()){
        cout<<"File found"<<endl;

        m.nfilas = nfila;
        m.ncolum = ncolum;
        m.punteromatriz = reinterpret_cast<int **>(*FMO.ReadfromFiles(archivename, nfila, ncolum));
    }

    else{
        cout<<"Error 404: File not found"<<endl;
        return LR;
    }

    archive.close();
    LR =  LR.CrearMatriz(m);
    return LR;
}
