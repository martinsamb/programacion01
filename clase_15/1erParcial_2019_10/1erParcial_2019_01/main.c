#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Alquileres.h"
#include "Clientes.h"
#include "Juegos.h"


#define QTY_ALQUILER 100
#define QTY_CLIENTE 100
#define QTY_JUEGO 1000

int cargarDatos(Alquiler arrayAlquiler[], Cliente arrayCliente[], Juego arrayJuego[], int *contadorIdAlquiler, int *contadorIdCliente, int *contadorIdJuego);

int main()
{
    int opcion;
    int opcionI;

    int contadorIdAlquiler=1;
    int flagAlquiler=0;
    Alquiler arrayAlquiler[QTY_ALQUILER];
    alquiler_Inicializar(arrayAlquiler,QTY_ALQUILER);

    int contadorIdCliente=1;
    int flagCliente=0;
    Cliente arrayCliente[QTY_CLIENTE];
    cliente_Inicializar(arrayCliente,QTY_CLIENTE);

    int contadorIdJuego=1;
    int flagJuego=0;
    Juego arrayJuego[QTY_JUEGO];
    juego_Inicializar(arrayJuego,QTY_JUEGO);

    cargarDatos(arrayAlquiler, arrayCliente,arrayJuego, &contadorIdAlquiler, &contadorIdCliente, &contadorIdJuego);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta Cliente \n2) Modificar Cliente \n3) Baja Cliente \n4) Listar Cliente \n5) Listar Juegos \n6) Alta Alquileres \n7) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                cliente_alta(arrayCliente,QTY_CLIENTE,&contadorIdCliente);                   //cambiar
                break;

            case 2: //Modificar
                cliente_modificar(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 3: //Baja
                cliente_baja(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 4://Listar
                cliente_listar(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 5://Listar Juego
                juego_listar(arrayJuego,QTY_JUEGO);                   //cambiar
                break;

            case 6://Alta Alquiler
                alquiler_alta(arrayAlquiler,QTY_ALQUILER,&contadorIdAlquiler);                   //cambiar
                break;

            case 7://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=7);
    return 0;
}

//----------------------------------------------------------------------------
int cargarDatos(Alquiler arrayAlquiler[], Cliente arrayCliente[], Juego arrayJuego[], int *contadorIdAlquiler, int *contadorIdCliente, int *contadorIdJuego)
{
    int i=0;
    //}Alquiler
    arrayAlquiler[i].isEmpty=0;
    arrayAlquiler[i].idUnico=*contadorIdAlquiler;
    arrayAlquiler[i].idCliente=1;
    arrayAlquiler[i].idJuego=1;
    arrayAlquiler[i].Fecha=11/11/11;
    (*contadorIdAlquiler)++;
    i++;

    arrayAlquiler[i].isEmpty=0;
    arrayAlquiler[i].idUnico=*contadorIdAlquiler;
    arrayAlquiler[i].idCliente=2;
    arrayAlquiler[i].idJuego=2;
    arrayAlquiler[i].Fecha=11/11/12;
    (*contadorIdAlquiler)++;
    i++;

    arrayAlquiler[i].isEmpty=0;
    arrayAlquiler[i].idUnico=*contadorIdAlquiler;
    arrayAlquiler[i].idCliente=3;
    arrayAlquiler[i].idJuego=3;
    arrayAlquiler[i].Fecha=11/11/13;
    (*contadorIdAlquiler)++;
    i++;

    arrayAlquiler[i].isEmpty=0;
    arrayAlquiler[i].idUnico=*contadorIdAlquiler;
    arrayAlquiler[i].idCliente=4;
    arrayAlquiler[i].idJuego=4;
    arrayAlquiler[i].Fecha=11/11/14;
    (*contadorIdAlquiler)++;
    i++;

    arrayAlquiler[i].isEmpty=0;
    arrayAlquiler[i].idUnico=*contadorIdAlquiler;
    arrayAlquiler[i].idCliente=5;
    arrayAlquiler[i].idJuego=5;
    arrayAlquiler[i].Fecha=11/11/15;
    (*contadorIdAlquiler)++;
    i++;

     //------------------------------------------------------

    i=0;
    //Cliente
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    strcpy(arrayCliente[i].Apellido,"Sakamoto");
    strcpy(arrayCliente[i].Nombre,"Ryuiuchi");
    strcpy(arrayCliente[i].Sexo,"");
    strcpy(arrayCliente[i].Domicilio,"Osaka 2109");
    strcpy(arrayCliente[i].Telefono,"15234234");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    strcpy(arrayCliente[i].Apellido,"Wonder");
    strcpy(arrayCliente[i].Nombre,"Steve");
    strcpy(arrayCliente[i].Sexo,"");
    strcpy(arrayCliente[i].Domicilio,"NewYorr 2109");
    strcpy(arrayCliente[i].Telefono,"15345345");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    strcpy(arrayCliente[i].Apellido,"Bjork");
    strcpy(arrayCliente[i].Nombre,"Celeste");
    strcpy(arrayCliente[i].Sexo,"");
    strcpy(arrayCliente[i].Domicilio,"Larrea 2109");
    strcpy(arrayCliente[i].Telefono,"15456456");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    strcpy(arrayCliente[i].Apellido,"Monti");
    strcpy(arrayCliente[i].Nombre,"Luna");
    strcpy(arrayCliente[i].Sexo,"");
    strcpy(arrayCliente[i].Domicilio,"Salta 2109");
    strcpy(arrayCliente[i].Telefono,"15567567");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    strcpy(arrayCliente[i].Apellido,"Spinetta");
    strcpy(arrayCliente[i].Nombre,"Luis");
    strcpy(arrayCliente[i].Sexo,"");
    strcpy(arrayCliente[i].Domicilio,"Gorriti 2109");
    strcpy(arrayCliente[i].Telefono,"15123123");
    (*contadorIdCliente)++;
    i++;


//-----------------------------------------------
    i=0;
    //Juego
    arrayJuego[i].isEmpty=0;
    arrayJuego[i].idUnico=*contadorIdJuego;
    arrayJuego[i].Importe=95.5;
    strcpy(arrayJuego[i].Descripcion,"Ajedrez");
    (*contadorIdJuego)++;
    i++;

    arrayJuego[i].isEmpty=0;
    arrayJuego[i].idUnico=*contadorIdJuego;
    arrayJuego[i].Importe=96.6;
    strcpy(arrayJuego[i].Descripcion,"Naipe");
    (*contadorIdJuego)++;
    i++;

    arrayJuego[i].isEmpty=0;
    arrayJuego[i].idUnico=*contadorIdJuego;
    arrayJuego[i].Importe=97.7;
    strcpy(arrayJuego[i].Descripcion,"Damas");
    (*contadorIdJuego)++;
    i++;

    arrayJuego[i].isEmpty=0;
    arrayJuego[i].idUnico=*contadorIdJuego;
    arrayJuego[i].Importe=98.8;
    strcpy(arrayJuego[i].Descripcion,"Metegol");
    (*contadorIdJuego)++;
    i++;

    arrayJuego[i].isEmpty=0;
    arrayJuego[i].idUnico=*contadorIdJuego;
    arrayJuego[i].Importe=99.9;
    strcpy(arrayJuego[i].Descripcion,"Pool");
    (*contadorIdJuego)++;
    i++;


    return 0;
}
