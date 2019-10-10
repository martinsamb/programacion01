#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "estudiante.h"

int Informes_listarPorCriterio(eEstudiante arrayA[],eCurso arrayB[], int sizeI, int sizeJ, char* criterio);
int Informes_notaMayorCuatro(eCurso arrayCurso[],int sizeI, eEstudiante arrayEst[],int sizeEst, eMateria arrayMat[],int sizeMat);
int Informes_AlumnosMateria(eEstudiante arrayEst[],eCurso arrayCur[], eMateria arrayMat[], int sizeEst, int sizeCur, int sizeMat, char* criterio);
int Informes_notaMasAlta(eCurso arrayCurso[],int sizeI, eEstudiante arrayEst[],int sizeEst, eMateria arrayMat[],int sizeMat);



#endif // INFORMES_H_INCLUDED
