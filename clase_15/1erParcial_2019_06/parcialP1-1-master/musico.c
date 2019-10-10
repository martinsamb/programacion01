#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"

//***************************************Inicializar*****************************************************
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Musico Array de Musico
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int musico_inicializar(Musico array[], int size)
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

//***************************************Busscar lugar vacio*********************************************
/** \brief Busca el primer lugar vacio en un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
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
//*****************************buscar por ID*******************************************************
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
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

//*********************musico buscar orquesta***********************************************
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarOrquesta(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//*******************************musico buscar instrumento*****************************************
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInstrumento(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//**********************************Alta*******************************************************
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getName("\nNombre del musico: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre) == 0 &&
                utn_getName("\nApellido del musico: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido) == 0 &&
                utn_getUnsignedInt("\nEdad del musico: ","\nError",1,3,1,&array[posicion].edad) == 0 &&
                utn_getUnsignedInt("\nID Orquesta: ","\nError",1,sizeof(int),1,&array[posicion].idOrquesta) == 0 &&
                utn_getUnsignedInt("\nID Instrumento: ","\nError",1,sizeof(int),1,&array[posicion].idInstrumento) == 0 )
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Edad: %d\n ID orquesta: %d\n ID Instrumento: %d",
                       array[posicion].idUnico,
                       array[posicion].nombre,
                       array[posicion].apellido,
                       array[posicion].edad,
                       array[posicion].idOrquesta,
                       array[posicion].idInstrumento);
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


//***********************************Baja**********************************
/** \brief Borra un elemento del array por ID
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID de musico a cancelar: ","\nError",1,sizeof(int),1,&id);          //cambiar si no se busca por ID
        if(
           musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].edad=0;
            array[posicion].idOrquesta=0;
            array[posicion].idInstrumento=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}

//*********************Baja valor repetido*********************************
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].edad=0;
                array[i].idOrquesta=0;
                array[i].idInstrumento=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].apellido,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

//********************************Modificar*************************************************
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID musico a modificar: ","\nError",1,sizeof(int),1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Edad: %d\n ID orquesta: %d\n ID Instrumento: %d",
                       array[posicion].idUnico,
                       array[posicion].nombre,
                       array[posicion].apellido,
                       array[posicion].edad,
                       array[posicion].idOrquesta,
                       array[posicion].idInstrumento);
                utn_getLetra("\nModificar: A: Edad B: ID orquesta S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nEdad: ","\nError",1,3,1,&array[posicion].edad);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nID Orquesta: ","\nError",1,sizeof(int),1,&array[posicion].idOrquesta);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************Listar***************************
/** \brief Lista los elementos de un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
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
                printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d",                  //Imprimo tmb edad porque nunca me lo pide...
                       array[i].idUnico,
                       array[i].nombre,
                       array[i].apellido,
                       array[i].edad);
        }
        retorno=0;
    }
    return retorno;
}

//****************************Ordenar*************************************
/** \brief Ordena por campo apellido los elementos de un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorApellido(Musico array[],int size)                              //cambiar Tipo
{
    int retorno=-1;
    int i, j;
    char bufferApellido[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferEdad;                                              //cambiar buffer int
    int bufferIdOrquesta;                                              //cambiar buffer int
    int bufferIdInstrumento;                                              //cambiar buffer int
    char bufferNombre[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            strcpy(bufferApellido,array[i].apellido);                      //cambiar campo varString
            bufferEdad=array[i].edad;                                //cambiar campo varInt
            bufferIdOrquesta=array[i].idOrquesta;                                //cambiar campo varInt
            bufferIdInstrumento=array[i].idInstrumento;                                //cambiar campo varInt
            strcpy(bufferNombre,array[i].nombre);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferApellido,array[j].apellido)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                strcpy(array[j + 1].apellido,array[j].apellido);          //cambiar campo varString

                array[j + 1].edad=array[j].edad;                        //cambiar campo varInt
                array[j + 1].idOrquesta=array[j].idOrquesta;                        //cambiar campo varInt
                array[j + 1].idInstrumento=array[j].idInstrumento;                        //cambiar campo varInt

                strcpy(array[j + 1].nombre,array[j].nombre);  //cambiar campo varLongString

                j--;
            }
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            strcpy(array[j + 1].apellido,bufferApellido);                     //cambiar campo varString

            array[j + 1].edad=bufferEdad;                                                        //cambiar campo varInt
            array[j + 1].idOrquesta=bufferIdOrquesta;                                                        //cambiar campo varInt
            array[j + 1].idInstrumento=bufferIdInstrumento;                                                        //cambiar campo varInt

            strcpy(array[j + 1].nombre,bufferNombre);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

