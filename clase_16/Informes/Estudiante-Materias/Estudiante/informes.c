#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "estudiante.h"  //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA eEstudiante Array de eEstudiante
* \param arrayB eEstudiante Array de eEstudiante
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(eEstudiante arrayA[],eCurso arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    int encontrado;

     if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1)
             {
                continue;
             }
            if(strcmp(arrayA[i].nombre,criterio)==0)
            {
                for(j=0;j<sizeJ;j++)
                {
                    encontrado=-1;
                    encontrado=estudiante_buscarIDCurso(arrayB,sizeJ,arrayA[i].idEstudiante,j);
                    if(encontrado==0)
                    {
                        printf("\nListado ID Estudiante: %d  ID Materia: %d ", arrayA[i].idEstudiante,arrayB[j].idMateria);
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int Informes_notaMayorCuatro(eCurso arrayCurso[],int sizeI, eEstudiante arrayEst[],int sizeEst, eMateria arrayMat[],int sizeMat)
{
    int retorno=-1;
    int i;

    char nombreAlumno[TEXT_SIZE];
    char nombreMateria[TEXT_SIZE];

     if(arrayCurso!=NULL && sizeI>=0 && arrayEst!=NULL && sizeEst>=0)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayCurso[i].isEmpty==1)
             {
                continue;
             }
            if(arrayCurso[i].nota>4)
            {
                //buscar nombre alumno
                if(estudiante_buscarNombrePorId(arrayEst, sizeI,arrayCurso[i].idEstudiante,nombreAlumno)==0);
                {
                    //buscar nombre materia
                    if(materia_buscarNombrePorId(arrayMat, sizeMat, arrayCurso[i].idMateria,nombreMateria)==0)
                    {
                        printf("\nListado ID Estudiante: %d Nombre: %s ID Materia: %d %s Nota:%d", arrayCurso[i].idEstudiante, nombreAlumno,arrayCurso[i].idMateria,nombreMateria, arrayCurso[i].nota);
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
int Informes_AlumnosMateria(eEstudiante arrayEst[],eCurso arrayCur[], eMateria arrayMat[], int sizeEst, int sizeCur, int sizeMat, char* criterio)
{
    int retorno=-1;
    int i;
    int j;
    int encontrado;
    int idMateria;
    int posicion;

     if(arrayEst!=NULL && sizeEst>=0 && arrayCur!=NULL && sizeCur>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeMat;i++)
        {
            if(arrayEst[i].isEmpty==1)
             {
                continue;
             }
             encontrado= materia_buscarIdPorNombre(arrayMat,sizeMat,criterio,&idMateria);
             if(encontrado==0)
             {
                for(j=0;j<sizeCur;j++)
                {
                    if(idMateria==arrayCur[j].idMateria)
                    {
                        //Buscar nombre alumno
                        estudiante_buscarID(arrayEst,sizeEst,arrayCur[j].idEstudiante,&posicion);
                        printf("\nListado Nombre Estudiante: %s  Nota: %d ", arrayEst[posicion].nombre,arrayCur[j].nota);
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int Informes_notaMasAlta(eCurso arrayCurso[],int sizeI, eEstudiante arrayEst[],int sizeEst, eMateria arrayMat[],int sizeMat)
{
    int maxNota;
    int i;
    char materia[TEXT_SIZE];
    int idEstudiante;
    char nombreEst[TEXT_SIZE];

    printf("\n Materia         alumno           nota");
     if(arrayEst!=NULL && sizeEst>=0 && arrayCurso!=NULL && sizeI>=0)
    {
        for(i=0;i<sizeMat;i++)
        {
            if(arrayMat[i].isEmpty==1)
             {
                continue;
             }
            maxNota=0;
            if(materia_buscarMayorNota(arrayCurso,sizeI,arrayMat[i].idMateria,&maxNota, &idEstudiante)==0)
            {
                strcpy(materia,"");
                materia_buscarNombrePorId(arrayMat,sizeMat,arrayMat[i].idMateria,materia);
                strcpy(nombreEst,"");
                estudiante_buscarNombrePorId(arrayEst, sizeEst,idEstudiante,nombreEst);
                printf("\n%s        %s         %d", materia, nombreEst, maxNota);
            }
        }
    }
    return 0;
}
