#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

Cachorro* newCachorro()
{
    return (Cachorro*)malloc(sizeof(Cachorro));
}

int deleteCachorro(Cachorro* this)
{
    int retorno =0;
    if(this != NULL)
    {
        free(this);
        retorno = 1;
    }
    return retorno;
}
//------------------------------------------------
int getId(Cachorro* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int setId(Cachorro* this,int id)
{
    int retorno = 0;
    if(this != NULL && id>0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}
//--------------------------------------
/*
int getNombre(Cachorro* this,char* nombre);
int setNombre(Cachorro* this,char* nombre);
*/
int getNombre(Cachorro* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int setNombre(Cachorro* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

//------------------------------------
/*
int getDias(Cachorro* this,int* dias);
int setDias(Cachorro* this,int dias);
*/
int setDias(Cachorro* this,int dias)
{
    int retorno = 0;
    if(this != NULL && dias>0)
    {
        this->dias = dias;
        retorno = 1;
    }
    return retorno;
}

int getDias(Cachorro* this,int* dias)
{
    int retorno = 0;
    if(this != NULL && dias != NULL)
    {
        *dias = this->dias;
        retorno = 1;
    }
    return retorno;
}


//--------------------------------------------------
/*
int getRaza(Cachorro* this,char* raza);
int setRaza(Cachorro* this,char raza);
*/
int getRaza(Cachorro* this,char* raza)
{
    int retorno = 0;
    if(this != NULL && raza != NULL)
    {
        strcpy(raza,this->raza);
        retorno = 1;
    }
    return retorno;
}

int setRaza(Cachorro* this,char* raza)
{
    int retorno = 0;
    if(this != NULL && raza != NULL)
    {
        strcpy(this->raza, raza);
        retorno = 1;
    }
    return retorno;
}
//________________________________________
/*
int getReservado(Cachorro* this,char* reservado);
int setReservado(Cachorro* this,char* reservado);
*/

int getReservado(Cachorro* this,char* reservado)
{
    int retorno = 0;
    if(this != NULL && reservado != NULL)
    {
        strcpy(reservado,this->reservado);
        retorno = 1;
    }
    return retorno;
}

int setReservado(Cachorro* this,char* reservado)
{
    int retorno = 0;
    if(this != NULL && reservado != NULL)
    {
        strcpy(this->reservado, reservado);
        retorno = 1;
    }
    return retorno;
}

//-------------------------------------------------
/*
int getGenero(Cachorro* this,char* genero);
int setGenero(Cachorro* this,char* genero);
*/

int getGenero(Cachorro* this,char* genero)
{
    int retorno = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero,this->genero);
        retorno = 1;
    }
    return retorno;
}

int setGenero(Cachorro* this,char* genero)
{
    int retorno = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        retorno = 1;
    }
    return retorno;
}

/*
void cahorro_menores45(void* pElement)
{
    Cachorro* element = pElement;
    int dias;

    if(getDias(element, &dias)==0 && dias!=0)
    {
        int dias;
        if(dias>0 && dias<45)
        {
            dias++;
        }

        setDias(element, dias);
    }
}

void cahorro_filtrarMachos(void* pElement)
{
    Cachorro* element = pElement;
    int genero;

    if(getGenero(element, genero)==0 && genero!=0)
    {
        int genero;
        if (strcmp(genero, "M") == 0)
        {
            genero++;
        }

        setGenero(element, genero);
    }
}

void cahorro_listaCallejeros(void* pElement)
{
    Cachorro* element = pElement;
    int raza;

    if(getRaza(element, raza)==0 && raza!=0)
    {
        int raza;
        if (strcmp(raza, "Callejero") == 0)
        {
            raza++;
        }
        setRaza(element, raza);
    }
}
*/
