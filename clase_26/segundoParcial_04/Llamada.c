#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"

Llamada* newLlamada()
{
    return (Llamada*)malloc(sizeof(Llamada));
}

int deleteLlamada(Llamada* this)
{
    int retorno =0;
    if(this != NULL)
    {
        free(this);
        retorno = 1;
    }
    return retorno;
}

int getId(Llamada* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int setId(Llamada* this,int id)
{
    int retorno = 0;
    if(this != NULL && id>0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int getFecha(Llamada* this,char* fecha)
{
    int retorno = 0;
    if(this != NULL && fecha != NULL)
    {
        strcpy(fecha,this->fecha);
        retorno = 1;
    }
    return retorno;
}

int setFecha(Llamada* this,char* fecha)
{
    int retorno = 0;
    if(this != NULL && fecha != NULL)
    {
        strcpy(this->fecha,fecha);
        retorno = 1;
    }
    return retorno;
}

int getNumeroCliente(Llamada* this,int* numeroCliente)
{
    int retorno = 0;
    if(this != NULL && numeroCliente != NULL)
    {
        *numeroCliente = this->numeroCliente;
        retorno = 1;
    }
    return retorno;
}

int setNumeroCliente(Llamada* this,int numeroCliente)
{
    int retorno = 0;
    if(this != NULL && numeroCliente != NULL)
    {
        this->numeroCliente = numeroCliente;
        retorno = 1;
    }
    return retorno;
}

int getIdProblema(Llamada* this,int* idProblema)
{
    int retorno = 0;
    if(this != NULL && idProblema != NULL)
    {
        *idProblema = this->idProblema;
        retorno=1;
    }
    return retorno;
}

int setIdProblema(Llamada* this,int idProblema)
{
    int retorno = 0;
    if(this != NULL && idProblema>0)
    {
        this->idProblema = idProblema;
        retorno = 1;
    }
    return retorno;
}

int getSolucion(Llamada* this,char* solucion)
{
    int retorno = 0;
    if(this != NULL && solucion != NULL)
    {
        strcpy(solucion,this->solucion);
        retorno = 1;
    }
    return retorno;
}

int setSolucion(Llamada* this,char* solucion)
{
    int retorno = 0;
    if(this != NULL && solucion != NULL)
    {
        strcpy(this->solucion, solucion);
        retorno = 1;
    }
    return retorno;
}

int problema1(void* elemento)
{
    int retorno = 0;
    int problema;
    Llamada* llamada = (Llamada*)elemento;
    if(llamada != NULL)
    {
        getIdProblema(llamada,&problema);
        if(problema == 1)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int problema2(void* elemento)
{
    int retorno = 0;
    int problema;
    Llamada* llamada = (Llamada*)elemento;
    if(llamada != NULL)
    {
        getIdProblema(llamada, &problema);
        if(problema == 2)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int problema3(void* elemento)
{
    int retorno = 0;
    int problema;
    Llamada* llamada = (Llamada*)elemento;
    if(llamada != NULL)
    {
        getIdProblema(llamada, &problema);
        if(problema == 3)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int problema4(void* elemento)
{
    int retorno = 0;
    int problema;
    Llamada* llamada = (Llamada*)elemento;
    if(llamada != NULL)
    {
        getIdProblema(llamada, &problema);
        if(problema == 4)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int problema5(void* elemento)
{
    int retorno = 0;
    int problema;
    Llamada* llamada = (Llamada*)elemento;
    if(llamada != NULL)
    {
        getIdProblema(llamada, &problema);
        if(problema == 5)
        {
            retorno = 1;
        }
    }
    return retorno;
}
