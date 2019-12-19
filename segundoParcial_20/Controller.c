#include <stdio.h>
#include <stdlib.h>
#include "computer.h"
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"


/** \brief Carga los datos de los computers desde el archivo datos_Fin.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pListaComputers)
{
	int ret = -1;
	char path[32];
	printf("\nIngrese nombre del archivo: ");
	scanf("%s",path);
	//utn_getChar("Introduzca el nombre del archivo.","Error",0,127,2, path);
	FILE* pFile;
	pFile = fopen(path, "r");
	if(parser_parseComputers(pFile, pListaComputers))
    {
		ret = 0;
		printf("Lista cargada exitosamente");
	}
	else
    {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintComputers(LinkedList* pListaComputers, int index)
{
	int ret = -1;
	Computer* auxComputer;
	int auxId;
	char auxDescripcion[4096];
	int auxPrecio;
	int auxIdTipo;
	char auxOferta[4096];

	if(pListaComputers != NULL)
    {
		printf("\nid              Descripcion                                Precio           Tipo         Oferta \n\n");

		auxComputer = ll_get(pListaComputers, index);
		computer_getId(auxComputer, &auxId);
		computer_getDescripcion(auxComputer, auxDescripcion);
		computer_getPrecio(auxComputer, &auxPrecio);
		computer_getIdTipo(auxComputer, &auxIdTipo);
		computer_getOferta(auxComputer, auxOferta);

		printf("%d  --  %s  --  %d  --  ", auxId, auxDescripcion, auxPrecio);

		if(auxIdTipo == 1)
        {
			printf("DESKTOP  --  ");
		}
		else if(auxIdTipo == 2)
        {
			printf("LAPTOP  --  ");
		}
			printf("%s\n",auxOferta);

		ret = 0;
	}
	return ret;
}

/** \brief Listar Perros
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_ListComputers(LinkedList* pListaComputers)
{
	int ret = -1;
	int i, len;
	if(pListaComputers != NULL)
    {
		if(ll_len(pListaComputers) > 0)
		{
			len = ll_len(pListaComputers);
			for(i = 0; i < len; i++) {
            controller_PrintComputers(pListaComputers, i);
        }
			ret = 0;
		}
        else
        {
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}

/** \brief Guarda los datos de los Perros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_saveComputersAsText(FILE* pFile , LinkedList* pListaComputers)
{
    int ret = 0;
    Computer* auxComputer;
    int auxId;
    char auxDescripcion[4096];
    int auxPrecio;
    int auxIdTipo;
	char auxOferta[4096];
    int i, len;

    if(pListaComputers != NULL && pFile != NULL)
    {
    	fprintf(pFile,"id,descripcion,precio,idTipo,oferta\n");//Guarda texto formateado en fichero
                //El identificador del fichero, la cadena de formato y los datos a guardar
    	len = ll_len(pListaComputers);

    	for(i = 0; i < len; i++)
        {
    		auxComputer = (Computer*)ll_get(pListaComputers, i);
    		computer_getId(auxComputer, &auxId);
    		computer_getDescripcion(auxComputer, auxDescripcion);
    		computer_getPrecio(auxComputer, &auxPrecio);
    		computer_getIdTipo(auxComputer, &auxIdTipo);
    		computer_getOferta(auxComputer, auxOferta);

    		fprintf(pFile,"%d,%s,%d,%d,%s\n", auxId, auxDescripcion, auxPrecio, auxIdTipo, auxOferta);//Guarda texto formateado en fichero
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}

int controller_saveAsText(char* fileName,LinkedList* listaComputers)
{
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaComputers != NULL)
        {
	        pArchivo = fopen(fileName,"w");
	        if(pArchivo != NULL && controller_saveComputersAsText(pArchivo,listaComputers))
	        {
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        }
            else
            {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortComputers(LinkedList* pListaComputers)
{
    int ret = -1;
    if(pListaComputers != NULL)
    {
    	if(ll_len(pListaComputers) > 0)
    	{
    		ll_sort(pListaComputers,computer_compareIdTipo,0);
    	}
    		ret = 0;
    		printf("Operacion completada");
    }
    else
    {
        printf("No hay registros cargados");
    }
    return ret;
}

int controller_mapComputers(LinkedList* pListaComputers)
{
    int ret = -1;
    if(pListaComputers != NULL)
    {
    	if(ll_len(pListaComputers) > 0)
    	{
    		ll_map(pListaComputers,computer_mapIdTipo);
    	}
    		ret = 0;
    		printf("Operacion completada");
    }
    else
    {
        printf("No hay registros cargados");
    }
    return ret;
}

