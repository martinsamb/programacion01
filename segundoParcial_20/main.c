#include <stdio.h>
#include <stdlib.h>
#include "computer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"


int main()
{
	int option = 0;

    LinkedList* listaComputers;
    LinkedList* listaComputadorasFiltradas;

    listaComputers = ll_newLinkedList();

    do
    {
    	printf("\
        	    	  \nMenu:\
        	    	  \n1. Cargar Archivo\
        	    	  \n2. Ordenar lista\
        	    	  \n\n3. Imprimir Lista\
        	    	  \n4. Filtrar Desktops\
                      \n5. Filtrar Ofertas\
                      \n6. Generar Archivo\
        	    	  \n7. Salir\
        	    	  \n");

    	utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,5,1,&option);

    	switch(option)
        {
    			case 1:
                    controller_loadFromText(listaComputers);//cargo archivo
                    break;
                case 2:
                	controller_sortComputers(listaComputers);//ordeno archivo
                    break;
                case 3:
                	controller_ListComputers(listaComputers);//imprimo listado

                	break;
                case 4:
                    controller_mapComputers(listaComputers);//asino ofertas a cada tipo dePC
                    break;
                case 5:

                	listaComputadorasFiltradas = ll_filter(listaComputers,filtrar);//filtro equipos desktop
                	printf("Calculando\n");
                	break;
                case 6:

                	if(listaComputadorasFiltradas != NULL)//imprimo lista de equipos
                    {
                		if(controller_saveAsText("filtrados.csv",listaComputadorasFiltradas) == 0)//salvo en un arhivo
                        {
                            printf("\nArchivo generado correctamente\n");
                        }
                        else
                        {
                			printf("Error generando archivo\n");
                		}
                	}
                	break;

                case 7:
                    break;
                default:
                	printf("Opcion invalida");
            }
        }while(option != 7);

        return 0;
}
