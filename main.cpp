#include <iostream>
#include "FileMakerLista.h"
#include "FileMakerOperations.h"
#include <vector>
#include <iostream>
#include <fstream>
using  namespace std;

int main() {
    int option = -1;
    FileMakerOperations FMO;
    FileMakerLista FML;
    FileMakerLista A = FileMakerLista();
    FileMakerLista B = FileMakerLista();
    FileMakerLista Resultado = FileMakerLista();

    cout << "*****File Maker Operations*****" << endl;

    while(option != 7){
        cout << "\nEscoja una opcion: " << endl;
        cout << "1. Cargar matriz al archivo" << endl;
        cout << "2. Suma" << endl;
        cout << "3. Resta" << endl;
        cout << "4. Multiplicacion" << endl;
        cout << "5. Determinante" << endl;
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
                    A = FML.CargaraArchivo();
                    if(A.inicioMatriz != nullptr){
                        cout << "\nMatriz en archivo: " << endl;
                        A.printLista();
                    }
                    break;
                }else if (selection == 2){
                    B = FML.CargaraArchivo();
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

        