#include <iostream>
#include <fstream>
#include "FileMakerOperaciones.h"
using namespace std;

struct Matrix{
    int nfilas;
    int ncolum;
    std::vector<std::vector<int>> Matriz;
    std::string archivename;
};

std::vector<std::vector<int>>Read(std::string archivename, int nfilas, int ncolum){
    ifstream file(archivename);

    file.open(archivename, ios::in);
    vector<vector<int>> Matrix (nfilas);

    for (int i = 0; i < nfilas; ++i) {
        Matrix[i] = vector<int>(ncolum);

        for (int j = 0; j < ncolum; ++j) {
            cout<<"Digite mumeros a almacenar en matriz["<<i<<"]["<<j<<"]: ";
            cin>>Matrix[i][j];
            file>>Matrix[i][j];
        }
    }

    return Matrix;
}
ListaMatriz Lista(Matrix m){
    ListaMatriz Matrix_List = ListaMatriz();
    vector<Nodo*> ListaNodos;

    for (int i = 0; i < m.nfilas; i++){
        for (int j = 0; j < m.ncolum; j ++){
            Nodo *neur = new Nodo;
            neur->value = m.Matriz[i][j];
            neur->sig = nullptr;
            neur->abajo = nullptr;
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

ListaMatriz CargaraArchivo(){
    ListaMatriz Result_List = ListaMatriz();
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

ListaMatriz FileMakerOperaciones::Add(ListaMatriz A, ListaMatriz B) {
    ListaMatriz Result_List = ListaMatriz();
    Matrix Temp_Data;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;

    if (A.nfilas != B.nfilas){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else if (A.ncolum != B.ncolum){
        cout << "\nLa cantidad de filas deben ser iguales, por ende, no se puede realizar la operacion." << endl;
    }else {
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

        Result_List = Lista(Temp_Data);
    }

    return Result_List;
}

ListaMatriz FileMakerOperaciones::Sub(ListaMatriz A, ListaMatriz B) {
    ListaMatriz Result_List = ListaMatriz();
    Matrix Temp_Data;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;
    int Temp1;
    int Temp2;

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
                Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
                Temp_A = Temp_A->sig;
                Temp_B = Temp_B->sig;
                ncolum = ncolum + 1;
            }
            Temp1 = Temp_A->value;
            Temp2 = Temp_B->value;
            Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
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
            Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;
            Temp_A = Temp_A->sig;
            Temp_B = Temp_B->sig;
            ncolum = ncolum + 1;
        }

        Temp1 = Temp_A->value;
        Temp2 = Temp_B->value;
        Matrix[nfilas][ncolum] = Temp_A->value + Temp_B->value;

        Temp_Data.archivename = "";
        Temp_Data.nfilas = A.nfilas;
        Temp_Data.ncolum = B.ncolum;
        Temp_Data.Matriz = Matrix;

        Result_List = Lista(Temp_Data);
    }

    return Result_List;
}

ListaMatriz FileMakerOperaciones::Multi(ListaMatriz A, ListaMatriz B) {
    ListaMatriz Result_List = ListaMatriz();
    Matrix Temp_Data;
    Nodo *Inicio_A = A.inicioMatriz;
    Nodo *Temp_A = A.inicioMatriz;
    Nodo *Inicio_B = B.inicioMatriz;
    Nodo *Temp_B = B.inicioMatriz;
    int nfilas = 0;
    int ncolum = 0;
    int Temp1;
    int Temp2;
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

        Result_List = Lista(Temp_Data);
    }

    return Result_List;
}

int FileMakerOperaciones::Det(ListaMatriz A) {
    int Result = -1;

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

    return Result;
}


int main() {
    int option = -1;
    FileMakerOperaciones FMO;
    ListaMatriz A = ListaMatriz();
    ListaMatriz B = ListaMatriz();
    ListaMatriz Resultado = ListaMatriz();

    cout << "*****File Maker Operations*****" << endl;

    while(option != 7){
        cout << "\nEscoja una opcion: " << endl;
        cout << "1. Cargar matriz al archivo" << endl;
        cout << "2. Suma" << endl;
        cout << "3. Resta" << endl;
        cout << "4. Multiplicacion" << endl;
        cout << "5. Dterminante" << endl;
        cout << "6. Imprimir Matriz" << endl;
        cout << "7. Salir" << endl;

        cin >> option;

        if (option == 1){
            cout << "\n***Cargar Matriz al archivo***" << endl;

            //Check availability.
            if(A.inicioMatriz != nullptr){
                cout << "\nMatriz A ya ha sido cargada." << endl;
            }

            if(B.inicioMatriz != nullptr){
                cout << "\nMatriz B ya ha sido cargada." << endl;
            }

            int selection = -1;
            while (selection != 3){
                cout << "\nEscoja archivo para cargar" << endl;
                cout << "1. Matriz A" << endl;
                cout << "2. Matriz B" << endl;
                cout << "3. Cancelar" << endl;
                cin >> selection;

                if (selection == 1){
                    A = CargaraArchivo();
                    if(A.inicioMatriz != nullptr){
                        cout << "\nMatriz en archivo: " << endl;
                        A.printLista();
                    }
                    break;
                }else if (selection == 2){
                    B = CargaraArchivo();
                    if(B.inicioMatriz != nullptr){
                        cout << "\nMatriz en archivo: " << endl;
                        B.printLista();
                    }
                    break;
                }else if (selection == 3){}else {
                    cout << "Ingrese opcion." << endl;
                }
            }


        }else if (option == 2){
            cout << "\n***Suma***" << endl;
            if (A.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia" << endl;
            }else if (B.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia" << endl;
            }else {
                Resultado = FMO.Add(A, B);
                if (Resultado.inicioMatriz != nullptr){
                    cout << "\nResultado: " << endl;
                    Resultado.printLista();
                }
            }

        }else if (option == 3){
            cout << "\n***Resta***" << endl;
            if (A.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia" << endl;
            }else if (B.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia." << endl;
            }else {
                Resultado = FMO.Sub(A, B);
                if (Resultado.inicioMatriz != nullptr){
                    cout << "\nResultado: " << endl;
                    Resultado.printLista();
                }
            }

        }else if (option == 4){
            cout << "\n***Multiplicacion***" << endl;if (A.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia" << endl;
            }else if (B.inicioMatriz == nullptr){
                cout << "\nMatriz Vacia" << endl;
            }else {
                Resultado = FMO.Multi(A, B);
                if (Resultado.inicioMatriz != nullptr){
                    cout << "Resultado: " << endl;
                    Resultado.printLista();
                }
            }

        }else if (option == 5){
            cout << "\n***Determinante***" << endl;
            int Determinant;
            cout << "Escoja una matriz: " << endl;

            int selection = -1;
            while (selection != 4){
                cout << "Con que matriz desea hacer la operacion? " << endl;
                cout << "1. Matriz A" << endl;
                cout << "2. Matriz B" << endl;
                cout << "3. Ultimo resultado" << endl;
                cout << "4. Cancel" << endl;
                cin >> selection;

                if (selection == 1){
                    Determinant = FMO.Det(A);
                    if(Determinant != -1){
                        cout << "\nDeterminante de A: " << Determinant << endl;
                    }
                }else if (selection == 2){
                    Determinant = FMO.Det(B);
                    if(Determinant != -1){
                        cout << "\nDeterminante de B: " << Determinant << endl;
                    }
                }else if (selection == 3){
                    Determinant = FMO.Det(Resultado);
                    if(Determinant != -1){
                        cout << "\nDeterminante de Ultimo resultado: " << Determinant << endl;
                    }
                }else if (selection == 4){}else {
                    cout << "Porfavor ingrese una opcion valida." << endl;
                }
            }

        }else if (option == 6){
            cout << "\n***Print***" << endl;
            int Determinant;
            cout << "Escoja una matriz: " << endl;

            int selection = -1;
            while (selection != 4){
                cout << "Que matriz desea imprimir? " << endl;
                cout << "1. Matriz A" << endl;
                cout << "2. Matriz B" << endl;
                cout << "3. Ultimo resultado" << endl;
                cout << "4. Cancel" << endl;
                cin >> selection;

                if (selection == 1){
                    if(A.inicioMatriz != nullptr){
                        A.printLista();
                    }else{
                        cout << "\nMatriz Vacia" << endl;
                    }
                }else if (selection == 2){
                    if(B.inicioMatriz != nullptr){
                        B.printLista();
                    }else{
                        cout << "\nMatriz Vacia" << endl;
                    }
                }else if (selection == 3){
                    if(Resultado.inicioMatriz != nullptr){
                        Resultado.printLista();
                    }else{
                        cout << "\nError" << endl;
                    }
                }else if (selection == 4){}else {
                    cout << "Ingrese opcion." << endl;
                }
            }
        }else if (option == 7){}else {
            cout << "Ingrese opcion" << endl;
        }

    }
    
}