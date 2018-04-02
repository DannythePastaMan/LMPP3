//
// Created by daniel on 4/2/18.
//

#ifndef MATRIZLISTAS_FILEMAKEROPERATIONS_H
#define MATRIZLISTAS_FILEMAKEROPERATIONS_H

#include "FileMakerLista.h"
#include <iostream>
#include <vector>

class FileMakerOperations {
public:
    FileMakerLista Add(FileMakerLista, FileMakerLista);
    FileMakerLista Sub(FileMakerLista, FileMakerLista);
    FileMakerLista Multi(FileMakerLista, FileMakerLista);
    int Det(FileMakerLista);
    FileMakerOperations();

};


#endif //MATRIZLISTAS_FILEMAKEROPERATIONS_H
