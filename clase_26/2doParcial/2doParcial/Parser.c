#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Cachorro.h"
#include "Parser.h"


int parser_fromText(FILE* pFile, LinkedList* this)
{
    int retorno = 0;
    char auxId[20];
    char auxNombre[30];
    char auxDias[20];
    char auxRaza[20];
    char auxReservado[4];
    char auxGenero[4];

    Cachorro auxCachorro;
    Cachorro* cachorro = NULL;
    int flag= 0;
    if(pFile != NULL && this != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId, auxNombre,auxDias,auxRaza,auxReservado,auxGenero);
            if(flag == 0)
            {
                flag=1;
                continue;
            }
            cachorro = newCachorro();
            if(cachorro != NULL)
            {
                if(isValidInter(auxId)&&
                   isValidName(auxNombre)&&
                   isValidInter(auxDias)&&
                   isValidName(auxRaza)&&
                   isValidName(auxReservado)&&
                   isValidName(auxGenero))
                {
                    auxCachorro.id = atoi(auxId);
                    strcpy(auxCachorro.nombre,auxNombre);
                    auxCachorro.dias = atoi(auxDias);
                    strcpy(auxCachorro.raza,auxRaza);
                    strcpy(auxCachorro.reservado,auxReservado);
                    strcpy(auxCachorro.genero,auxGenero);
                    //set valida campo
                    //get lee campo por medio de get

                    if(setId(cachorro,auxCachorro.id)&&
                       setNombre(cachorro,auxCachorro.nombre)&&
                       setDias(cachorro,auxCachorro.dias)&&
                       setRaza(cachorro,auxCachorro.raza)&&
                       setReservado(cachorro,auxCachorro.reservado)&&
                       setGenero(cachorro,auxCachorro.genero))
                    {
                        ll_add(this,cachorro); // agrega un elemento al ll
                    }
                    else
                    {
                        deleteCachorro(cachorro);
                    }
                    retorno =1;
                }
            }
        }
    }
    return retorno;
}

int parser_writeInfo(char* fileName,int totalEntregas,int tipoG,int tipoR,int tipoP,int totalBultos,float promedioBultos,float promedioSolucion)
{
    int retorno = 0;
    FILE* pFile = NULL;
    if(fileName != NULL && totalEntregas>0 && tipoG>0 && tipoR>0 && tipoP>0 && totalBultos>0 && promedioBultos>0 && promedioSolucion)
    {
        pFile = fopen(fileName,"w");
        if(pFile != NULL)
        {
            retorno = 1;
            fprintf(pFile,"-----------Informe de ventas-------------------\n");
            fprintf(pFile,"-IdProblema total de entregas: %d\n",totalEntregas);
            fprintf(pFile,"-IdProblema de entregas por tipo: %d(GOLD) - %d(REGULAR) - %d(PLUS))\n",tipoG,tipoR,tipoP);
            fprintf(pFile,"-IdProblema total de bultos entregados: %d\n",totalBultos);
            fprintf(pFile,"-Promedio de bultos por entrega: %.2f\n",promedioBultos);
            fprintf(pFile,"-Solucion promedio por entrega: %.2f\n",promedioSolucion);
            fprintf(pFile,"------------------------------------------------\n");
        }
        fclose(pFile);
    }
    return retorno;
}
