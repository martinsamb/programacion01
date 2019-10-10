#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int Informes_listarMusico(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);

int listar_orquesta_deLugar(Orquesta array[], int size);
int listar_musico_menores(Musico arrayA[], Orquesta arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int listar_orquesta_menosMusico(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int listar_instrumento_orquesta(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int listar_orquesta_completa(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int imprimir_orquesta_menores(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int imprimir_promedio_musico(Orquesta arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int listar_musico_instrumentoViento(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);


#endif // INFORMES_H_INCLUDED
