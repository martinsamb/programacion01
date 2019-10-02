#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "asociado.h"  //cambiar por nombre entidad
#include "llamada.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdAsociado=0;
    int contadorIdLlamada = 0;                  //cambiar

    Asociado arrayAsociado[QTY_TIPO];                   //cambiar
    asociado_Inicializar(arrayAsociado,QTY_TIPO);

    Llamada arrayLlamada[QTY_TIPO];                   //cambiar
    llamada_Inicializar(arrayLlamada,QTY_TIPO);                 //cambiar

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Asociado \n2) Modificar datos Asociado \n3) Baja Asociado \n4) Nueva Llamada \n5) Asignar Ambulancia \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                asociado_alta(arrayAsociado,QTY_TIPO,&contadorIdAsociado);                   //cambiar
                break;

            case 2: //Modificar
                asociado_modificar(arrayAsociado,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                asociado_baja(arrayAsociado,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                llamada_alta(arrayLlamada,QTY_TIPO,&contadorIdLlamada);                   //cambiar
                break;

            case 5://Ordenar
                llamada_modificar(arrayLlamada,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
