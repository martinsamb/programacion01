#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#include "publicidad.h"

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Publicidad Array de Publicidad
* \param arrayB Pantalla Array de Pantalla
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPantallasPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0 && cuitBuscado!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayPublicidad[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(arrayPublicidad[i].cuit,cuitBuscado)==0)
            {
                if(pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j)==0)
                {
                    printf("\nID publicidad: %d\nID pantalla: %d\nNombre: %s\nDireccion: %s\nTipo: $s\nPrecio: $.2f",
                    arrayPublicidad[i].idPublicidad,arrayPublicidad[i].idPantalla,arrayPantalla[j].nombre,arrayPantalla[j].direccion,arrayPantalla[j].tipo,arrayPantalla[j].precio);
                }
                else
                {
                    printf("No existe el ID");
                }

            }

        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int Informes_listarFacturacionPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int importe;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0 && cuitBuscado!=NULL)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayPublicidad[i].isEmpty==1 && strcmp(arrayPublicidad[i].cuit,cuitBuscado)!=0)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                importe = (arrayPublicidad[i].dias*arrayPantalla[j].precio);
                printf("\nID Publicidad: %d\nID Pantalla: %d\nDias: %d\nPrecio: %.2f\nImporte: %d",
                       arrayPublicidad[i].idPublicidad,arrayPublicidad[i].idPantalla,arrayPublicidad[i].dias,arrayPantalla[j].precio,importe);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarContrataciones(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayPublicidad[i].isEmpty==1)
                continue;
            else
            {
                pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                printf("\nID Publicidad: %d\nNombre pantalla: %s\nNombre video: %s\nDias: $d\nCuit cliente: %s",
                       arrayPublicidad[i].idPublicidad,arrayPantalla[j].nombre,arrayPublicidad[i].archivo,arrayPublicidad[i].dias,arrayPublicidad[i].cuit);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int importe;
    int auxPosicion;
    int contadorContrataciones;

    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            publicidad_buscarCuit(arrayPublicidad,i-1,arrayPublicidad[i].cuit,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayPublicidad[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCUIT: %s",arrayPublicidad[i].cuit);
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayPublicidad[k].isEmpty!=1 && strcmp(arrayPublicidad[k].cuit,arrayPublicidad[i].cuit)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        contadorContrataciones++;
                        pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                        importe=(arrayPublicidad[k].dias*arrayPantalla[j].precio);
                        printf("\nID publicidad: %d  Importe: %d",arrayPublicidad[k].idPublicidad,importe);

                    }
                }
                printf("\nCantidad contrataciones: %d",contadorContrataciones);
                contadorContrataciones=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

