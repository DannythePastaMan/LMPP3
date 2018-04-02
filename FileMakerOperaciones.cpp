//
// Created by daniel on 3/20/18.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "FileMakerOperaciones.h"
using namespace std;

FileMakerOperaciones::FileMakerOperaciones() = default;

ListaMatriz FileMakerOperaciones::SumaMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Nodo *aux1 = No1.inicio;
    Nodo *temp1 = No1.inicio;
    Nodo *aux2 = No2.inicio;
    Nodo *temp2 = No2.inicio;
    Matriz TM;

    int nfilas = 0, ncolum = 0;
    for (int i = 0; i < 2; ++i) {
        LR.ReadandWriteOnFile();
    }

    if(No1.nfilas != No2.nfilas){
        cout<<"Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."<<endl;
    }

    else{
       vector<vector<int>> Matriz;

        for (int i = 0; i < No1.nfilas; ++i) {
            Matriz[i] = vector<int>(static_cast<unsigned long>(No1.ncolum));
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (temp1->sig != nullptr) {
                        Matriz[nfilas][ncolum] = temp1->dato + temp2->dato;
                        aux2 = aux2->sig;
                        temp2 = temp2->sig;
                        ncolum = ncolum + 1;
                    }

                   Matriz [nfilas][ncolum] = static_cast<int>(temp1 - temp2);
                    temp1 = aux1->abajo;
                    temp2 = aux2->abajo;
                    aux1 = aux1->abajo;
                    aux2 = aux2->abajo;
                    nfilas = nfilas + 1;
                    ncolum = 0;
                }
            }
        }

                for (int k = 0; k < nfilas; ++k) {
                    if(aux2->sig != nullptr){
                        Matriz[nfilas][ncolum] = temp1->dato + temp2->dato;
                        temp1 = temp1->sig;
                         temp2 = temp2->sig;
                        ncolum = ncolum + 1;
                    }
                }
                TM.archive = "";
                TM.nfilas = No1.nfilas;
                TM.ncolum = No2.ncolum;
                TM.Matriz = Matriz;

        LR = LR.CrearMatriz(TM);
    }
    return LR;
}

ListaMatriz FileMakerOperaciones::RestaMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Matriz TM;
    Nodo *aux1 = No1.inicio;
    Nodo *aux2 = No1.inicio;
    Nodo *aux3 = No2.inicio;
    Nodo *aux4 = No2.inicio;

    int nfilas = 0, ncolum = 0, temp1, temp2;

    if (No1.nfilas != No2.nfilas) {
        cout
                << "Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."
                << endl;
    } else {
        vector<vector<int>> Matriz;

        for (int i = 0; i < No1.nfilas; ++i) {
            Matriz[i] = vector<int>(static_cast<unsigned long>(No1.ncolum));
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (aux2->sig != nullptr) {
                        temp1 = aux2->dato;
                        temp2 = aux4->dato;
                        Matriz[nfilas][ncolum] = temp1 - temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }


                    temp1 = aux2->dato;
                    temp2 = aux4->dato;
                    Matriz[nfilas][ncolum] = temp1 - temp2;
                    aux2 = aux1->abajo;
                    aux4 = aux3->abajo;
                    aux1 = aux1->abajo;
                    aux3 = aux3->abajo;
                    nfilas = nfilas + 1;
                    ncolum = 0;
                }
            }
        }

                for (int k = 0; k < nfilas; ++k) {
                    if (aux2->sig != nullptr) {

                        temp1 = aux2->dato;
                        temp2 = aux4->dato;
                        Matriz[nfilas][ncolum] = temp1 - temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }
                }

                temp1 = aux2->dato;
                temp2 = aux4->dato;
                Matriz[nfilas][ncolum] = temp1 - temp2;

                TM.archive = "";
                TM.nfilas = No1.nfilas;
                TM.ncolum = No2.ncolum;
                TM.Matriz = Matriz;

                LR = LR.CrearMatriz(TM);
            }
    return LR;
        }

ListaMatriz FileMakerOperaciones::MultiplyMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Matriz TM;
    Nodo *aux1 = No1.inicio;
    Nodo *aux2 = No1.inicio;
    Nodo *aux3 = No2.inicio;
    Nodo *aux4 = No2.inicio;

    int nfilas = 0, ncolum = 0, temp1, temp2;

    if (No1.nfilas != No2.nfilas) {
        cout
                << "Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."
                << endl;
    } else {
        vector<vector<int>>Matriz;

        for (int i = 0; i < No1.nfilas; ++i) {
            Matriz[i] = vector<int>(static_cast<unsigned long>(No1.ncolum));
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (aux2->sig != nullptr) {
                        temp1 = aux2->dato;
                        temp2 = aux4->dato;
                        Matriz[nfilas][ncolum] = temp1 * temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }


                    temp1 = aux2->dato;
                    temp2 = aux4->dato;
                    Matriz[nfilas][ncolum] = temp1 * temp2;
                    aux2 = aux1->abajo;
                    aux4 = aux3->abajo;
                    aux1 = aux1->abajo;
                    aux3 = aux3->abajo;
                    nfilas = nfilas + 1;
                    ncolum = 0;
                }
            }
        }

        for (int k = 0; k < nfilas; ++k) {
            if (aux2->sig != nullptr) {

                temp1 = aux2->dato;
                temp2 = aux4->dato;
                Matriz[nfilas][ncolum] = temp1 * temp2;
                aux2 = aux2->sig;
                aux4 = aux4->sig;
                ncolum = ncolum + 1;
            }
        }

        temp1 = aux2->dato;
        temp2 = aux4->dato;
        Matriz[nfilas][ncolum] = temp1 * temp2;

        TM.archive = "";
        TM.nfilas = No1.nfilas;
        TM.ncolum = No2.ncolum;
        TM.Matriz = Matriz;

        LR = LR.CrearMatriz(TM);
    }
    return LR;
}

int FileMakerOperaciones::DeterminanteMatriz(ListaMatriz No1) {
    int Res = -1, Determinante1, Determinante2, DeterminanteA, DeterminanteB, DeterminanteC, DeterminanteD, DeterminanteE, DeterminanteF;

    if(No1.nfilas != No1.ncolum){
        cout<<"Para poder llevar a cabo la operacion, la matriz debe ser cuadrada"<<endl;
    }

    else if(No1.ncolum == 1){
        Res = No1.inicio->dato;
    }

    else if(No1.ncolum == 2){
        Determinante1 = No1.inicio->dato * No1.inicio->sig->abajo->dato;
        Determinante2 = No1.inicio->sig->dato * No1.inicio->abajo->dato;
        Res = Determinante1 - Determinante2;
    }

    else if(No1.ncolum == 3){
        DeterminanteA = No1.inicio->dato * No1.inicio->sig->abajo->dato * No1.inicio->sig->abajo->sig->abajo->dato;
        DeterminanteB = No1.inicio->sig->dato * No1.inicio->sig->abajo->sig->dato * No1.inicio->abajo->abajo->dato;
        DeterminanteC = No1.inicio->abajo->dato * No1.inicio->abajo->abajo->sig->dato * No1.inicio->sig->sig->dato;
        DeterminanteD = No1.inicio->sig->sig->dato * No1.inicio->sig->abajo->dato * No1.inicio->abajo->abajo->dato;
        DeterminanteE = No1.inicio->sig->dato * No1.inicio->abajo->dato * No1.inicio->sig->sig->abajo->abajo->sig->dato;
        DeterminanteF = No1.inicio->sig->sig->abajo->dato * No1.inicio->sig->abajo->abajo->dato * No1.inicio->dato;

        Res = (DeterminanteA + DeterminanteB + DeterminanteC) - (DeterminanteD + DeterminanteE + DeterminanteF);
    }

    else if(No1.ncolum >= 4){
        cout<<"Tiene que usar Laplace."<<endl;
    }
    return Res;
    }
