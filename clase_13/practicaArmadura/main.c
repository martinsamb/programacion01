#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h" //cambiar por nombre entidad
#define SIZE_CHAR 30
#define SIZE_PANTALLAS 3
#define SIZE_PUBLICACIONES 4
#define QTY_TIPO 3
#define CANT_EMPLE 5




int main()
{
    int opcion;
    int contadorIdfantasma=3;                   //cambiar
    int contadorIdPantalla=0;
    int contadorIdPublicacion=4;
    int contadorPublicaciones=0;
    char cuitBuscado[TEXT_SIZE];

    ePantalla Pantallas[SIZE_PANTALLAS]={   {"LCD","Abasto","Corrientes 4500",123,0,1},
                                            {"LED","River","Alcorta 4500",500,0,2},
                                            {"LED","Boca","Patricios 123",500,0,3}};

    //pantalla_Inicializar(Pantallas,SIZE_PANTALLAS);


    Employee eEmployee[SIZE_PANTALLAS];

    ePublicacion Publicacion[SIZE_PUBLICACIONES]={  {0,1,"20424340226",100,"MC123",1},
                                                    {0,3,"20543453457",150,"BK456",2},
                                                    {0,2,"20424340226",200,"FG456",3},
                                                    {0,3,"20302423447",110,"utn.avi",4}};
    //publicacion_Inicializar(Publicacion,SIZE_PUBLICACIONES);

    //Fantasma arrayFantasma[QTY_TIPO];                   //cambiar
    //fantasma_Inicializar(arrayFantasma,QTY_TIPO);                   //cambiar

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Pantalla \n2) Modificar Pantalla \n3) Baja Pantalla \n4) Listar pantallas \n5) Alta Contratacion "
                           "\n6) Listar Publicaciones \n7) listar Por Cuit\n8) Modificar publicaciones por cuit"
                           "\n9) Baja Publicaciones \n10) Consultar Facturacion por cuit \n15) Salir",                   //solo modificar el texto
                      "\nError",1,sizeof(int),1,6,1,&opcion);


        switch(opcion)
        {
            case 1: //Alta

                //pantalla_alta(Pantallas,SIZE_PANTALLAS,&contadorIdPantalla);
                //fantasma_alta(arrayFantasma,QTY_TIPO,&contadorIdfantasma);                   //cambiar
                break;

            case 2: //Modificar

                pantalla_modificar(Pantallas,SIZE_PANTALLAS);
                //fantasma_modificar(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja

                pantalla_baja(Pantallas,SIZE_PANTALLAS);
                //fantasma_baja(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 4://LISTAR PANTALLAS
                pantalla_listar(Pantallas,SIZE_PANTALLAS);

                //fantasma_listar(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 5://MODIFICAR PUBLICACION ----- ALTA CONTRATACION

                publicacion_alta(Publicacion,SIZE_PUBLICACIONES,&contadorIdPublicacion);
                //publicacion_listarPorCUIT(Publicacion,SIZE_PUBLICACIONES);

                //pantalla_ordenarPorString(Pantallas,SIZE_PANTALLAS);
                //fantasma_ordenarPorString(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 6://MODIFICAR CONTRATACION
                publicacion_listar(Publicacion,SIZE_PUBLICACIONES);
                //publicacion_listarPorCUIT(Publicacion,SIZE_PUBLICACIONES);
                break;
            case 7://LISTAR POR CUIT
                publicacion_listarPorCUIT(Publicacion,SIZE_PUBLICACIONES);
                break;

            case 8://MODIFICAR CONDICIONES DE PUBLICACION

                publicacion_listarPorCUIT(Publicacion,SIZE_PUBLICACIONES);
                publicacion_modificar(Publicacion,SIZE_PUBLICACIONES);
            case 9://BAJA CONTRATACION
                publicacion_baja(Publicacion,SIZE_PUBLICACIONES);
            case 10://CONSULTAR FACTURACION

                buscarCuit(cuitBuscado);
                publicacion_calcularFacturacion(Pantallas,SIZE_PANTALLAS,Publicacion,SIZE_PUBLICACIONES,cuitBuscado,&contadorPublicaciones);
                break;
            case 11:
                informeCantidadContratacionesImporteApagar(Pantallas,SIZE_PANTALLAS,Publicacion,SIZE_PUBLICACIONES);
                break;


            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=15);
    return 0;
}



