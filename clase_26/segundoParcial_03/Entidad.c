#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entidad.h"
#include "LinkedList.h"
#include "utn.h"

#define FALSE 0
#define TRUE 1


Entidad* entidad_newEntidad()
{
    return(Entidad*)malloc(sizeof(Entidad));
}
Entidad* entidad_newEntidadParametros(char* id, char* fecha, char* foto, char* cantidad,
                                      char* precio, char* cuit)
{
    Entidad* pEntidad = entidad_newEntidad();
    Entidad* retorno = NULL;
    if(id != NULL && fecha != NULL && foto != NULL && cantidad != NULL && precio != NULL && cuit != NULL)
    {
        if(entidad_setIdStr(pEntidad,id)&& entidad_setFecha(pEntidad,fecha)&& entidad_setFoto(pEntidad,foto)&&
           entidad_setCantidadStr(pEntidad,cantidad) && entidad_setPrecioStr(pEntidad, precio) && entidad_setCuit(pEntidad, cuit))
        {
            retorno = pEntidad;
        }
        else
        {
            entidad_delete(pEntidad);
        }
    }
    return retorno;
}
int entidad_delete(Entidad* this)
{
    int retorno =-FALSE;
    if(this != NULL)
    {
        free((void*)this);
        retorno = TRUE;
    }
    return retorno;
}

int entidad_setId(Entidad* this,int id)
{
    int retorno = FALSE;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = TRUE;
    }
    return retorno;
}

int entidad_getId(Entidad* this,int* id)
{
    int retorno = FALSE;
    if(this != NULL  && id != NULL)
    {
        *id = this->id;
        retorno = TRUE;
    }
    return retorno;
}

int entidad_setIdStr(Entidad* this, char* id)
{
    int retorno = FALSE;
    if(this != NULL && id != NULL)
    {
        if(isValidId(id))
        {
            if(entidad_setId(this, atoi(id)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}

int entidad_setFecha(Entidad* this,char* fecha)
{
    int retorno = FALSE;
    if(this != NULL && fecha != NULL)
    {
        if(isValidFechaArchivo(fecha))
        {
            strncpy(this->fecha,fecha,sizeof(this->fecha));
            retorno = TRUE;
        }
    }
    return retorno;
}

int entidad_getFecha(Entidad* this,char* fecha)
{
    int retorno = FALSE;
    if(this != NULL && fecha != NULL)
    {
        if(isValidFechaArchivo(fecha))
        {
            strncpy(fecha,this->fecha,sizeof(this->fecha));
            retorno = TRUE;
        }
    }
    return retorno;
}


int entidad_setFoto(Entidad* this,char* foto)
{
    int retorno = FALSE;
    if(this != NULL && foto != NULL)
    {
        strncpy(this->foto,foto, sizeof(this->foto));
        retorno = TRUE;
    }
    return retorno;
}

int entidad_getFoto(Entidad* this,char* foto)
{
    int retorno = FALSE;
    if(this != NULL && foto != NULL)
    {
        strncpy(foto,this->foto,sizeof(this->foto));
        retorno = TRUE;
    }
    return retorno;
}

int entidad_setCantidad(Entidad* this,int cantidad)
{
    int retorno = FALSE;
    if(this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = TRUE;
    }
    return retorno;
}

int entidad_getCantidad(Entidad* this,int* cantidad)
{
    int retorno = FALSE;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = TRUE;
    }
    return retorno;
}

int entidad_setCantidadStr(Entidad* this, char* cantidad)
{
    int retorno = FALSE;
    if(this != NULL && cantidad != NULL)
    {
        if(isValidId(cantidad))
        {
            if(entidad_setCantidad(this, atoi(cantidad)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}

int entidad_setPrecio(Entidad* this,float precio)
{
    int retorno = FALSE;
    int cantidad;
    if(this != NULL && precio> 0 )
    {
        if(entidad_getCantidad(this, &cantidad))
        {
            precio = precio * cantidad;
            this->precio = precio;
            retorno = TRUE;
        }
    }
    return retorno;
}

int entidad_getPrecio(Entidad* this,float* precio)
{
    int retorno = FALSE;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = TRUE;
    }
    return retorno;
}

int entidad_setPrecioStr(Entidad* this, char* precio)
{
    int retorno = FALSE;
    if(this != NULL && precio != NULL)
    {
        if(isValidFLoatStr(precio))
        {
            if(entidad_setPrecio(this, atof(precio)))
            {
                retorno =TRUE;
            }
        }
    }
    return retorno;
}

int entidad_setCuit(Entidad* this,char* cuit)
{
    int retorno = FALSE;
    if(this != NULL && cuit != NULL)
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno = TRUE;
    }
    return retorno;
}

int entidad_getCuit(Entidad* this,char* cuit)
{
    int retorno = FALSE;
    if(this != NULL && cuit != NULL)
    {
        strncpy(cuit,this->cuit, sizeof(this->cuit));
        retorno = TRUE;
    }
    return retorno;
}
