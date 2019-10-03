#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/


int publicacion_Inicializar(ePublicacion array[], int size)                                    //cambiar fantasma
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

int fantasma_Inicializar(Fantasma array[], int size)                                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
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

int pantalla_buscarEmpty(ePantalla array[], int size, int* posicion)                    //cambiar fantasma
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

int publicacion_buscarEmpty(ePublicacion array[], int size, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_buscarID(ePantalla array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
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

int publicacion_buscarID(ePublicacion array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
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

int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmpleado==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int findEmployeeById2(Employee array[], int size, int valorBuscado)                    //cambiar fantasma
{

    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmpleado==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/


int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_buscarInt(ePantalla array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPantalla==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_buscarInt(ePublicacion array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPublicacion==valorBuscado)                                                   //cambiar campo varInt
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/


int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_buscarString(ePantalla array[], int size, char* valorBuscado, int* indice)                    //BUSCA POR NOMBRE DE LA PANTALLA EJ PANTALLA.OBELISCO
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_buscarString(ePublicacion array[], int size, char* valorBuscado, int* indice)//BUSCA POR CUIT                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].cuit,valorBuscado)==0)                                        //cambiar campo varString
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/

int fantasma_alta(Fantasma array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,99,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_alta(ePantalla array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(pantalla_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPantalla=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("\nDime el tipo de Pantalla: LCD - LED","\nError",1,TEXT_SIZE,1,array[posicion].tipo);                 //mensaje + cambiar campo varLongString
            utn_getTexto("\nNombre de Pantalla:","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                 //mensaje + cambiar campo varLongString
            utn_getTexto("\nDireccion:","\nError",1,TEXT_SIZE,1,array[posicion].direccion);                 //mensaje + cambiar campo varLongString
            utn_getFloat("\nPrecio por dia de publicacion","\nError",1,sizeof(float),1,5000,2,&array[posicion].precio);             //mensaje + cambiar campo varFloat

            printf("La pantalla con nombre: %s se encuentra en la direccion: %s con un precio de publicacion diario de %f cuyo id:%d"
                   ,array[posicion].nombre,array[posicion].direccion,array[posicion].precio,array[posicion].idPantalla);
            retorno=0;
        }
    }
    return retorno;
}

int publicacion_alta(ePublicacion array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(publicacion_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPublicacion=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nDime la ID de la Pantalla donde deseas publicar","Error",1,sizeof(int),1,1000,3,&array[posicion].idPantalla);
            utn_getTexto("\nDime tu CUIT","\nError",1,TEXT_SIZE,1,array[posicion].cuit);                 //mensaje + cambiar campo varLongString
            utn_getTexto("\nNombre del archivo","\nError",1,TEXT_SIZE,1,array[posicion].nombreArchivo);                 //mensaje + cambiar campo varLongString
            utn_getUnsignedInt("\nDime la cantidad de dias de la publicacion","Error",1,sizeof(int),1,365,3,&array[posicion].diasPublicacion);



             retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/

int fantasma_baja(Fantasma array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_baja(ePantalla array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPantalla=0;                                                                   //cambiar campo id
            array[posicion].precio=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].direccion,"");
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].tipo,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

int publicacion_baja(ePublicacion array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    char letra;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(publicacion_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else

        {
           printf("Realmente desea elimitar la publicacion? s-n");

            scanf("%c",&letra);
            if(letra=='s')
                {
                    array[posicion].isEmpty=1;
                    array[posicion].idPublicacion=0;
                    array[posicion].idPantalla=0;                                                                   //cambiar campo id
                    array[posicion].diasPublicacion=0;                                                             //cambiar campo varFloat
                    strcpy(array[posicion].nombreArchivo,"");
                    strcpy(array[posicion].cuit,"");                                               //cambiar campo varLongString
                    retorno=0;


                }
        }
    }
    return retorno;
}



//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/

int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                strcpy(array[i].varLongString,"");






                                                            //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}
int pantalla_bajaValorRepetidoInt(ePantalla array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPantalla==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                    array[i].isEmpty=1;
                    array[i].idPantalla=0;                                                                   //cambiar campo id
                    array[i].precio=0;                                                             //cambiar campo varFloat
                    strcpy(array[i].direccion,"");
                    strcpy(array[i].nombre,"");                                                   //cambiar campo varString
                    strcpy(array[i].tipo,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}
int publicacion_bajaValorRepetidoInt(ePublicacion array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPublicacion==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idPublicacion=0;
                array[i].idPantalla=0;                                                                   //cambiar campo id
                array[i].diasPublicacion=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombreArchivo,"");
                strcpy(array[i].cuit,"");                                                 //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return    int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/



int fantasma_modificar(Fantasma array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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

int pantalla_modificar(ePantalla array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n Tipo de Pantalla: %s\n Direccion de pantalla: %s\n Precio diario de publicacion: %f",
                       posicion, array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].precio);
                utn_getChar("\nModificar: \nA:tipo \nB:nombre \nC:Direccion \nD: Precio \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nDime el tipo de Pantalla: LCD - LED","\nError",1,TEXT_SIZE,1,array[posicion].tipo);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'B':
                        utn_getTexto("\nNombre de Pantalla:","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'C':
                        utn_getTexto("\nDireccion:","\nError",1,TEXT_SIZE,1,array[posicion].direccion);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'D':
                        utn_getFloat("\nPrecio por dia de publicacion","\nError",1,sizeof(float),1,5000,2,&array[posicion].precio);             //mensaje + cambiar campo varFloat
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

int publicacion_modificar(ePublicacion array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(publicacion_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta

                printf("\n Posicion: %d \n CUIT: %s \n Nombre del Archivo :%s \n Cantidad de dias de publicacion: %d \nID: %d \n ID Pantalla: %d",posicion,array[posicion].cuit,array[posicion].nombreArchivo,
                       array[posicion].diasPublicacion,array[posicion].idPublicacion,array[posicion].idPantalla);

                utn_getChar("\nModificar: \nA:CUIT \nB: Nombre del Archivo \nC: Dias de publicacion \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nDime tu CUIT","\nError",1,TEXT_SIZE,1,array[posicion].cuit);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'B':
                        utn_getTexto("\nNombre del archivo","\nError",1,TEXT_SIZE,1,array[posicion].nombreArchivo);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'C':
                        utn_getUnsignedInt("\nDime la cantidad de dias de la publicacion","Error",1,sizeof(int),1,365,3,&array[posicion].diasPublicacion);
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/


int fantasma_ordenarPorString(Fantasma array[],int size)                              //cambiar fantasma
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

int pantalla_ordenarPorString(ePantalla array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;

    int bufferId;
    int bufferIsEmpty;
    char bufferNombre[TEXT_SIZE];
    char bufferTipo[TEXT_SIZE];
    char bufferDireccion[TEXT_SIZE];
    float bufferPrecio;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);
            strcpy(bufferDireccion,array[i].direccion);                      //cambiar campo varString
            bufferId=array[i].idPantalla;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferTipo,array[i].tipo);
            bufferPrecio=array[i].precio;


            j = i - 1;
            while ((j >= 0) && strcmp(bufferNombre,array[j].nombre)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo varString
                strcpy(array[j + 1].direccion,array[j].direccion);          //cambiar campo varString
                array[j + 1].idPantalla=array[j].idPantalla;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].tipo,array[j].tipo);
                array[j + 1].precio=array[j].precio;

                j--;
            }


                strcpy(array[j + 1].nombre,bufferNombre);          //cambiar campo varString
                strcpy(array[j + 1].direccion,bufferDireccion);          //cambiar campo varString
                array[j + 1].idPantalla=bufferId;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].tipo,bufferTipo);
                array[j + 1].precio=bufferPrecio;

        }
        retorno=0;
    }
    return retorno;
}

int publicacion_ordenarPorString(ePublicacion array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;
    int bufferIdPublicacion;
    int bufferIsEmpty;
    int bufferDiasPublicacion;
    int bufferidPantalla;
    char bufferCUIT[TEXT_SIZE];
    char bufferNombreVideo[TEXT_SIZE];
    float bufferPrecio;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombreVideo,array[i].nombreArchivo);
            strcpy(bufferCUIT,array[i].cuit);
            bufferIsEmpty=array[i].isEmpty;
            bufferidPantalla=array[i].idPantalla;
            bufferDiasPublicacion=array[i].diasPublicacion;
            bufferIdPublicacion=array[i].idPublicacion;

            j = i - 1;

            while ((j >= 0) && strcmp(bufferCUIT,array[j].cuit)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                    strcpy(array[j + 1].cuit,array[j].cuit);          //cambiar campo varString
                    strcpy(array[j + 1].nombreArchivo,array[j].nombreArchivo);          //cambiar campo varString
                    array[j + 1].idPantalla=array[j].idPantalla;                                //cambiar campo id
                    array[j + 1].isEmpty=array[j].isEmpty;
                    array[j + 1].diasPublicacion=array[j].diasPublicacion;
                    array[j + 1].idPublicacion=array[j].idPublicacion;

                    j--;
            }


                strcpy(array[j + 1].cuit,bufferCUIT);          //cambiar campo varString
                strcpy(array[j + 1].nombreArchivo,bufferNombreVideo);          //cambiar campo varString
                array[j + 1].idPantalla=bufferidPantalla;                                //cambiar campo id
                array[j + 1].isEmpty=bufferIsEmpty;                                //cambiar campo id
                array[j + 1].diasPublicacion=bufferDiasPublicacion;
                array[j + 1].idPublicacion=bufferIdPublicacion;

        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size)                      //cambiar fantasma
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
int pantalla_listar(ePantalla array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else
               // printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos

               printf("\n Posicion: %d\n ID: %d\n Tipo de Pantalla: %s\n Direccion de pantalla: %s\n Precio diario de publicacion: %f",
                       posicion, array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].precio);
        }
        retorno=0;
    }
    return retorno;
}

int publicacion_listar(ePublicacion array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else
               // printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos

               printf("\n\n Posicion: %d "
                      "\n CUIT: %s "
                      "\n Nombre del Archivo :%s "
                      "\n Cantidad de dias de publicacion: %d "
                      "\nID: %d "
                      "\n ID Pantalla: %d",
                      posicion,
                      array[posicion].cuit,
                      array[posicion].nombreArchivo,
                      array[posicion].diasPublicacion,
                      array[posicion].idPublicacion,
                      array[posicion].idPantalla);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar POR CUIT
/** \brief Lista los elementos de un array POR CUIT
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/


int publicacion_listarPorCUIT(ePublicacion array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    char CUITbuscado[TEXT_SIZE];
    utn_getTexto("Ingrese el cuit a listar","Error",1,TEXT_SIZE,3,CUITbuscado);
    //utn_getCUIT("Ingrese su CUIT para lista las publicacion vigentes","Error",2,CUITbuscado);
    printf("%s",CUITbuscado);

    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else if(strcmp(array[posicion].cuit,CUITbuscado)==0)
                    {

               // printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos

               printf("\n\n Posicion: %d \n CUIT: %s \n Nombre del Archivo :%s \n Cantidad de dias de publicacion: %d \nID: %d \n ID Pantalla: %d",
                      posicion,array[posicion].cuit,array[posicion].nombreArchivo,array[posicion].diasPublicacion,array[posicion].idPublicacion,
                      array[posicion].idPantalla);
                     }
        }
        retorno=0;
    }
    return retorno;
}

int publicacion_calcularFacturacion(ePantalla arrayPantalla[], int sizePantalla, ePublicacion arrayPublicacion[], int sizePublicacion, char CUITbuscado[], int *contadorPucliaciones)
{

   int retorno=-1;
   int posicion=0;
   float total=0;
   //char CUITbuscado[TEXT_SIZE];
   int pruebaFucion;
   int posicionPantalla;
   //buscarCuit(CUITbuscado);
   int aux = 0;
        //printf("\n\nEntre en calcular facturacion y el cuit es: %s \n\n El contador es: %d",CUITbuscado,*contadorPucliaciones);
        //printf(CUITbuscado);

           if(arrayPublicacion!=NULL && sizePublicacion > 0)

                    {
                           for(posicion=0;posicion<sizePublicacion;posicion++)
                                {
                                    if(strcmp(CUITbuscado,arrayPublicacion[posicion].cuit)==0)
                                        {
                                            //printf("\nContador: %d",*contadorPucliaciones);
                                            //*contadorPucliaciones++;
                                            aux++;
                                            //printf("\ncontador de publicaciones: %d para el cuit: %s" ,aux,arrayPublicacion[posicion].cuit);
                                            pantalla_buscarInt(arrayPantalla,sizePantalla,arrayPublicacion[posicion].idPantalla,&posicionPantalla);
                                            total=arrayPublicacion[posicion].diasPublicacion*arrayPantalla[posicionPantalla].precio;
                                            printf("\nEl precio de la publicacion %d por la pantalla %s con direccion %s es de %.2f"
                                                   ,arrayPublicacion[posicion].idPublicacion,arrayPantalla[posicionPantalla].nombre
                                                   ,arrayPantalla[posicionPantalla].direccion,total);
                                        }
                                }

                    }
            *contadorPucliaciones = aux;
                    //printf("\n\n La cantidad de publiacaciones para el cuit es de: %d",*contadorPucliaciones);


    return 0;

}

int calcularTotalidadSalarios(Employee array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    float sumaSalarios=0;
    int contadorEmpleados=0;
    int contadorEmpleadosSuperanElPromedio=0;
    float promedioDeSalarios;
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;

            else
               contadorEmpleados++;
               sumaSalarios=sumaSalarios+array[posicion].salary;
               //printf("la suma de salarios es: %.2f",sumaSalarios);
        }

        promedioDeSalarios=sumaSalarios/contadorEmpleados;

        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;

            else if(array[posicion].salary>promedioDeSalarios)
                {
                    contadorEmpleadosSuperanElPromedio++;


                }

        }

        printf("La totalidad de los salarios es de %.2f, superan este valor %d empleados de un total de %d",sumaSalarios,contadorEmpleadosSuperanElPromedio,contadorEmpleados);

        retorno=0;
    }
    return retorno;
}

int informeCantidadContratacionesImporteApagar(ePantalla arrayPantalla[], int sizePantalla, ePublicacion arrayPublicacion[], int sizePublicacion)
{

int retorno=-1;
int posicion=0;
int posicion2=0;
float total=0;
int pruebaFucion;
int posicionPantalla;
int contador=0;
char auxCuit[TEXT_SIZE]="0";
int *contadorPublicacionesPorCuit=0;


            if(arrayPublicacion!=NULL && sizePublicacion > 0)

                    {
                           publicacion_ordenarPorString(arrayPublicacion,sizePublicacion);// prdeno por cuit

                    }


           if(arrayPublicacion!=NULL && sizePublicacion > 0)// validar el isempty

                    {

                           for(posicion=0;posicion<sizePublicacion;posicion++)
                                {

                                        if(strcmp(auxCuit,arrayPublicacion[posicion].cuit)!=0)
                                        {
                                            printf("\n\n\nPara el cuit: %s" ,arrayPublicacion[posicion].cuit);
                                            strcpy(auxCuit,arrayPublicacion[posicion].cuit);
                                            publicacion_calcularFacturacion(arrayPantalla,sizePantalla,arrayPublicacion,sizePublicacion,auxCuit,&contadorPublicacionesPorCuit);
                                            printf("\nLa cantidad de publicaciones es de: %d",contadorPublicacionesPorCuit);

                                        }

                                        contadorPublicacionesPorCuit=0;

                                }
                    }





return retorno;
}


int buscarCuit(char * pCuit){


    utn_getTexto("Ingrese el cuit a listar","Error",1,TEXT_SIZE,3,pCuit);

    return 0;
}
