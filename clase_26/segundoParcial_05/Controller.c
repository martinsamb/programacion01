#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controller_loadFromText(char* path, LinkedList* this)
{
    int retorno=0;
    FILE *pFile=NULL;
    if(path!=NULL && this!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(parser_fromText(pFile,this))
            {
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int controller_imprimirLlamadas(LinkedList* this)
{
    int retorno=0;
    void* elemento;
    int i;
    Llamada* llamada;
    int id;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucion[5];
    if(this!=NULL)
    {
        retorno=1;
        for(i=0;i<ll_len(this);i++)
        {
            elemento=ll_get(this,i);
            if(elemento!=NULL)
            {
                llamada = (Llamada*) elemento;
                if(getId(llamada,&id)&&
                   getFecha(llamada,fecha)&&
                   getNumeroCliente(llamada,&numeroCliente)&&
                   getIdProblema(llamada,&idProblema)&&
                   getSolucion(llamada,solucion))
                {
                    printf("%d %s %d %s ",id,fecha,numeroCliente,solucion);
                    switch(idProblema)
                    {
                        case 1:
                            printf("No enciende PC\n");
                            break;
                        case 2:
                            printf("No funciona mouse\n");
                            break;
                        case 3:
                            printf("No funciona teclado\n");
                            break;
                        case 4:
                            printf("No hay internet\n");
                            break;
                        case 5:
                            printf("No funciona telefono\n");
                            break;
                        default:
                            printf("NO TIENE UN TIPO CONOCIDO DE ERROR\n");
                            break;
                    }
                }

            }
        }
    }
    return retorno;
}

int controller_askProblema()
{
    char auxiliar[10];
    int auxInt;
    int option=-1;
    printf("Eliga el numero del problema que aparecera en el archivo\n");
    auxInt=utn_getInter("1-No enciende PC\n2-No funciona mouse\n3-No funciona teclado\n4-No hay internet\n5-No funciona telefono\n","ERROR\n",0,5,3,auxiliar);
    if(auxInt==0)
    {
        option=atoi(auxiliar);
    }
    return option;
}

int controller_writeText(char* path,LinkedList* this)
{
    int retorno=0;
    void* elemento;
    int i;
    Llamada* llamada;
    int id;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucion[5];
    FILE* pFile;
    if(path!=NULL && this!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            retorno=1;
            //fprintf(pFile,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");
            for(i=0;i<ll_len(this);i++)
            {
                elemento=ll_get(this,i);
                if(elemento!=NULL)
                {
                    llamada = (Llamada*) elemento;
                    if(getId(llamada,&id)&&
                       getFecha(llamada,fecha)&&
                       getNumeroCliente(llamada,&numeroCliente)&&
                       getIdProblema(llamada,&idProblema)&&
                       getSolucion(llamada,solucion))
                    {
                        fprintf(pFile,"%d,%s,%d,%d,%s\n",id,fecha,numeroCliente,idProblema,solucion);
                    }
                }
            }
        }
    }
    return retorno;
}


