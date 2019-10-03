#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array pantalla Array of pantalla
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int pantalla_Inicializar(Pantalla array[], int size)                                    //cambiar pantalla
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion)                    //cambiar pantalla
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* posicion)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPantalla==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pantalla_alta(Pantalla array[], int size, int* contadorID)                          //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(pantalla_buscarEmpty(array,size,&posicion)==-1)                          //cambiar pantalla
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPantalla=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo varString
            utn_getTexto("\nDireccion: ","\nError",1,TEXT_SIZE,1,array[posicion].direccion);                 //mensaje + cambiar campo varLongString
            utn_getName("\nTipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);                      //mensaje + cambiar campo varString
            utn_getFloat("\nPrecio por dia: ","\nError",1,sizeof(float),0,1,1,&array[posicion].precio);             //mensaje + cambiar campo varFloat

            printf("\n ID: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f",array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].tipo,array[posicion].precio);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int pantalla_baja(Pantalla array[], int sizeArray, int* id)                                      //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPantalla=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].direccion,"");                                               //cambiar campo varLongString
            strcpy(array[posicion].tipo,"");
            array[posicion].precio=0;                                               //cambiar campo varLongString

            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int pantalla_modificar(Pantalla array[], int sizeArray)                                //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\nID: %d\nNombre: %d\nDireccion: %d\nTipo: %s\nPrecio: %.2f",
                       array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].tipo,array[posicion].precio);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo varString
                        break;
                    case 'B':
                        utn_getTexto("\nDireccion: ","\nError",1,TEXT_SIZE,1,array[posicion].direccion);
                        break;
                    case 'C':
                        utn_getName("\nTipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getFloat("\nPrecio por dia: ","\nError",1,sizeof(float),0,1,1,&array[posicion].precio);
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

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int pantalla_listar(Pantalla array[], int size)                      //cambiar pantalla
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
                printf("\nPosicion: %d\nID: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f *****",i,
                       array[i].idPantalla,array[i].nombre,array[i].direccion,array[i].tipo,array[i].precio);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}



