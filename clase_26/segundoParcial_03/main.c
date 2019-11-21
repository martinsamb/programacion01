#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Entidad.h"
#include "Controller.h"


int main()
{
    int cantidadDeFotos = 0;
    int mayores = 0;
    int mayoresMayores = 0;
    int cantidadDeFotosPolaroid = 0;

    LinkedList* lista = ll_newLinkedList();
    if(lista != NULL)
    {
        if(controller_loadFromText("data.csv", lista))
        {
            printf("Archivo abierta\n");
            cantidadDeFotos = acumuladorDeFotos(lista);
            mayores = ll_count(lista, criterioMayor150);
            mayoresMayores = ll_count(lista, criterioMayor300);
            cantidadDeFotosPolaroid = ll_count(lista, criterioPolaroid);
            if(controller_saveAsText("informe.csv",cantidadDeFotos, mayores, mayoresMayores,cantidadDeFotosPolaroid))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("Ocurrio un error  en el guardado");
            }
        }
        else
        {
            printf("Ocurrio un error  en la apertura");
        }
    }
    return 0;
}


