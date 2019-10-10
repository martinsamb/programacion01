#include "musico.h"
#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;

}Orquesta;

#endif // ORQUESTA_H_INCLUDED

int orquesta_inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
int orquesta_baja(Orquesta arrayO[], int sizeO, Musico arrayM[], int sizeM);
int orquesta_listar(Orquesta array[], int size);


