#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h"
#include "pantalla.h"
#include "informes.h"

#define QTY_PANTALLAS 3
#define QTY_CONTRATACIONES 3

int main()
{
    int opcion;
    int contadorIdPantalla=0;   //si lo declaro antes de opcion se cambia a 1 despues de inicializar arrayInt, por que????????
    int contadorIdPublicidad=0;
    int bufferIDPantalla=0;
    char bufferCuit[TEXT_SIZE];

    Pantalla arrayPantallas[QTY_PANTALLAS];
    Pantalla_Inicializar(arrayPantallas,QTY_PANTALLAS);

    Publicidad arrayPublicidad[QTY_CONTRATACIONES];
    Publicidad_Inicializar(arrayPublicidad,QTY_CONTRATACIONES);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de pantalla \n2) Modificar datos de pantalla \n3) Baja de pantalla \n4) Contratar una publicidad \n5) Modificar condiciones de publicacion \n6) Cancelar contratacion \n7) Consulta facturacion \n8) Listar contrataciones \n9) Listar pantallas \n10) Informar \n11) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta de pantalla      ok
                //Se solicitan al usuario los datos de la pantalla, para que el sistema pueda​ ​funcionar​ ​se​ ​deberá​ ​generar​ ​un​ ​ID​ ​único​ ​para​ ​cada​ ​pantalla.

                Pantalla_alta(arrayPantallas,QTY_PANTALLAS,&contadorIdPantalla);
                break;

            case 2: //Modificar datos de pantalla       ok
                //Se ingresa el ID de la pantalla,permitiendo modificar sus datos.

                Pantalla_modificar(arrayPantallas,QTY_PANTALLAS);
                break;

            case 3: //Baja de pantalla
                //Se ingresa el ID de la pantalla,se eliminará la pantalla junto con todas las​ ​contrataciones​ ​de​ ​publicidad​ ​para​ ​esta​ ​pantalla.

                Pantalla_baja(arrayPantallas,QTY_PANTALLAS,&bufferIDPantalla);
                Publicidad_bajaPantalla(arrayPublicidad,QTY_CONTRATACIONES,bufferIDPantalla);
                bufferIDPantalla=0;
                break;

            case 4: //Contratar una publicidad      ok
                /*Se listaran todas las pantallas y se le pedirá al usuario que elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos asociados a la publicidad:
                cuit del cliente, cantidad de días que dura la publicación y nombre​ ​del​ ​archivo​ ​de​ ​video​ ​(p.ej.​ ​Video1.avi). */

                Pantalla_listar(arrayPantallas,QTY_PANTALLAS);
                Publicidad_alta(arrayPublicidad,QTY_CONTRATACIONES,&contadorIdPublicidad);
                break;

            case 5://Modificar condiciones de publicacion
                /*Se pedirá que se ingrese el cuit del cliente y se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos.
                Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días contratados​ ​para​ ​la​ ​misma.*/
    //Solo modificar dias?
                utn_getCUIT("\nCUIT: ","\nError",11,14,1,bufferCuit);
                Informes_listarPantallasPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                Publicidad_modificar(arrayPublicidad,QTY_CONTRATACIONES); // fata modificar
                strcpy(bufferCuit,"");
                break;

            case 6://Cancelar contratacion
                /* ​Se pedirá que se ingrese el cuit del cliente y se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos.
                Luego ingresar​ ​el​ ​ID​ ​de​ ​la​ ​pantalla​ ​de​ ​la​ ​cual​ ​se​ ​quiere​ ​cancelar​ ​la​ ​contratación.*/
                utn_getCUIT("\nCUIT: ","\nError",11,14,1,bufferCuit);
                Informes_listarPantallasPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                Publicidad_bajaPantallaCuit(arrayPublicidad,QTY_CONTRATACIONES,bufferCuit);
                strcpy(bufferCuit,"");
                break;

            case 7://Consulta facturacion
                //Se deberá ingresar el cuit del cliente y se deberá listar el importe a​ ​pagar​ ​por​ ​cada​ ​contratación.
                utn_getCUIT("\nCUIT: ","\nError",11,14,1,bufferCuit);
                Informes_listarFacturacionPorCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS,bufferCuit);
                Publicidad_bajaPantallaCuit(arrayPublicidad,QTY_CONTRATACIONES,bufferCuit);
                strcpy(bufferCuit,"");
                break;

            case 8://Listar contrataciones
                // deberán listar las contrataciones indicando nombre de la pantalla,​ ​nombre​ ​de​ ​video,​ ​cantidad​ ​de​ ​días​ ​y​ ​cuit​ ​de​ ​cliente.
                Informes_listarContrataciones(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS);
                break;

            case 9://Listar​ ​pantallas     ok
                /*Se​ ​deberán​ ​listar​ ​las​ ​pantallas​ ​existentes​ ​indicando​ ​todos​ ​sus​ ​campos.*/
                Pantalla_listar(arrayPantallas,QTY_PANTALLAS);
                break;

            case 10://Informar
                /*1. Lista​ ​de​ ​cada​ ​cliente​ ​con​ ​cantidad​ ​de​ ​contrataciones​ ​e​ ​importe​ ​a​ ​pagar​ ​por​ ​cada​ ​una.
                2. Cliente​ ​con​ ​importe​ ​más​ ​alto​ ​a​ ​facturar​ ​(si​ ​hay​ ​más​ ​de​ ​uno​ ​indicar​ ​el​ ​primero)*/

                Informes_listarCuit(arrayPublicidad,arrayPantallas,QTY_CONTRATACIONES,QTY_PANTALLAS);

                break;

            case 11://Salir
                break;
        }
    }
    while(opcion!=11);
    return 0;
}
/*

Estructuras/entidades:
Pantalla
    int idPantalla
    int isEmpty
    char nombre[]
    char direccion[]
    char tipo []
    float precio

Publicidad
    int idPublicidad
    int isEmpty
    char cuit[]
    int dias
    char archivo[]
    int idPantalla


Entidad extra si se contratan varias pantallas por publicidad (no en este caso)
    int idPantalla
    int idPublicidad


Siempre:
    Alta, baja, modificacion
    init array
    Buscar vacio
    print array
    buscar id

*/
/*
Nota​ ​0​ ​:​ ​El​ ​sistema​ ​soportará​ ​una​ ​capacidad​ ​máxima​ ​de​ ​100​ ​pantallas​ ​y​ ​1000​ ​contrataciones
 Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones​ ​(Alta,​ ​Baja,​ ​Modificar,​ ​etc.).​ ​
         Los​ ​informes​ ​deberán​ ​estar​ ​en​ ​una​ ​biblioteca​ ​aparte.
 Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones​ ​y​ ​respetar​ ​las​ ​reglas​ ​de​ ​estilo​ ​de​ ​la​ ​cátedra.
*/
