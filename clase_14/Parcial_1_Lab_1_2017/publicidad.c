#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h"

//***************************************************************
//Init
int Publicidad_Inicializar(Publicidad array[], int size)
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
int Publicidad_buscarEmpty(Publicidad array[], int size, int* posicion)
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

int Publicidad_buscarID(Publicidad array[], int size, int valosBuscado, int* posicion)
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
int Publicidad_buscarCuit(Publicidad array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (strcmp(array[i].cuit,valorBuscado)==0)
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
int Publicidad_alta(Publicidad array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Publicidad_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPublicidad=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nID pantalla: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idPantalla);
            utn_getCUIT("\nCUIT: ","\nError",1,TEXT_SIZE,1,array[posicion].cuit);
            utn_getUnsignedInt("\nDias a contratar: ","\nError",1,sizeof(int),1,1,1,&array[posicion].dias);
            utn_getTexto("\nNombre Archivo: ","\nError",1,TEXT_SIZE,1,array[posicion].archivo);
            printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre Archivo: %s\nID pantalla: %d",array[posicion].idPublicidad,array[posicion].cuit,array[posicion].dias,array[posicion].archivo,array[posicion].idPantalla);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja
int Publicidad_baja(Publicidad array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Publicidad_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nEste ID de pantalla no se encuentra en ninguna contratacion");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPublicidad=0;
            strcpy(array[posicion].cuit,"");
            array[posicion].dias=0;
            strcpy(array[posicion].archivo,"");
            array[posicion].idPantalla=0;
            retorno=0;
        }
    }
    return retorno;
}

int Publicidad_bajaPantalla(Publicidad array[], int sizeArray, int valorIDPantalla) //cuando se da de baja la pantalla tmb se da de baja todas las publicidades
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPantalla==valorIDPantalla)
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
    return retorno;
}

int Publicidad_bajaPantallaCuit(Publicidad array[], int sizeArray, char* cuitBuscado) //Se dan de baja las pantallas contratadas por un cuit
{
    int retorno=-1;
    int posicion;
    int i;
    int valorIDPantalla;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&valorIDPantalla);
        if(Publicidad_buscarID(array,sizeArray,valorIDPantalla,&posicion)==-1)
        {
            printf("\nEste ID de pantalla no se encuentra en ninguna contratacion");
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
int Publicidad_modificar(Publicidad array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID pantalla contratada a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Publicidad_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre Archivo: %s\nID pantalla: %d",array[posicion].idPublicidad,array[posicion].cuit,array[posicion].dias,array[posicion].archivo,array[posicion].idPantalla);
                utn_getChar("\nModificar: C D A P S(salir)","\nError",1,sizeof(char),1,&opcion);
                switch(opcion)
                {
                    case 'C':
                        utn_getCUIT("\nCUIT: ","\nError",1,TEXT_SIZE,1,array[posicion].cuit);
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nDias a contratar: ","\nError",1,sizeof(int),1,1,1,&array[posicion].dias);
                        break;
                    case 'A':
                        utn_getTexto("\nNombre Archivo: ","\nError",1,TEXT_SIZE,1,array[posicion].archivo);
                        break;
                    case 'P':
                        utn_getUnsignedInt("\nID pantalla: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idPantalla);
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
int Publicidad_listar(Publicidad array[], int size)
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
                printf("\nID publicidad: %d\nCUIT: %s\nDias a contratar: %d\nNombre Archivo: %s\nID pantalla: %d",array[i].idPublicidad,array[i].cuit,array[i].dias,array[i].archivo,array[i].idPantalla);
        }
        retorno=0;
    }
    return retorno;
}



