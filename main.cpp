#include <iostream>
#include "FileMakerOperaciones.h"
using namespace std;

int main() {

    FileMakerOperaciones FMO;

    int opc, nfilas, ncolum, **punteroMatriz;
    cout << "*******Menu*******\n\n---Bienvenido---\n" << endl;

    while(opc != -1){
    cout<< "Ingrese una opcion: \n\n1. Suma de Matrices\n2. Resta de Matrices\n3. Multiplicacion de Matrices\n4. Division de Matrices\n5. Determinante\n""-1. Salir" << endl;
    cin >> opc;

        switch (opc) {
            case 1: {
                string ans = "no";
                cout << "*******Suma de Matrices*******" << endl;
                FMO.SumaMatrices(punteroMatriz, nfilas, ncolum);
                break;
            }

            case 2: {
                cout << "*******Resta de Matrices*******" << endl;
                FMO.RestaMatrices(punteroMatriz, nfilas, ncolum);
                break;
            }

            case 3: {
                cout << "*******Multiplicacion de Matrices*******" << endl;
                FMO.MultiplyMatrices(punteroMatriz, nfilas, ncolum);
                break;
            }

            case 4: {
                cout << "*******Division de Matrices*******" << endl;
                FMO.DividirMatrices(punteroMatriz, nfilas, ncolum);
                break;
            }

            case 5: {
                cout << "*******Determinante*******" << endl;
                FMO.DeterminanteMatriz(punteroMatriz, nfilas, ncolum);
                break;
            }

            case -1: {
                cout << "*******Salir*******" << endl;
                break;
            }
        }
        return 0;
    }
}
