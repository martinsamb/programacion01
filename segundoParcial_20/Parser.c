#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "computer.h"

int parser_parseComputers(FILE* fileName, LinkedList* listaComputers)
{
	int ret = 0;
	char auxId[4096];
	char auxDescripcion[4096];
	char auxPrecio[4096];
	char auxIdTipo[4096];
	char auxOferta[4096];
	Computer* pComputer;

		if(fileName != NULL && listaComputers != NULL)
        {
			fscanf(fileName, "[^\n]\n");//Lee datos formateados desde fichero
			fscanf(fileName, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxPrecio,auxIdTipo);
			//lee archivo cadena de caracteres, reglas descripta, pasa a la funcion como parametro
			while(!feof(fileName))
            {
				fscanf(fileName, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxPrecio,auxIdTipo);//desvuelve la cantidad de datos leidos
				strcpy(auxOferta, "");
				pComputer = computer_newParametros(auxId, auxDescripcion,auxPrecio,auxIdTipo,auxOferta);

				if(pComputer != NULL)
                {
					if(ll_add(listaComputers, pComputer) == 0)
					{
						ret++;
					}
				}
				else
                {
					printf("NULL");
				}
			}
		}
    return ret;
}

