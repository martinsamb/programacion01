#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h" //cambiar por nombre entidad
#include "pantalla.h"
#include "informes.h"


#define QTY_PANTALLAS 3
#define QTY_CONTRATACIONES 3

int main()
{
    int opcion;
    int contadorIdPantalla=0;
    int contadorIdPublicidad=0;
    int bufferIDPantalla=0;
    char bufferCuit[TEXT_SIZE];

    Pantalla arrayPantallas[QTY_PANTALLAS];
    pantalla_Inicializar(arrayPantallas,QTY_PANTALLAS);

    Publicidad arrayPublicidad[QTY_CONTRATACIONES];
    publicidad_Inicializar(arrayPublicidad,QTY_CONTRATACIONES);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de pantalla \n2) Modificar datos de pantalla \n3) Baja de pantalla \n4) Contratar una publicidad \n5) Modificar condiciones de publicacion \n6) Cancelar contratacion\n7) Consulta facturacion \n8) Listar contrataciones \n9) Listar pantallas \10) Informar \n11) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                pantalla_alta(arrayPantallas,QTY_PANTALLAS,&contadorIdPantalla);                   //cambiar
                break;

            case 2: //Modificar
                pantalla_modificar(arrayPantallas,QTY_PANTALLAS);                   //cambiar
                break;

            case 3: //Baja
                pantalla_baja(arrayPantallas,QTY_PANTALLAS,&bufferIDPantalla);
                publicidad_bajaPantalla(arrayPublicidad,QTY_CONTRATACIONES,bufferIDPantalla);
                bufferIDPantalla=0;
                break;

            case 4://Listar
                pantalla_listar(arrayPantallas,QTY_PANTALLAS);
                publicidad_alta(arrayPublicidad,QTY_CONTRATACIONES,&contadorIdPublicidad);
                break;

            case 5://Modificar
                utn_getCUIT("\nCUIT: ","\nError",1,bufferCuit);
                Informes_listarPantallasPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                publicidad_modificar(arrayPublicidad,QTY_CONTRATACIONES);
                strcpy(bufferCuit,"");                   //cambiar
                break;

            case 6://Cancelar contratacion
                utn_getCUIT("\nCUIT: ","\nError",1,bufferCuit);
                Informes_listarPantallasPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                publicidad_bajaPantallaCuit(arrayPublicidad,QTY_CONTRATACIONES,bufferCuit);
                strcpy(bufferCuit,"");                   //cambiar
                break;

            case 7://Consultas facturacion
                utn_getCUIT("\nCUIT: ","\nError",1,bufferCuit);
                Informes_listarPantallasPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                publicidad_modificar(arrayPublicidad,QTY_CONTRATACIONES);
                strcpy(bufferCuit,"");                   //cambiar
                break;

            case 8://LIstar contrataciones
                Informes_listarContrataciones(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS);
                break;

            case 9://Listar pantalla
                pantalla_listar(arrayPantallas,QTY_PANTALLAS);

            case 10://Listar pantallas
                Informes_listarCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS);
                break;

            case 11://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
