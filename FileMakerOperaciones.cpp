//
// Created by daniel on 3/20/18.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "FileMakerOperaciones.h"
using namespace std;


FileMakerOperaciones::FileMakerOperaciones() {
    this->nColum = nColum;
    this->nFilas = nFilas;
    this->punteromatriz = punteromatriz;

}

void FileMakerOperaciones::CrearMatriz(int **, int, int) {
    cout<<"Num filas: ";
    cin>>nFilas;

    cout<<"\nNum columnas: ";
    cin>>nColum;

    punteromatriz = new int *[nFilas];
    for (int i = 0; i < nFilas; ++i) {
        punteromatriz[i] = new int [nColum];
    }

    cout<<"\nDigitando elementos de la matriz: \n";
    for (int i = 0; i < nFilas; ++i) {
        for (int j = 0; j < nColum; ++j) {
            cout<<"\nDigite un numero["<<i<<"]["<<j<<"]: ";
            cin>>*(*(punteromatriz+i)+j);
        }
    }
}

void FileMakerOperaciones::printMatrix() {
    int nFilas;
    int nColum;
    int **punteromatriz;

cout<<"*****Matriz*****"<<endl;
    for (int i = 0; i < nFilas; ++i) {
        for (int j = 0; j < nColum; ++j) {
            cout<<*(*(punteromatriz+i)+j)<<" ";
        }
    cout<<"\n";
    }
}

void FileMakerOperaciones::WriteFiles() {
    ofstream archive1, archive2, archive3,archive4;

    archive1.open("Matriz1.txt", ios::out);
    archive2.open("Matriz2.txt", ios::out);
    archive3.open("Matriz3.txt", ios::out);
    archive4.open("Matriz4.txt", ios::out);

    if(archive1.fail()||archive2.fail()||archive3.fail()||archive4.fail()){
        cout<<"No se pudo abrir archivo.";
        exit(1);
    }

    else{
        cout<<"\nA continuacion se le pedira crear matrices(4), por favor digitelas en los siguientes enunciados: \n"<<endl;
        for (int i = 0; i < 4; ++i) {
            CrearMatriz(punteromatriz, nFilas, nColum);
        }
        printMatrix();
        cout<<"Matrices creadas exitosamente"<<endl;
        cout<<"Archivos Creados"<<endl;
    }

    archive1.close();
    archive2.close();
    archive3.close();
    archive4.close();
}

void FileMakerOperaciones::ReadFiles() {
    ifstream archive;
    string text;

    archive.open("Juego.txt", ios::in);

    if(archive.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archive.eof()){
        getline(archive, text);
        cout<<text<<endl;
    }
    archive.close();
}

void FileMakerOperaciones::SumaMatrices(int **punteromatrizSuma, int nfilasSuma, int ncolumnasSuma) {
    WriteFiles();
}

void FileMakerOperaciones::RestaMatrices(int **, int, int) {
    WriteFiles();

}

void FileMakerOperaciones::MultiplyMatrices(int **, int, int) {
    WriteFiles();

}

void FileMakerOperaciones::DividirMatrices(int **, int, int) {
    WriteFiles();
}

void FileMakerOperaciones::DeterminanteMatriz(int **, int, int) {
    WriteFiles();
}
