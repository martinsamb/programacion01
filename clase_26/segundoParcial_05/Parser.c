
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Llamada.h"
#include "Parser.h"
int parser_fromText(FILE* pFile, LinkedList* this)
{
    int retorno=0;
    char auxId[20];
    char auxFecha[15];
    char auxNumeroCliente[20];
    char auxIdProblema[20];
    char auxSolucion[4];

    Llamada auxLlamada;
    Llamada* llamada=NULL;
    int flag=0;
    if(pFile!=NULL&&this!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxFecha,auxNumeroCliente,auxIdProblema,auxSolucion);
            if(flag==0)
            {
                flag=1;
                continue;
            }
            //printf("%4s %15s %15s %15s %15s\n",auxId,auxFecha,auxNumeroCliente,auxIdProblema,auxSolucion);

            llamada=newLlamada();
            if(llamada!=NULL)
            {
                if(isValidInter(auxId)&&isValidFecha(auxFecha)&&isValidInter(auxNumeroCliente)&&isValidInter(auxIdProblema)&&isValidName(auxSolucion))
                {
                    auxLlamada.id=atoi(auxId);
                    strcpy(auxLlamada.fecha,auxFecha);
                    auxLlamada.numeroCliente=atoi(auxNumeroCliente);
                    auxLlamada.idProblema=atoi(auxIdProblema);
                    strcpy(auxLlamada.solucion,auxSolucion);

                    if(setId(llamada,auxLlamada.id)&&
                       setFecha(llamada,auxLlamada.fecha)&&
                       setNumeroCliente(llamada,auxLlamada.numeroCliente)&&
                       setIdProblema(llamada,auxLlamada.idProblema)&&
                       setSolucion(llamada,auxLlamada.solucion))
                    {
                        ll_add(this,llamada);
                    }
                    else
                    {
                        deleteLlamada(llamada);
                    }

                    retorno=1;
                }
            }

        }
    }
    return retorno;
}

int parser_writeInfo(char* fileName,int totalEntregas,int tipoG,int tipoR,int tipoP,int totalBultos,float promedioBultos,float promedioSolucion)
{
    int retorno=0;
    FILE* pFile=NULL;
    if(fileName!=NULL && totalEntregas>0 && totalEntregas>0 && tipoG>0 && tipoR>0 && tipoP>0 && totalBultos>0 && promedioBultos>0 && promedioSolucion)
    {
        pFile=fopen(fileName,"w");
        if(pFile!=NULL)
        {
            retorno=1;
            fprintf(pFile,"********************\nInforme de ventas\n********************\n");
            fprintf(pFile,"- IdProblema total de entregas: %d\n",totalEntregas);
            fprintf(pFile,"- IdProblema de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n",tipoG,tipoR,tipoP);
            fprintf(pFile,"- IdProblema total de bultos entregados: %d\n",totalBultos);
            fprintf(pFile,"- Promedio de bultos por entrega: %.2f\n",promedioBultos);
            fprintf(pFile,"- Solucion promedio por entrega: %.2f\n",promedioSolucion);
            fprintf(pFile,"********************\n");
        }
        fclose(pFile);
    }
    return retorno;
}


