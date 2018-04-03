//
// Created by daniel on 4/2/18.
//

#include "FileMakerLista.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <ostream>

using  namespace std;

void FileMakerLista::printLista() {
    Nodo* Rp;

    // pointer to move down
    Nodo* Dp = inicioMatriz;

    // loop till node->down is not NULL
    while (Dp) {
        Rp = Dp;

        // loop till node->right is not NULL
        while (Rp) {
            cout << Rp->value << " ";
            Rp = Rp->sig;
        }
        cout << "\n";
        Dp = Dp->abajo;
    }
}

std::vector<std::vector<int>> FileMakerLista::Read(std::string archivename, int nfilas, int ncolum) {
    ofstream file;
    file.open(archivename.c_str(), ios::app);
    vector<vector<int>> Matrix (nfilas);

    file<<" "<<"\n";
    for (int i = 0; i < nfilas; ++i) {
        Matrix[i] = vector<int>(ncolum);

        for (int j = 0; j < ncolum; ++j) {
            cout<<"Digite numeros a almacenar en matriz["<<i<<"]["<<j<<"]: ";
            cin>>Matrix[i][j];
            file<<" ";
            file<<Matrix[i][j];
        }
        file<<"\n";
    }
    file.close();
    return Matrix;
}

FileMakerLista FileMakerLista::Lista(Matrix m) {
    FileMakerLista Matrix_List = FileMakerLista();
    vector<Nodo*> ListaNodos;

    for (int i = 0; i < m.nfilas; i++){
        for (int j = 0; j < m.ncolum; j ++){
            Nodo *neur = new Nodo;
            neur->value = m.Matriz[i][j];
            neur->sig = neur;
            neur->abajo = neur;
            ListaNodos.push_back(neur);
        }
    }

    for(int N = 0; N < ListaNodos.size(); N ++){
        //Ultimo elemento de Matriz, Inferior Izqierdo.
        if (N == (ListaNodos.size() - 1)){
            ListaNodos[N]->sig = nullptr;
            ListaNodos[N]->abajo = nullptr;
            //Ultima columna de Matriz.
        }else if((N + 1) % m.ncolum == 0){
            if(N != 0){
                ListaNodos[N]->sig = nullptr;
                ListaNodos[N]->abajo = ListaNodos[N + m.ncolum];
            }
            //Ultima fila de Matriz.
        }else if (N >= (ListaNodos.size() - m.ncolum)){
            ListaNodos[N]->sig = ListaNodos[N + 1];
            ListaNodos[N]->abajo = nullptr;
        }else{
            ListaNodos[N]->sig = ListaNodos[N + 1];
            ListaNodos[N]->abajo = ListaNodos[N + m.ncolum];
        }

    }

    Matrix_List.inicioMatriz = ListaNodos[0];
    Matrix_List.nfilas = m.nfilas;
    Matrix_List.ncolum = m.ncolum;

    return Matrix_List;
}

FileMakerLista FileMakerLista::CargaraArchivo() {
    FileMakerLista Result_List = FileMakerLista();
    int ncolum, nfilas;
    string archivename;

    cout << "Ingrese nombre del archivo donde se encuentra la matriz: ";
    cin >> archivename;
    ifstream file(archivename);

    cout << "Cuantas filas tiene la matriz? : ";
    cin >> nfilas;

    cout << "Cuantas columnas tiene la matriz? : ";
    cin >> ncolum;

    Matrix Matriz;

    if(file.good()){
        cout << "\nArchivo encontrado!" << endl;

        Matriz.archivename = archivename;
        Matriz.nfilas = nfilas;
        Matriz.ncolum = ncolum;
        Matriz.Matriz = Read(archivename, nfilas, ncolum);

    }else{
        cout << "El archivo que escribio no existe!" << endl;
        return Result_List;
    }

    Result_List = Lista(Matriz);

    return Result_List;
}
