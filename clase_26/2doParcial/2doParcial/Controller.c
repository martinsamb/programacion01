#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorro.h"
#include "Parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo indicado(modo texto)
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* this)
{
    int retorno = 0;
    FILE* pFile = NULL;
    if(path != NULL && this != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if(parser_fromText(pFile,this))
            {
                retorno = 1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}
int controller_imprimirCachorros(LinkedList* this)
{
    int retorno = 0;
    void* elemento;
    int i;
    Cachorro* cachorro;
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[5];
    char genero[5];

    if(this != NULL)
    {
        retorno =1;
        for(i=0;i<ll_len(this);i++)
        {
            cachorro = ll_get(this,i);
            if(elemento != NULL)
            {
                cachorro = (Cachorro*)elemento;
                if(getId(cachorro, &id)&&
                   getNombre(cachorro, nombre)&&
                   getDias(cachorro,&dias)&&
                   getRaza(cachorro, raza) &&
                   getReservado(cachorro, reservado) &&
                   getGenero(cachorro, genero))
                {
                    printf("%d %s %d %s %s %s",id,nombre,dias,raza,reservado,genero);
                }
            }
        }
    }
    return retorno;
}

int controller_writeText(char* path,LinkedList* this)
{
    int retorno = 0;
    void* elemento;
    int i;
    Cachorro* cachorro;
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[5];
    char genero[5];;
    FILE* pFile;

    if(path != NULL && this != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            retorno = 1;
            for(i=0;i<ll_len(this); i++)
            {
                elemento = ll_get(this,i);
                if(elemento != NULL)
                {
                    cachorro = (Cachorro*)elemento;
                    if(getId(cachorro, &id)&&
                       getNombre(cachorro, nombre)&&
                       getDias(cachorro,&dias)&&
                       getRaza(cachorro, raza) &&
                       getReservado(cachorro, reservado) &&
                       getGenero(cachorro, genero))
                    {
                        fprintf(pFile,"%d %s %d %s %s %s",id,nombre,dias,raza,reservado,genero);
                    }
                }
            }
        }
    }
    return retorno;
}
