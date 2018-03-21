//
// Created by daniel on 3/20/18.
//

#ifndef MATRIZLISTAS_FILEMAKEROPERACIONES_H
#define MATRIZLISTAS_FILEMAKEROPERACIONES_H


class FileMakerOperaciones {
public:
    FileMakerOperaciones();
    void WriteFiles();
    void ReadFiles();
    void CrearMatriz(int **, int, int);
    void printMatrix();
    void SumaMatrices(int **, int, int);
    void RestaMatrices(int **, int, int);
    void MultiplyMatrices(int **, int, int);
    void DividirMatrices(int **, int, int);
    void DeterminanteMatriz(int **, int, int);

private:

    int nFilas;
    int nColum;
    int **punteromatriz;
};


#endif //MATRIZLISTAS_FILEMAKEROPERACIONES_H
