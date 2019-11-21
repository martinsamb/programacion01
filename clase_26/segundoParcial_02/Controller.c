
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entrega.h"                          //Replace Entrega (tipo) y entrega (f)     campos: Cantidad + int1 // Importe + int2 // Tipo2 + nombre2
#include "utn.h"


/*
Modificar
    Add: mensajes y buffers por campo
    Edit: buffers por campo, mensajes, funciones set en switch
    List: buffers y mensaje
    SaveAsText: buffers y mensaje
*/

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerEntrega_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;

    FILE *pFile=NULL;

    if(path!=NULL && pArrayList!=NULL)
    {
        ll_clear(pArrayList);
        pFile=fopen(path,"r");    //direccion archivo, modo de arpetura

        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                retornoParser=parser_EntregaFromText(pFile,pArrayList);
                if(retornoParser==-2)
                    contadorError++;
                else if(retornoParser==1)
                    contadorCargados++;
            }
            fclose(pFile);
            printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);
            if(contadorCargados>0)
                retorno=0;
        }
    }

    return retorno;
}


/** \brief Alta de Entrega
 *
 * \param pArrayList LinkedList*
 * \param ultimoId int* Puntero al maximo ID actual de la lista
 * \return int -1 Error / 0 Alta exitosa
 *
 */
int controllerEntrega_addEntrega(LinkedList* pArrayList, int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];             //cambiar por cantidad de campos
    Entrega* pEntrega=NULL;

    if(pArrayList!=NULL)
    {
        utn_getTexto("\nTipo ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nCantidad","\nError",1,STR_SIZE,1,arrayBuffers[2]);           //cambiar
        utn_getTexto("\nImporte ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        pEntrega=entrega_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(pEntrega!=NULL)
        {
            ll_add(pArrayList,pEntrega);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
        else
            printf("\nError");
    }
    return retorno;
}

/** \brief Modificar datos de Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Modificacion exitosa
 *
 */
int controllerEntrega_editEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    int bufferCantidad;                        //cambiar
    float bufferImporte;                       //cambiar
    char bufferTipo[STR_SIZE];
    Entrega* pEntrega=NULL;

    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id)==0)
        {
            if(entrega_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    pEntrega=ll_get(pArrayList,indice);
                    entrega_getId(pEntrega,&bufferID);
                    entrega_getTipo(pEntrega,bufferTipo);
                    entrega_getCantidad(pEntrega,&bufferCantidad);
                    entrega_getImporte(pEntrega,&bufferImporte);
                    printf("\n ID: %d   Tipo: %s   Cantidad: %d   Importe: %f",bufferID,bufferTipo,bufferCantidad,bufferImporte);                       //cambiar

                    utn_getLetra("\nModificar: A Tipo B Cantidad C Importe S(salir)","\nError",1,&opcion);                      //cambiar
                    switch(opcion)
                    {
                        case 'A':
                            utn_getTexto("\nTipo: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            entrega_setTipo(pEntrega,bufferModificacion);
                            break;
                        case 'B':
                            utn_getTexto("\n: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            entrega_setCantidadStr(pEntrega,bufferModificacion);
                            break;
                        case 'C':
                            utn_getTexto("\n: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            entrega_setImporteStr(pEntrega,bufferModificacion);
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
    }
    return retorno;
}

/** \brief Baja de Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Baja exitosa
 *
 */
int controllerEntrega_removeEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id)==0)
        {
            if(entrega_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                ll_remove(pArrayList,indice);
                printf("\nBaja exitosa");
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Listar Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerEntrega_ListEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferCantidad;                       //cambiar
    float bufferImporte;
    char bufferTipo[STR_SIZE];
    int size=ll_len(pArrayList);
    Entrega* pEntrega;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            pEntrega=ll_get(pArrayList,i);
            entrega_getId(pEntrega,&bufferID);
            entrega_getTipo(pEntrega,bufferTipo);
            entrega_getCantidad(pEntrega,&bufferCantidad);                       //cambiar
            entrega_getImporte(pEntrega,&bufferImporte);

            printf("\n ID: %d   Tipo: %s   Cantidad: %d   Importe: %f",bufferID,bufferTipo,bufferCantidad,bufferImporte);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena Entrega por nombre (diferencia mayusculas y minusculas)
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerEntrega_sortEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList,entrega_cmpTipo,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int controllerEntrega_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Entrega* pEntrega=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferCantidad;                       //cambiar
    float bufferImporte;                       //cambiar
    char bufferTipo[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pEntrega=ll_get(pArrayList,i);
                entrega_getId(pEntrega,&bufferID);
                entrega_getTipo(pEntrega,bufferTipo);
                entrega_getCantidad(pEntrega,&bufferCantidad);                       //cambiar
                entrega_getImporte(pEntrega,&bufferImporte);                       //cambiar

                if(fprintf(pFile,"%d,%s,%d,%f\n",bufferID,bufferTipo,bufferCantidad,bufferImporte)>8)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

