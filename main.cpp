#include <iostream>
#include "FileMakerOperaciones.h"
using namespace std;

int main() {

    FileMakerOperaciones FMO;
    ListaMatriz m;
    ListaMatriz No1 = ListaMatriz();
    ListaMatriz No2 = ListaMatriz();
    ListaMatriz ResultadoOperacion = ListaMatriz();
    int opc = -1;

    cout << "*******Menu*******\n\n---Bienvenido---\n" << endl;

    while(opc < 5){
    cout<< "Ingrese una opcion: \n\n1. Suma de Matrices\n2. Resta de Matrices\n3. Multiplicacion de Matrices\n4. Determinante\n""5. Salir" << endl;
    cin >> opc;

        switch (opc) {
            case 1: {
                cout << "*******Suma de Matrices*******\nPor favor, cargue matrices a los archivos."<<endl;
                if(No1.inicioMatriz != nullptr){
                    cout<<"Ya hay una matriz."<<endl;
                }

                if(No2.inicioMatriz != nullptr){
                    cout<<"Ya existe una matriz en este archivo."<<endl;
                }

                else{
                    int des = -1;

                    while(des != 3){
                        cout<<"*****Bienvenido a la carga de matrices a archivos*****\nPor favor indique donde quiere Cargar la matriz: "<<endl;
                        cout<<"1. Matriz No.1\n2. Matriz No.2\n3. No deseo cargar una matriz."<<endl;
                        cin>>des;
                        switch (des){
                            case 1:{
                                No1 = m.cargarMatriz();

                                if(No1.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No1.printMatrix();
                                }
                                break;
                            }

                            case 2:{
                                No2 = m.cargarMatriz();

                                if(No2.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No2.printMatrix();
                                }
                                break;
                            }

                            case 3:{
                                    cout<<"Ingrese una opcion.";
                            }

                            default: {
                                break;
                            }
                        }
                    }
                }

                ResultadoOperacion = FMO.SumaMatrices(No1, No2);

                if(ResultadoOperacion.inicioMatriz != nullptr){
                    cout<<"\nResultado de la suma: ";
                    ResultadoOperacion.printMatrix();
                }
            }

            case 2: {
                cout << "*******Resta de Matrices*******\nPor favor, cargue matrices a los archivos." << endl;
                if(No1.inicioMatriz != nullptr){
                    cout<<"Ya hay una matriz."<<endl;
                }

                if(No2.inicioMatriz != nullptr){
                    cout<<"Ya existe una matriz en este archivo."<<endl;
                }

                else{
                    int des = -1;

                    while(des != 3){
                        cout<<"*****Bienvenido a la carga de matrices a archivos*****\nPor favor indique donde quiere Cargar la matriz: "<<endl;
                        cout<<"1. Matriz No.1\n2. Matriz No.2\n3. No deseo cargar una matriz."<<endl;
                        cin>>des;
                        switch (des){
                            case 1:{
                                No1 = m.cargarMatriz();

                                if(No1.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No1.printMatrix();
                                }
                                break;
                            }

                            case 2:{
                                No2 = m.cargarMatriz();

                                if(No2.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No2.printMatrix();
                                }
                                break;
                            }

                            case 3:{
                                cout<<"Ingrese una opcion.";
                            }

                            default: {
                                break;
                            }
                        }
                    }
                }

                FMO.RestaMatrices(No1, No2);

                if(ResultadoOperacion.inicioMatriz != nullptr){
                    cout<<"Resultado: ";
                    ResultadoOperacion.printMatrix();
                }
                break;
            }

            case 3: {
                cout << "*******Multiplicacion de Matrices*******\nPor favor, cargue matrices a los archivos." << endl;
                if(No1.inicioMatriz != nullptr){
                    cout<<"Ya hay una matriz."<<endl;
                }

                if(No2.inicioMatriz != nullptr){
                    cout<<"Ya existe una matriz en este archivo."<<endl;
                }

                else{
                    int des = -1;

                    while(des != 3){
                        cout<<"*****Bienvenido a la carga de matrices a archivos*****\nPor favor indique donde quiere Cargar la matriz: "<<endl;
                        cout<<"1. Matriz No.1\n2. Matriz No.2\n3. No deseo cargar una matriz."<<endl;
                        cin>>des;
                        switch (des){
                            case 1:{
                                No1 = m.cargarMatriz();

                                if(No1.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No1.printMatrix();
                                }
                                break;
                            }

                            case 2:{
                                No2 = m.cargarMatriz();

                                if(No2.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No2.printMatrix();
                                }
                                break;
                            }

                            case 3:{
                                cout<<"Ingrese una opcion.";
                            }

                            default: {
                                break;
                            }
                        }
                    }
                }

                FMO.MultiplyMatrices(No1, No2);
                if(ResultadoOperacion.inicioMatriz != nullptr){
                    cout<<"Resultado: ";
                    ResultadoOperacion.printMatrix();
                }
                break;
            }

            case 4: {
                cout << "*******Determinante*******" << endl;
                if(No1.inicioMatriz != nullptr){
                    cout<<"Ya hay una matriz."<<endl;
                }

                if(No2.inicioMatriz != nullptr){
                    cout<<"Ya existe una matriz en este archivo."<<endl;
                }

                else{
                    int des = -1;

                    while(des != 3){
                        cout<<"*****Bienvenido a la carga de matrices a archivos*****\nPor favor indique donde quiere Cargar la matriz: "<<endl;
                        cout<<"1. Matriz No.1\n2. Matriz No.2\n3. No deseo cargar una matriz."<<endl;
                        cin>>des;
                        switch (des){
                            case 1:{
                                No1 = m.cargarMatriz();

                                if(No1.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No1.printMatrix();
                                }
                                break;
                            }

                            case 2:{
                                No2 = m.cargarMatriz();

                                if(No2.inicioMatriz != nullptr){
                                    cout<<"Matriz cargada: ";
                                    No2.printMatrix();
                                }
                                break;
                            }

                            case 3:{
                                cout<<"Ingrese una opcion.";
                            }

                            default: {
                                break;
                            }
                        }
                    }
                }

                cout<<"En este caso, requerimos de su ingreso a la matriz a la que desea aplicar esta operacion"<<endl;
                int des = -1;

                while(des != 4){
                    cout<<"A continuacion, se le pedira escojer una matriz a imprimir, para tomar la decision a cual aplicarle la operacion: "<<endl;
                    cout<<"1. Matriz 1\n 2. Matriz 2"<<endl;
                    cin>>des;

                    switch(des){
                        case 1:{
                            if(No1.inicioMatriz != nullptr){
                                No1.printMatrix();
                                FMO.DeterminanteMatriz(No1);
                            }
                            break;
                        }

                        case 2:{
                            if(No2.inicioMatriz != nullptr){
                                No2.printMatrix();
                                FMO.DeterminanteMatriz(No2);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 5: {
                cout << "*******Salir*******" << endl;
                break;
            }
        }
        return 0;
    }
}
