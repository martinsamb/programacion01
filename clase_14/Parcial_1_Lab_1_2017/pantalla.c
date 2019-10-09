#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"

//***************************************************************
//Init
int Pantalla_Inicializar(Pantalla array[], int size)
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

//*****************************************
//Buscar
//Int
int Pantalla_buscarEmpty(Pantalla array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
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

int Pantalla_buscarID(Pantalla array[], int size, int valosBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].idPantalla==valosBuscado)
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
/*
int Tipo_buscarNombre(Empleado array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
*/
//*****************************************
//Alta
int Pantalla_alta(Pantalla array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Pantalla_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPantalla=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nDireccion: ","\nError",1,TEXT_SIZE,1,array[posicion].direccion);
            utn_getName("\nTipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);
            utn_getFloat("\nPrecio por dia: ","\nError",1,sizeof(float),0,1,1,&array[posicion].precio);
            printf("\nID: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f",array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].tipo,array[posicion].precio);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja
int Pantalla_baja(Pantalla array[], int sizeArray, int* id)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a borrar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Pantalla_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPantalla=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].direccion,"");
            strcpy(array[posicion].tipo,"");
            array[posicion].precio=0;

            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Modificar
int Pantalla_modificar(Pantalla array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Pantalla_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\nID: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f",array[posicion].idPantalla,array[posicion].nombre,array[posicion].direccion,array[posicion].tipo,array[posicion].precio);
                utn_getChar("\nModificar: N D T P S(salir)","\nError",1,sizeof(char),1,&opcion);
                switch(opcion)
                {
                    case 'N':
                        utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'D':
                        utn_getTexto("\nDireccion: ","\nError",1,TEXT_SIZE,1,array[posicion].direccion);
                        break;
                    case 'T':
                        utn_getName("\nTipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);
                        break;
                    case 'P':
                        utn_getFloat("\nPrecio por dia: ","\nError",1,sizeof(float),0,1,1,&array[posicion].precio);
                        break;
                    case 'S':
                        break;

                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/*
int Pantalla_ordenarporNombre(Pantalla array[],int size)
{
    int retorno=-1;
    int i, j;
    char buffer[30];
    int bufferId;
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(buffer,array[i].nombre);
            bufferId=array[i].idPantalla;
            bufferIsEmpty=array[i].isEmpty;
            j = i - 1;
            while ((j >= 0) && strcmp(buffer,array[j].nombre)<0)
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idPantalla=array[j].idPantalla;
                array[j + 1].isEmpty=array[j].isEmpty;
                j--;
            }
            strcpy(array[j + 1].nombre,buffer);
            array[j + 1].idPantalla=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
        }
        retorno=0;
    }
    return retorno;
}*/
//*****************************************
//Listar
int Pantalla_listar(Pantalla array[], int size)
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
                printf("\nPosicion: %d\nID: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f",i,array[i].idPantalla,array[i].nombre,array[i].direccion,array[i].tipo,array[i].precio);
        }
        retorno=0;
    }
    return retorno;
}
