#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"
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
int controller_imprimirLlamadas(LinkedList* this)
{
    int retorno = 0;
    void* elemento;
    int i;
    Llamada* llamada;
    int id;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucion[5];
    if(this != NULL)
    {
        retorno =1;
        for(i=0;i<ll_len(this);i++)
        {
            elemento = ll_get(this,i);
            if(elemento != NULL)
            {
                llamada = (Llamada*)elemento;
                if(getId(llamada, &id)&&
                   getFecha(llamada, fecha)&&
                   getNumeroCliente(llamada,&numeroCliente)&&
                   getIdProblema(llamada, &idProblema) &&
                   getSolucion(llamada, solucion))
                {
                    printf("%d %s %d %s",id,fecha,numeroCliente,solucion);
                    switch(idProblema)
                    {
                        case 1:
                            printf("No enciende PC\n");
                            break;

                        case 2:
                            printf("No funciona mouse\n");
                            break;

                        case 3:
                            printf("No funciona el teclado\n");
                            break;

                        case 4:
                            printf("No funciona el internet\n");
                            break;

                        case 5:
                            printf("No funciona telefono\n");
                            break;

                        default:
                            printf("No tiene un tipo conocido de error\n");
                            break;
                    }
                }
            }
        }
    }
    return retorno;
}

int controller_numeroProblema()
{
    char auxiliar[10];
    int auxInt;
    int option = -1;
    printf("Eliga el problema que aparece en el archivo\n");
    auxInt = utn_getInter("1-No enciende PC\n2-No funciona mouse\n3-No funciona teclado\n4-No hay internet\n5-No funciona telefono\n","ERROR\n",0,5,3,auxiliar);
    if(auxInt == 0)
    {
        option = atoi(auxiliar);
    }
    return option;
}

int controller_writeText(char* path,LinkedList* this)
{
    int retorno = 0;
    void* elemento;
    int i;
    Llamada* llamada;
    int id;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucion[5];
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
                    llamada = (Llamada*)elemento;
                    if(getId(llamada, &id)&&
                       getFecha(llamada, fecha)&&
                       getNumeroCliente(llamada,&numeroCliente)&&
                       getIdProblema(llamada, &idProblema)&&
                       getSolucion(llamada, solucion))
                    {
                        fprintf(pFile,"%d, %s, %d, %d, %s\n",id, fecha, numeroCliente, idProblema, solucion);
                    }
                }
            }
        }
    }
    return retorno;
}
