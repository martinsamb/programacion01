
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "asociado.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array asociado Array of asociado
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int asociado_Inicializar(Asociado array[], int size)                                    //cambiar asociado
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
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int asociado_buscarEmpty(Asociado array[], int size, int* posicion)                    //cambiar asociado
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
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int asociado_buscarID(Asociado array[], int size, int valorBuscado, int* posicion)                    //cambiar asociado
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAsociado==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int asociado_buscarInt(Asociado array[], int size, int valorBuscado, int* posicion)                    //cambiar asociado
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAsociado==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int asociado_buscarString(Asociado array[], int size, char* valorBuscado, int* indice)                    //cambiar asociado
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].idAsociado,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int asociado_alta(Asociado array[], int size, int* contadorID)                          //cambiar asociado
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(asociado_buscarEmpty(array,size,&posicion)==-1)                          //cambiar asociado
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idAsociado=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nID asociado: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idAsociado);           //mensaje + cambiar campo varInt
            utn_getDNI("\nDNI:","\nDNI:",1,12,1, array[posicion].dni);
            utn_getTexto("\nNombre: : ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);
            printf("\n Posicion: %d\n ID Asociado: %d\nDNI: %s\nNombre: %d\nApellido: %d\nEdad: %s",
                   array[posicion].idAsociado,array[posicion].dni,array[posicion].nombre,array[posicion].apellido,array[posicion].edad);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int asociado_baja(Asociado array[], int sizeArray)                                      //cambiar asociado
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(asociado_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idAsociado=0;                                                                   //cambiar campo id
            array[posicion].dni=0;                                                               //cambiar campo varInt
            array[posicion].edad=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].apellido,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int asociado_bajaValorRepetidoInt(Asociado array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int asociado_modificar(Asociado array[], int sizeArray)                                //cambiar asociado
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(asociado_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int asociado_ordenarPorString(Asociado array[],int size)                              //cambiar asociado
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].varInt;                                //cambiar campo varInt
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array asociado Array de asociado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int asociado_listar(Asociado array[], int size)                      //cambiar asociado
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
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


