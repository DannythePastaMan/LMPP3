//
// Created by daniel on 4/2/18.
//

#include "FileMakerOperations.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

FileMakerLista FileMakerOperations::Add(FileMakerLista A, FileMakerLista B) {
    FileMakerLista Result_List = FileMakerLista();
    FileMakerLista FML;
    Matrix Temp_Data;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;
    ofstream file;

    if (A.nfilas != B.nfilas){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else if (A.ncolum != B.ncolum){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }
    else {
        vector<vector<int>> Matrix (static_cast<unsigned long>(A.nfilas));

        for (int i = 0; i < A.nfilas; ++i) {
            Matrix[i] = vector<int>(static_cast<unsigned long>(A.ncolum));
        }

        while(Inicio_A->abajo != nullptr){
            while(Temp_A->sig != nullptr){
                Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
                Temp_A = Temp_A->sig;
                Temp_B = Temp_B->sig;
                ncolum = ncolum + 1;
            }
            Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
            Temp_A = Inicio_A->abajo;
            Temp_B = Inicio_B->abajo;
            Inicio_A = Inicio_A->abajo;
            Inicio_B = Inicio_B->abajo;
            nfilas = nfilas + 1;
            ncolum = 0;
        }

        while(Temp_A->sig != nullptr){
            Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
            Temp_A = Temp_A->sig;
            Temp_B = Temp_B->sig;
            ncolum = ncolum + 1;
        }
        Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;

        Temp_Data.archivename = "";
        Temp_Data.nfilas = A.nfilas;
        Temp_Data.ncolum = B.ncolum;
        Temp_Data.Matriz = Matrix;

        file.open("ResultadoSuma.txt", ios::out);
        for (int i = 0; i < A.nfilas; ++i) {
            for (int j = 0; j < B.ncolum; ++j) {
                file<<Matrix[i][j];
            }
        }

        Result_List = FML.Lista(Temp_Data);
    }
    file.close();
    return Result_List;
}

FileMakerLista FileMakerOperations::Sub(FileMakerLista A, FileMakerLista B) {
    FileMakerLista Result_List = FileMakerLista();
    Matrix Temp_Data;
    FileMakerLista FML;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;
    int Temp1;
    int Temp2;
    ofstream file;

    if (A.nfilas != B.nfilas){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else if (A.ncolum != B.ncolum){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else {
        vector<vector<int>> Matrix (static_cast<unsigned long>(A.nfilas));


        for (int i = 0; i < A.nfilas; ++i) {
            Matrix[i] = vector<int>(static_cast<unsigned long>(A.ncolum));
        }

        while(Inicio_A->abajo != NULL){
            while(Temp_A->sig != NULL){
                Temp1 = Temp_A->value;
                Temp2 = Temp_B->value;
                Matrix[nfilas][ncolum] = Temp_A->value - Temp_B->value;
                Temp_A = Temp_A->sig;
                Temp_B = Temp_B->sig;
                ncolum = ncolum + 1;
            }
            Temp1 = Temp_A->value;
            Temp2 = Temp_B->value;
            Matrix[nfilas][ncolum] = Temp_A->value - Temp_B->value;
            Temp_A = Inicio_A->abajo;
            Temp_B = Inicio_B->abajo;
            Inicio_A = Inicio_A->abajo;
            Inicio_B = Inicio_B->abajo;
            nfilas = nfilas + 1;
            ncolum = 0;
        }

        while(Temp_A->sig != NULL){
            Temp1 = Temp_A->value;
            Temp2 = Temp_B->value;
            Matrix[nfilas][ncolum] = Temp_A->value - Temp_B->value;
            Temp_A = Temp_A->sig;
            Temp_B = Temp_B->sig;
            ncolum = ncolum + 1;
        }

        Temp1 = Temp_A->value;
        Temp2 = Temp_B->value;
        Matrix[nfilas][ncolum] = Temp_A->value - Temp_B->value;

        Temp_Data.archivename = "";
        Temp_Data.nfilas = A.nfilas;
        Temp_Data.ncolum = B.ncolum;
        Temp_Data.Matriz = Matrix;

        file.open("ResultadoResta.txt", ios::out);
        for (int i = 0; i < A.nfilas; ++i) {
            for (int j = 0; j < B.ncolum; ++j) {
                file<<Matrix[i][j];
            }
        }

        Result_List = FML.Lista(Temp_Data);
    }
    file.close();
    return Result_List;
}

FileMakerLista FileMakerOperations::Multi(FileMakerLista A, FileMakerLista B) {
    FileMakerLista Result_List = FileMakerLista();
    Matrix Temp_Data;
    FileMakerLista FML;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;
    int Temp1;
    int Temp2;
    ofstream file;

    vector<vector<int>> Matrix (static_cast<unsigned long>(A.nfilas));

    if (A.nfilas != B.nfilas){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else if (A.ncolum != B.ncolum){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else {

        for (int i = 0; i < A.nfilas; ++i) {
            Matrix[i] = vector<int>(static_cast<unsigned long>(A.ncolum));
        }

        while(Inicio_A->abajo != nullptr){
            while(Temp_A->sig != nullptr){
                Temp1 = Temp_A->value;
                Temp2 = Temp_B->value;
                Matrix[nfilas][ncolum] = Temp1 * Temp2;
                Temp_A = Temp_A->sig;
                Temp_B = Temp_B->sig;
                ncolum = ncolum + 1;
            }
            Temp1 = Temp_A->value;
            Temp2 = Temp_B->value;
            Matrix[nfilas][ncolum] = Temp1 * Temp2;
            Temp_A = Inicio_A->abajo;
            Temp_B = Inicio_B->abajo;
            Inicio_A = Inicio_A->abajo;
            Inicio_B = Inicio_B->abajo;
            nfilas = nfilas + 1;
            ncolum = 0;
        }

        while(Temp_A->sig != nullptr){
            Temp1 = Temp_A->value;
            Temp2 = Temp_B->value;
            Matrix[nfilas][ncolum] = Temp1 * Temp2;
            Temp_A = Temp_A->sig;
            Temp_B = Temp_B->sig;
            ncolum = ncolum + 1;
        }
        Temp1 = Temp_A->value;
        Temp2 = Temp_B->value;
        Matrix[nfilas][ncolum] = Temp1 * Temp2;


        Temp_Data.archivename = "";
        Temp_Data.nfilas = A.nfilas;
        Temp_Data.ncolum = B.ncolum;
        Temp_Data.Matriz = Matrix;

        file.open("ResultadoMultiplicacion.txt", ios::out);
        for (int i = 0; i < A.nfilas; ++i) {
            for (int j = 0; j < B.ncolum; ++j) {
                file<<Matrix[i][j];
            }
        }

        Result_List = FML.Lista(Temp_Data);
    }
    file.close();
    return Result_List;
}

int FileMakerOperations::Det(FileMakerLista A) {
    int Result = -1;
    ofstream file;

    if(A.nfilas != A.ncolum){
        cout << "Matriz debe ser cuadrada, operacion no podra ser llevada a cabo." << endl;
    }else if (A.ncolum == 1){
        Result = A.inicioMatriz->value;
    }else if (A.ncolum == 2){
        int D1 = A.inicioMatriz->value * A.inicioMatriz->sig->abajo->value;
        int D2 = A.inicioMatriz->sig->value * A.inicioMatriz->abajo->value;
        Result = D1 - D2;
    }else if (A.ncolum == 3){
        int D11 = A.inicioMatriz->value * A.inicioMatriz->sig->abajo->value * A.inicioMatriz->sig->abajo->sig->abajo->value;
        int D12 = A.inicioMatriz->sig->value * A.inicioMatriz->sig->abajo->sig->value * A.inicioMatriz->abajo->abajo->value;
        int D13 = A.inicioMatriz->abajo->value * A.inicioMatriz->abajo->abajo->sig->value * A.inicioMatriz->sig->sig->value;
        int D21 = A.inicioMatriz->sig->sig->value * A.inicioMatriz->sig->abajo->value * A.inicioMatriz->abajo->abajo->value;
        int D22 = A.inicioMatriz->sig->value * A.inicioMatriz->abajo->value * A.inicioMatriz->sig->sig->abajo->abajo->value;
        int D23 = A.inicioMatriz->sig->sig->abajo->value * A.inicioMatriz->sig->abajo->abajo->value * A.inicioMatriz->value;
        Result = (D11 + D12 + D13) - (D21 + D22 + D23);
    }else {
        cout << "Se debe resolver con las transformadas de Laplace." << endl;
    }

    file.open("ResultadoDeterminante.txt", ios::out);
    file<<Result;
    file.close();
    return Result;
}

FileMakerOperations::FileMakerOperations() {

}
