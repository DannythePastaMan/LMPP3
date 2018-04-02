#include <iostream>
#include "FileMakerOperaciones.h"
using namespace std;

int main() {

    FileMakerOperaciones FMO;
    ListaMatriz m;
    ListaMatriz No1 = ListaMatriz();
    ListaMatriz No2 = ListaMatriz();
    ListaMatriz ResultadoOperacion = ListaMatriz();
    int opc = -1, nfilas, ncolumnas;
    string archivename;

    cout << "*******Menu*******\n\n---Bienvenido---\n" << endl;

    do{
    cout<< "Ingrese una opcion: \n1.Cargar Matriz\n2. Suma de Matrices\n3. Resta de Matrices\n4. Multiplicacion de Matrices\n5. Determinante\n""6. Salir" << endl;
    cin >> opc;

        switch (opc) {
            case 1:{
                cout<<"*****Carga de Matrices*****"<<endl;
                if(No1.inicio != nullptr){
                    cout<<"Ya hay una matriz."<<endl;
                }

                if(No2.inicio != nullptr){
                    cout<<"Ya existe una matriz en este archivo."<<endl;
                }

                else{
                    int des = -1;

                    do{
                        cout<<"*****Bienvenido a la carga de matrices a archivos*****\nPor favor indique donde quiere Cargar la matriz: "<<endl;
                        cout<<"1. Matriz No.1\n2. Matriz No.2\n3. No deseo cargar una matriz."<<endl;
                        cin>>des;
                        switch (des) {
                            case 1: {
                                No1 = m.ReadandWriteOnFile();
                                if (No1.inicio != nullptr) {
                                    cout << "Matriz cargada: ";
                                    No1.printMatrix();
                                }
                                break;
                            }

                            case 2: {
                                No2 = m.ReadandWriteOnFile();

                                if (No2.inicio != nullptr) {
                                    cout << "Matriz cargada: ";
                                    No2.printMatrix();
                                }
                                break;
                            }

                            case 3: {
                                cout << "Ingrese una opcion.";
                                break;
                            }
                        }
                        }while(des != 3);
                    }
                break;
                }

            case 2: {
                cout << "*******Suma de Matrices*******\n"<<endl;
                ResultadoOperacion = FMO.SumaMatrices(No1, No2);

                if(ResultadoOperacion.inicio != nullptr){
                    cout<<"\nResultado de la suma: ";
                    ResultadoOperacion.printMatrix();
                }
            }

            case 3: {
                FMO.RestaMatrices(No1, No2);

                if(ResultadoOperacion.inicio != nullptr){
                    cout<<"Resultado: ";
                    ResultadoOperacion.printMatrix();
                }
                break;
            }

            case 4: {
                cout << "*******Multiplicacion de Matrices*******\nPor favor, cargue matrices a los archivos." << endl;

                FMO.MultiplyMatrices(No1, No2);
                if(ResultadoOperacion.inicio != nullptr){
                    cout<<"Resultado: ";
                    ResultadoOperacion.printMatrix();
                }
                break;
            }

            case 5: {
                cout << "*******Determinante*******" << endl;

                cout<<"En este caso, requerimos de su ingreso a la matriz a la que desea aplicar esta operacion"<<endl;
                int des = -1;

                while(des != 4){
                    cout<<"A continuacion, se le pedira escojer una matriz a imprimir, para tomar la decision a cual aplicarle la operacion: "<<endl;
                    cout<<"1. Matriz 1\n 2. Matriz 2"<<endl;
                    cin>>des;

                    switch(des){
                        case 1:{
                            if(No1.inicio != nullptr){
                                No1.printMatrix();
                                FMO.DeterminanteMatriz(No1);
                            }
                            break;
                        }

                        case 2:{
                            if(No2.inicio != nullptr){
                                No2.printMatrix();
                                FMO.DeterminanteMatriz(No2);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 6: {
                cout << "*******Salir*******" << endl;
                break;
            }
        }
    }while(opc != 6);
}
