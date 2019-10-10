#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"

//*******************************Inicializar array********************************

/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Instrumento Array de Instrumento
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int instrumento_inicializar(Instrumento array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//**************************************Buscar lugar vacio*********************************************
/** \brief Busca el primer lugar vacio en un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//*****************************Buscar por ID********************************************************
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//***********************************Alta**********************************************

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getTexto("\nNombre instrumento: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre) == 0  &&
                utn_getUnsignedInt("\nTipo de instrumento: ","\nError",1,sizeof(int),1,&array[posicion].tipo) == 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\nID: %d",array[posicion].idUnico);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}

//********************************Listar****************************************
/** \brief Lista los elementos de un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                printf("\n ID: %d   Nombre: %s  Tipo: ",
                       array[i].idUnico,array[i].nombre);
                if(array[i].tipo==1)
                    printf("Cuerdas");
                else if(array[i].tipo==2)
                    printf("Viento-madera");
                else if(array[i].tipo==3)
                    printf("Viento-metal");
                else if(array[i].tipo==4)
                    printf("Percusion");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////
void menuInformes()
{
    printf("\n\nMENU INFORMES\n");
    printf("--------------\n");
    printf("1 - listar_orquestas_deLugar\n");
    printf("2 - listar_musicos_menores\n");
    printf("3 - listar_orquestas_menosMusico\n");
    printf("4 - listar_instrumento_orquesta\n");
    printf("5 - listar_orquesta_completa\n");
    printf("6 - imprimir_orquesta_menores\n");
    printf("7 - imprimir_promedio_musico \n");
    printf("8 - listar_musico_instrumentoViento\n");
    printf("9 - SALIR\n");
    printf("Elija opcion: ");
}

void menuPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Agregar Orquesta\n");
    printf("2 - Eliminar orquesta\n");
    printf("3 - Imprimir orquesta\n");
    printf("4 - Agregar musico\n");
    printf("5 - Modificar musico\n");
    printf("6 - Eliminar musico\n");
    printf("7 - Imprimir musico\n");
    printf("8 - Agregar instrumento\n");
    printf("9 - Imprimir instrumento\n");
    printf("10 - Informes\n");
    printf("11 - SALIR\n");
    printf("Elija opcion: ");
}
