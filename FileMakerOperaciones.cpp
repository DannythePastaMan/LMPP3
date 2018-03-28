//
// Created by daniel on 3/20/18.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "FileMakerOperaciones.h"
#include "ListaMatriz.h"
using namespace std;


FileMakerOperaciones::FileMakerOperaciones() {

}

int *FileMakerOperaciones::ReadfromFiles(string archivo, int nfilas, int ncolum){
    ifstream archive(archivo);

    auto **punteromatriz = new int *[nfilas];
    for (int i = 0; i < nfilas; ++i) {
        punteromatriz[i] = new int [ncolum];

        for (int j = 0; j < ncolum; ++j) {
            archive>>punteromatriz[i][j];
        }
    }

    return *punteromatriz;
}
ListaMatriz FileMakerOperaciones::SumaMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Nodo *aux1 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux2 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux3 = reinterpret_cast<Nodo *>(No2.inicioMatriz);
    Nodo *aux4 = reinterpret_cast<Nodo *>(No2.inicioMatriz);

    int nfilas = 0, ncolum = 0, temp1, temp2;

    if(No1.nfilas != No2.nfilas){
        cout<<"Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."<<endl;
    }

    else{
        auto **punteromatriz (reinterpret_cast<int **>(No1.nfilas));

        for (int i = 0; i < No1.nfilas; ++i) {
            punteromatriz[i] = new int(No1.ncolum);
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (aux2->sig != nullptr) {
                        punteromatriz[nfilas][ncolum] = aux2->dato + aux4->dato;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }

                    punteromatriz[nfilas][ncolum] = temp1 - temp2;
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
                    if(aux2->sig != nullptr){
                        punteromatriz[nfilas][ncolum] = aux2->dato + aux4->dato;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }
                }

                Matriz TM;
                TM.nfilas = No1.nfilas;
                TM.ncolum = No2.ncolum;
                TM.punteromatriz = punteromatriz;

        LR = LR.CrearMatriz(TM);
    }
    return LR;
}

ListaMatriz FileMakerOperaciones::RestaMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Nodo *aux1 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux2 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux3 = reinterpret_cast<Nodo *>(No2.inicioMatriz);
    Nodo *aux4 = reinterpret_cast<Nodo *>(No2.inicioMatriz);

    int nfilas = 0, ncolum = 0, temp1, temp2;

    if (No1.nfilas != No2.nfilas) {
        cout
                << "Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."
                << endl;
    } else {
        auto **punteromatriz(reinterpret_cast<int **>(No1.nfilas));

        for (int i = 0; i < No1.nfilas; ++i) {
            punteromatriz[i] = new int(No1.ncolum);
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (aux2->sig != nullptr) {
                        temp1 = aux2->dato;
                        temp2 = aux4->dato;
                        punteromatriz[nfilas][ncolum] = temp1 - temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }


                    temp1 = aux2->dato;
                    temp2 = aux4->dato;
                    punteromatriz[nfilas][ncolum] = temp1 - temp2;
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
                        punteromatriz[nfilas][ncolum] = temp1 - temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }
                }

                temp1 = aux2->dato;
                temp2 = aux4->dato;
                punteromatriz[nfilas][ncolum] = temp1 - temp2;

                Matriz TM;
                TM.nfilas = No1.nfilas;
                TM.ncolum = No2.ncolum;
                TM.punteromatriz = punteromatriz;

                LR = LR.CrearMatriz(TM);
            }
    return LR;
        }

ListaMatriz FileMakerOperaciones::MultiplyMatrices(ListaMatriz No1, ListaMatriz No2) {
    ListaMatriz LR = ListaMatriz();
    Nodo *aux1 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux2 = reinterpret_cast<Nodo *>(No1.inicioMatriz);
    Nodo *aux3 = reinterpret_cast<Nodo *>(No2.inicioMatriz);
    Nodo *aux4 = reinterpret_cast<Nodo *>(No2.inicioMatriz);

    int nfilas = 0, ncolum = 0, temp1, temp2;

    if (No1.nfilas != No2.nfilas) {
        cout
                << "Para poder realizar la suma de matrices se deben tener un numero igual de filas, operacion no realizada."
                << endl;
    } else {
        auto **punteromatriz(reinterpret_cast<int **>(No1.nfilas));

        for (int i = 0; i < No1.nfilas; ++i) {
            punteromatriz[i] = new int(No1.ncolum);
        }

        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolum; ++j) {
                if (aux1->abajo != nullptr) {
                    if (aux2->sig != nullptr) {
                        temp1 = aux2->dato;
                        temp2 = aux4->dato;
                        punteromatriz[nfilas][ncolum] = temp1 * temp2;
                        aux2 = aux2->sig;
                        aux4 = aux4->sig;
                        ncolum = ncolum + 1;
                    }


                    temp1 = aux2->dato;
                    temp2 = aux4->dato;
                    punteromatriz[nfilas][ncolum] = temp1 * temp2;
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
                punteromatriz[nfilas][ncolum] = temp1 * temp2;
                aux2 = aux2->sig;
                aux4 = aux4->sig;
                ncolum = ncolum + 1;
            }
        }

        temp1 = aux2->dato;
        temp2 = aux4->dato;
        punteromatriz[nfilas][ncolum] = temp1 * temp2;

        Matriz TM;
        TM.nfilas = No1.nfilas;
        TM.ncolum = No2.ncolum;
        TM.punteromatriz = punteromatriz;

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
