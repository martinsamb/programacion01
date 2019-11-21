#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "clases.h"

int main()
{
    char seguir = 's';
    char confirma;

    eAlmuerzo almuerzos[] =
    {
        {100, 1234, 5, {21, 04, 2009}},
        {101, 5555, 3, {22, 04, 2001}},
        {102, 8944, 4, {15, 03, 2018}},
        {103, 2222, 2, {21, 04, 2017}},
        {104, 1234, 3, {21, 02, 2016}},
        {105, 2211, 2, {01, 10, 2014}},
        {106, 1234, 1, {11, 12, 2015}},
        {107, 7654, 1, {03, 06, 2018}},
        {108, 1234, 3, {28, 01, 2009}},
        {109, 2222, 2, {04, 03, 2014}},
        {110, 9040, 5, {01, 04, 2012}}
    };

    eComida comidas[] =
    {
        {1, "Pescado"},
        {2, "Pasta"},
        {3, "Milanesas"},
        {4, "Pizza"},
        {5, "Ensalada"},
    };

    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };
    //eEmpleado lista[TAM];


    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2,1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2,1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {8944, "Sonia", 'f', 39000, {12,3,2012},3,1},
        {2231, "Miguel", 'm', 29700, {28,7,2009}, 2,1},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2,1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 0},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,0},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,0}
    };
    //inicializarEmpleados(lista, TAM);

    //hardcodeEmpleados(lista);       //  <-----------VER ESTE TEMA

    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            ordenarPorNombreYLegajo(lista, TAM, 0);
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
         case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

         case 8:
            //printf("\nListar empleados\n\n");
            SectorMasEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

         case 9:
            mostrarAlmuerzos(almuerzos, TAMALMUERZOS, lista, TAM, comidas, TAMCOMIDAS);
            break;

        case 10:
            mostrarEmpleadosXComida(comidas, TAMCOMIDAS, lista, TAM, almuerzos, TAMALMUERZOS, sectores, TAMSEC);
            break;

        case 11:
            mostrarCantidadComidasXEmpleado(comidas, TAMCOMIDAS, almuerzos, TAMALMUERZOS);
            break;

         case 12:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}


