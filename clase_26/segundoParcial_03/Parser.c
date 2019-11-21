#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entidad.h"
#include "Controller.h"

int acumuladorDeFotos(LinkedList* lista)
{
    Entidad* pEntidad = NULL;
    int acum;
    int retorno = 0;
    if(lista != NULL)
    {
        for(int i = 0; i < ll_len(lista);i++)
        {
            pEntidad = ll_get(lista,i);
            entidad_getCantidad(pEntidad,&acum);
            retorno = retorno + acum;
        }
    }
    return retorno;
}

int criterioMayor150(void* pEntidad)
{
    int retorno = 0;
    float precio;
    if(pEntidad != NULL)
    {
        entidad_getPrecio(pEntidad, &precio);
        if(precio > 150)
        {
            retorno =1;
        }
    }
    return retorno;
}

int criterioMayor300(void* pEntidad)
{
    int retorno = 0;
    float precio;
    if(pEntidad != NULL)
    {
        entidad_getPrecio(pEntidad, &precio);
        if(precio > 300)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int criterioPolaroid(void* pEntidad)
{
    int retorno = 0;
    char foto[30];
    if (pEntidad != NULL)
    {
        entidad_getFoto(pEntidad, foto);
        if (strncmp(foto, "POLAROID_11x9", 13) == 0 || strncmp(foto, "POLAROID_10x10", 14) == 0)
        {
            retorno = 1;        }
    }
    return retorno;}
