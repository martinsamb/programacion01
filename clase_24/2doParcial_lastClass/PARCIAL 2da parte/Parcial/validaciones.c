/*
 * validaciones.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>

#include "validaciones.h"

static int esNumero(char* cadena);
static int getInt(int* pResultado);
int getNumInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int numeroAux;
    int retorno = -1;

    if(maximo>=minimo && reintentos>=0 && pNumero!=NULL && mensaje!=NULL && error!=NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            //__fpurge(stdin);
            fflush(stdin);
            if(getInt(&numeroAux)==0 && numeroAux >= minimo && numeroAux <= maximo)
            {
                *pNumero = numeroAux;
                retorno = 0;
                break;
            }
            else
                printf(error);
        }while(reintentos > 0);
    }
    return retorno;
}

static int esNumero(char* cadena)
{
    int retorno=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            retorno = 0;
    }
    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    scanf("%s", buffer);
    if(esNumero(buffer)==0)
    {
        *pResultado = atoi(buffer);
        retorno=0;
    }
    else
        retorno=-1;
    return retorno;
}

static int getFloat(float* pResultado);
int getNumFloat(float* pNumero, int reintentos, float minimo,
                float maximo, char* mensaje, char* error)
{
    int retorno = -1;
    float floatAux;

    if(maximo >= minimo && reintentos >= 0 && pNumero != NULL && mensaje != NULL && error != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            //__fpurge(stdin);
            fflush(stdin);
            if(getFloat(&floatAux) == 0 && floatAux >= minimo && floatAux <= maximo)
            {
                *pNumero = floatAux;
                retorno = 0;
                break;
            }
            else
                printf("%s", error);
        }while(reintentos > 0);
    }
    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno;

    if(scanf("%f", pResultado) == 1)
        retorno=0;
    else
        retorno=-1;
    return retorno;
}

static int getStringOnlyLetters(char* string, int limite);
static int getStr(char* string, int limite);
int getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char stringAux[100];

    if(pNombre != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getStringOnlyLetters(stringAux, limite) == 0)
            {
                strncpy(pNombre, stringAux, limite);
                retorno = 0;
                break;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

static int getStringOnlyLetters(char* string, int limite)
{
    int retorno = -1;
    char stringAux[limite];

    if(string!=NULL && limite>0)
    {
        if(getStr(stringAux, limite) == 0 && esNumero(stringAux) == -1)
        {
            strncpy(string, stringAux, limite);
            retorno = 0;
        }
    }
    return retorno;
}

static int getStr(char* string, int limite)
{
    int retorno = -1;
    char stringAux[100];

    if(string!=NULL && limite > 0)
    {
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringAux, sizeof(stringAux), stdin);
        if(stringAux[(strlen(stringAux))-1] == '\n')
            stringAux[(strlen(stringAux))-1] = '\0';
        if(strlen(stringAux) <= limite)
        {
            sprintf(string, "%s", stringAux);
            retorno = 0;
        }
    }
    return retorno;
}

int getStringAlfaNum(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    //int i;
    char stringAux[100];

    if(pNombre != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getStr(stringAux, limite) == 0)
            {
                /*for(i = 0; stringAux[i]; i++)
                    stringAux[i] = toupper(stringAux[i]);*/

                strncpy(pNombre, stringAux, limite);
                retorno = 0;
                break;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

static int esNumeroCuit(char* cadena);
int getCuit(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char stringAux[100];

    if(pNombre != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getStr(stringAux, limite) == 0 && esNumeroCuit(stringAux)==0)
            {
                strncpy(pNombre, stringAux, limite);
                retorno = 0;
                break;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}


static int esNumeroCuit(char* cadena)
{
    int retorno=-1;
    int i=0;
    int contadorGuion=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]>='0' && cadena[i]<='9')
            {
                i++;
            }
            else if(cadena[i]=='-')
            {
                contadorGuion++;
                i++;
            }
            else
                break;
        }
        if(cadena[i]=='\0' && contadorGuion==2 && cadena[2]=='-' && cadena[11]=='-')
            retorno = 0;
    }
    return retorno;
}






