#include <stdio.h>
#include <stdlib.h>
#include "Entregas.h"
#include "utn.h"
#include <string.h>

/** \brief Crea posicion de memoria para un nueva entrega
 *
 * \param this Entrega*
 * \param id int
 * \return Entrega*
 *
 */
Entrega* entrega_new(void)
{
    return (Entrega*)malloc(sizeof(Entrega));
}

/** \brief Crea un nueva entrega  con posicion de memoria y contenido basado en strings
 *
 * \param is char*
 * \param tipo char*
 * \param cantidad char*
 * \param importe char*
 * \return Entrega*
 *
 */
Entrega* entrega_newParametros(char* id, char* tipo, char* cantidad, char* importe)
{
    Entrega* retorno = NULL;
    Entrega* pAuxEntrega;
    if(id != NULL && tipo != NULL && cantidad != NULL && importe != NULL)
    {
        pAuxEntrega = entrega_new();
        if(pAuxEntrega != NULL)
        {
            if(!entrega_setIdAsString(pAuxEntrega,id) && !entrega_setTipo(pAuxEntrega,tipo) && !entrega_setCantidadAsString(pAuxEntrega,cantidad)
               && !entrega_setImporteAsString(pAuxEntrega, importe))
            {
                retorno = pAuxEntrega;
            }
            else
            {
                entrega_delete(pAuxEntrega);
            }
        }
    }
    return retorno;
}

/** \brief Elimina una entrega
 *
 * \param this Entrega*
 * \return int
 *
 */
int entrega_delete(Entrega* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define un Id de una entrega
 *
 * \param this Entrega*
 * \param id int
 * \return int
 *
 */
int entrega_setId(Entrega* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id=id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el Id de una entrega
 *
 * \param this Entrega*
 * \param int*resultado
 * \return int
 *
 */
int entrega_getId(Entrega* this, int*resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el Id de una entrega como string
 *
 * \param this Entrega*
 * \param char*id
 * \return int
 *
 */
int entrega_setIdAsString(Entrega* this,char*id)
{
    int retorno =-1;
    if(this != NULL && id>= 0)
    {
        if(isValidNumber(id))
        {
            retorno = entrega_setId(this,atoi(id));
        }
    }
    return retorno;
}

/** \brief Obtiene el Id de una entrega como string
 *
 * \param this Entrega*
 * \param resultado char*
 * \return int
 *
 */
int entrega_getIdAsString(Entrega* this, char* resultado)
{
    int retorno =-1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        entrega_getId(this,&bufferId);
        sprintf(resultado,"%d", bufferId);
        retorno = 0;
    }
    return retorno;
}


/** \brief Define el tipo de entrega
 *
 * \param this Entrega*
 * \param tipo char*
 * \return int
 *
 */
int entrega_setTipo(Entrega* this, char* tipo)
{
    int retorno = -1;
    if(this!= NULL && isValidName(tipo))
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

/** \brief  Obtiene el tipo de una entrega
 *
 * \param this Entrega*
 * \param resultado char*
 * \return int
 *
 */
int entrega_getTipo(Entrega* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}


/** \brief Define la cantidad de entregas
 *
 * \param this Entrega*
 * \param cantidad int
 * \return int
 *
 */
int entrega_setCantidad(Entrega* this, int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad>= 0)
    {
            this->cantidad = cantidad;
            retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene la cantidad de entregas
 *
 * \param this Entrega*
 * \param resultado int*
 * \return int
 *
 */
int entrega_getCantidad(Entrega* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL )
    {
        *resultado = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define la cantidad de entregas como string
 *
 * \param this Entrega*
 * \param cantidad char*
 * \return int
 *
 */
int entrega_setCantidadAsString(Entrega* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0 )
    {
        if(isValidNumber(cantidad))
        {
            retorno = entrega_setCantidad(this,atoi(cantidad));
        }
    }
    return retorno;
}

/** \brief Obtiene la cantidad de entregas como string
 *
 * \param resultado Entrega* thismchar*
 * \return int
 *
 */
int entrega_getCantidadAsString(Entrega* this, char* resultado)
{
    int retorno = -1;
    int bufferCantidad;

    if(this != NULL && resultado != NULL)
    {
        bufferCantidad = this->cantidad;
        sprintf(resultado,"%d",bufferCantidad);
        retorno = 0;
    }
    return retorno;
}


/** \brief Define el importe de la entrega
 *
 * \param this Entrega*
 * \param importe float
 * \return int
 *
 */
int entrega_setImporte(Entrega* this, float importe)
{
    int retorno =-1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}


/** \brief Obtiene el importe de la entrega
 *
 * \param this Entrega*
 * \param resultado float*
 * \return int
 *
 */
int entrega_getImporte(Entrega* this, float* resultado)
{
    int retorno =-1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el importe como string
 *
 * \param this Entrega*
 * \param importe char*
 * \return int
 *
 */
int entrega_setImporteAsString(Entrega* this, char* importe)
{
    int retorno =-1;
    if(this != NULL && importe>= 0)
    {
        if(isValidFloatNumber(importe))
        {
            retorno = entrega_setImporte(this,atof(importe));
        }
    }
    return retorno;
}

/** \brief Obtiene el importe como string
 *
 * \param this Entrega*
 * \param resultado char*
 * \return int
 *
 */
int entrega_getImporteAsString(Entrega* this, char* resultado)
{
    int retorno =-1;
    int bufferImporte;
    if(this != NULL && resultado != NULL)
    {
        bufferImporte = this->importe;
        sprintf(resultado,"%d",bufferImporte);
        retorno = 0;
    }
    return retorno;
}


int entrega_filtrarGold(void* this)
{
    int retorno =-1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "GOLD");
    if(!comparison)
        retorno =1;

    return retorno;
}

int entrega_filtrarPlus(void* this)
{
    int retorno = -1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "PLUS");
    if(!comparison)
        retorno = 1;

    return retorno;
}

int entrega_filtrarRegular(void* this)
{
    int retorno =-1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "REGULAR");
    if(!comparison)
        retorno = 1;

    return retorno;

}
