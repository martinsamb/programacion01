#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h" //cambiar por nombre entidad

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array publicidad Array of publicidadr
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int publicidad_Inicializar(Publicidad array[], int size)                                    //cambiar publicidad
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
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/

int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion)                    //cambiar publicidad
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
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

//int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion);
int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion)                    //cambiar publicidad
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
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

//int publicidad_buscarCuit(Publicidad array[], int size, int valorBuscado, int* indice);
int publicidad_buscarCuit(Publicidad array[], int size, char* valorBuscado, int* indice)                    //cambiar publicidad
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(strcmp(array[i].cuit,valorBuscado)==0)
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
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
//int publicidad_alta(Publicidad array[], int size, int* contadorID)
int publicidad_alta(Publicidad array[], int size, int* contadorID)                          //cambiar publicidad
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(publicidad_buscarEmpty(array,size,&posicion)==-1)                          //cambiar publicidad
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPublicidad=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nID Pantalla: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idPantalla);           //mensaje + cambiar campo varInt
            utn_getCUIT("\nCUIT: ","\nError",1,array[posicion].cuit);
            utn_getUnsignedInt("\nDias a contratar: ","\nError",1,sizeof(int),1,1,1,&array[posicion].dias);           //mensaje + cambiar campo varInt
            utn_getTexto("\nNombre archivo: ","\nError",1,TEXT_SIZE,1,array[posicion].archivo);          //mensaje + cambiar campo varLongString
            printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre archivo: %s\nID Pantalla: %d",
                   array[posicion].idPublicidad,array[posicion].cuit,array[posicion].dias,array[posicion].archivo,array[posicion].idPantalla);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
//int publicidad_baja(Publicidad array[], int sizeArray)
int publicidad_baja(Publicidad array[], int sizeArray)                                      //cambiar publicidad
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(publicidad_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPublicidad=0;                                                                   //cambiar campo id
            array[posicion].idPantalla=0;                                                               //cambiar campo varInt
            array[posicion].dias=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].cuit,"");                                                   //cambiar campo varString
            strcpy(array[posicion].archivo,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
//int publicidad_bajaPantalla(Publicidad array[], int sizeArray, int valorIdPantalla)
int publicidad_bajaPantalla(Publicidad array[], int sizeArray, int valorIDPantalla) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPantalla==valorIDPantalla)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idPublicidad=0;                                                                   //cambiar campo id
                array[i].dias=0;                                                               //cambiar campo varInt
                array[i].idPantalla=0;                                                             //cambiar campo varFloat
                strcpy(array[i].archivo,"");                                                   //cambiar campo varString
                strcpy(array[i].cuit,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}

//****************************************
//int publicidad_bajaPantallaCuit(Publicidad array[],int sizeArray, char* cuitBuscado)
int publicidad_bajaPantallaCuit(Publicidad array[],int sizeArray, char* cuitBuscado)
{
    int retorno=-1;
    int posicion;
    int i;
    int valorIDPantalla;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&valorIDPantalla);
        if(publicidad_buscarID(array,sizeArray,valorIDPantalla,&posicion)==-1)
        {
            printf("\Este ID de pantalla no se encuentra en ninguna contratacion");
        }
        else
        {
            for(i=0;i<sizeArray;i++)
            {
                if(array[i].idPantalla==valorIDPantalla && strcmp(array[i].cuit,cuitBuscado)==0)
                {
                    array[i].isEmpty=1;
                    array[i].idPublicidad=0;
                    strcpy(array[i].cuit,"");
                    array[i].dias=0;
                    strcpy(array[i].archivo,"");
                    array[i].idPantalla=0;
                }
            }
            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
//int publicidad_modificar(Publicidad array[], int sizeArray)
int publicidad_modificar(Publicidad array[], int sizeArray)                                //cambiar publicidad
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla contratada a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(publicidad_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre archivo: %s\nID pantalla: %d",
                       array[posicion].idPublicidad,array[posicion].cuit,array[posicion].dias,array[posicion].archivo,array[posicion].idPantalla);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getCUIT("\nCUIT: ","\nError",1,array[posicion].cuit);             //mensaje + cambiar campo varFloat
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nDias a contratar: ","\nError",1,sizeof(int),1,1,1,&array[posicion].dias);           //mensaje + cambiar campo varInt
                        break;

                    case 'C':
                        utn_getTexto("\nNombre archivo: ","\nError",1,TEXT_SIZE,1,array[posicion].archivo);             //mensaje + cambiar campo varLongString
                        break;

                    case 'D':
                        utn_getUnsignedInt("\nID pantalla: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idPantalla);           //mensaje + cambiar campo varInt
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
* \param array publicidad Array de publicidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
//int publicidad_listar(Publicidad array[], int size)
int publicidad_listar(Publicidad array[], int size)                      //cambiar publicidad
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
                printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre archivo: %s\nID pantalla: %d",
                       array[i].idPublicidad,array[i].cuit,array[i].dias,array[i].archivo,array[i].idPantalla);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

//int publicidad_listarPotCuit(Publicidad array[], int size, char*cuit);



