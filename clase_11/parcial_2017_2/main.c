#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h" //cambiar por nombre entidad
#include "pantalla.h"
#include "informes.h"


#define QTY_PANTALLAS 3
#define QTY_CONTRATACIONES 3

int cargarDatos(Pantalla arrayPantalla[], Publicidad arrayPublicidad[],int *contadorIdPantalla,int *contadorIdPublicacion);

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
    cargarDatos(arrayPantallas, arrayPublicidad,&contadorIdPantalla,&contadorIdPublicidad);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de pantalla \n2) Modificar datos de pantalla \n3) Baja de pantalla \n4) Contratar una publicidad \n5) Modificar condiciones de publicacion \n6) Cancelar contratacion\n7) Consulta facturacion \n8) Listar contrataciones \n9) Listar pantallas \n10) Informar \n11) Salir\n",
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

            case 8://Listar contrataciones
                Informes_listarContrataciones(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS);
                break;

            case 9://Listar pantalla
                pantalla_listar(arrayPantallas,QTY_PANTALLAS);
                break;

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
//----------------------------------------------------------------------------

int cargarDatos(Pantalla arrayPantalla[], Publicidad arrayPublicidad[],int *contadorIdPantalla,int *contadorIdPublicacion)
{
    int i=0;
    //Pantalla
    arrayPantalla[i].isEmpty=0;
    arrayPantalla[i].idPantalla=*contadorIdPantalla;
    arrayPantalla[i].precio=1.0;
    strcpy(arrayPantalla[i].nombre,"SonyA");
    strcpy(arrayPantalla[i].direccion,"A1B");
    strcpy(arrayPantalla[i].tipo,"LCD");
    (*contadorIdPantalla)++;
    i++;

    arrayPantalla[i].isEmpty=0;
    arrayPantalla[i].idPantalla=*contadorIdPantalla;
    arrayPantalla[i].precio=2.0;
    strcpy(arrayPantalla[i].nombre,"SonyB");
    strcpy(arrayPantalla[i].direccion,"A2B");
    strcpy(arrayPantalla[i].tipo,"LD");
    (*contadorIdPantalla)++;
    i++;

    arrayPantalla[i].isEmpty=0;
    arrayPantalla[i].idPantalla=*contadorIdPantalla;
    arrayPantalla[i].precio=3.0;
    strcpy(arrayPantalla[i].nombre,"SonyC");
    strcpy(arrayPantalla[i].direccion,"A3B");
    strcpy(arrayPantalla[i].tipo,"LCD");
    (*contadorIdPantalla)++;
    i++;

    arrayPantalla[i].isEmpty=0;
    arrayPantalla[i].idPantalla=*contadorIdPantalla;
    arrayPantalla[i].precio=4.0;
    strcpy(arrayPantalla[i].nombre,"SAM");
    strcpy(arrayPantalla[i].direccion,"B1B");
    strcpy(arrayPantalla[i].tipo,"LD");

    (*contadorIdPantalla)++;
    i++;

    arrayPantalla[i].isEmpty=0;
    arrayPantalla[i].idPantalla=*contadorIdPantalla;
    arrayPantalla[i].precio=5.0;
    strcpy(arrayPantalla[i].nombre,"WH");
    (*contadorIdPantalla)++;
    i++;

    i=0;
 //------------------------------------------------------
    //publicidad
    arrayPublicidad[i].isEmpty=0;
    arrayPublicidad[i].idPublicidad=*contadorIdPublicacion;
    arrayPublicidad[i].idPantalla=*contadorIdPantalla;
    arrayPublicidad[i].dias=10;
    strcpy(arrayPublicidad[i].archivo,"archA");
    strcpy(arrayPublicidad[i].cuit,"20-234234234");
    (*contadorIdPublicacion)++;
    i++;

    arrayPublicidad[i].isEmpty=0;
    arrayPublicidad[i].idPublicidad=*contadorIdPublicacion;
    arrayPublicidad[i].idPantalla=*contadorIdPantalla;
    arrayPublicidad[i].dias=20;
    strcpy(arrayPublicidad[i].archivo,"archB");
    strcpy(arrayPublicidad[i].cuit,"21-234234234");
    (*contadorIdPublicacion)++;
    i++;

    arrayPublicidad[i].isEmpty=0;
    arrayPublicidad[i].idPublicidad=*contadorIdPublicacion;
    arrayPublicidad[i].idPantalla=*contadorIdPantalla;
    arrayPublicidad[i].dias=30;
    strcpy(arrayPublicidad[i].archivo,"archC");
    strcpy(arrayPublicidad[i].cuit,"22-234234234");
    (*contadorIdPublicacion)++;
    i++;

    arrayPublicidad[i].isEmpty=0;
    arrayPublicidad[i].idPublicidad=*contadorIdPublicacion;
    arrayPublicidad[i].idPantalla=*contadorIdPantalla;
    arrayPublicidad[i].dias=30;
    strcpy(arrayPublicidad[i].archivo,"archD");
    strcpy(arrayPublicidad[i].cuit,"23-234234234");
    (*contadorIdPublicacion)++;
    i++;

    arrayPublicidad[i].isEmpty=0;
    arrayPublicidad[i].idPublicidad=*contadorIdPublicacion;
    arrayPublicidad[i].idPantalla=*contadorIdPantalla;
    arrayPublicidad[i].dias=40;
    strcpy(arrayPublicidad[i].archivo,"archE");
    strcpy(arrayPublicidad[i].cuit,"24-234234234");
    (*contadorIdPublicacion)++;
    i++;

//-----------------------------------------------

    //pantalla_listar(arrayPantalla,QTY_PANTALLAS);
    //publicidad_listar(arrayPublicidad,QTY_CONTRATACIONES);

    return 0;
}
