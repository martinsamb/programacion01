#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "clases.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Sectores con mas empleados\n");
    printf("9- Almuerzos\n");
    printf("10- Mostrar cantidad de empleados x comida\n");
    printf("11- Mostrar cantidad de comidas\n");
    printf("12- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

   consigioNombre =  obtenerSector(sectores, tam, emp.idSector, nombreSector);

    if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }
    printf("   %d   %10s     %c     %.2f     %02d/%02d/%4d    %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    system("cls");

    printf(" Legajo      Nombre     Sexo    Sueldo     FechaIngreso   Sector\n");
    printf(" ------      ------     ----    ------     ------------   ------\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int indice;
    int legajo;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

             printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);

            mostrarSectores(sectores, tamSector);

            printf("Ingrese id sector: ");
            scanf("%d", &vec[indice].idSector);


            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");

    for(int i=0; i < tamSec; i++){
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++){
            if( empleados[j].idSector == sectores[i].id && empleados[j].ocupado== 1){
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int contador;

    for(int i=0; i < tamSec; i++){
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);

        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1){
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }


}

void mostrarSectores( eSector sectores[], int tam){

    printf("\n    Sectores\n");
    printf(" id     descripcion\n\n");

    for(int i=0; i < tam; i++){
        printf("  %d      %10s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\n\n");
}

int obtenerComida(eComida comida[], int tam, int idComida)
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)    {

        if(idComida == comida[i].id)
        {
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

void mostrarComidas( eComida comidas[], int tam){

    printf("\nCOMIDAS\n\n");
    printf(" id     descripcion\n\n");

    for(int i=0; i < tam; i++){
        printf("  %d      %10s\n", comidas[i].id, comidas[i].descripcion);
    }
    printf("\n\n");
}

void mostrarAlmuerzos (eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamComida)
{
    char descComida[20];
    char nombreEmpleado[20];

    system("cls");
    printf("*** LISTADO DE ALMUERZOS***\n\n");
    printf("ID  Legajo    Nombre      Comida      Fecha\n\n");

    for(int i=0; i < tamAlmuerzo; i++)
    {
        for(int j=0; j < tamEmp; j++)
        {
            if( almuerzo[i].idEmpleado==empleados[j].legajo && empleados[j].ocupado==1)
            {
                strcpy(nombreEmpleado, empleados[j].nombre);
                break;
            }
        }

        for(int k=0; k < tamComida; k++)
        {
            if( almuerzo[i].idComida == comidas[k].id)
            {
                strcpy(descComida, comidas[k].descripcion);
                break;
            }
        }

        printf("%d  %d  %8s  %12s   %02d/%02d/%04d\n",
               almuerzo[i].id, almuerzo[i].idEmpleado, nombreEmpleado, descComida,
               almuerzo[i].fecha.dia, almuerzo[i].fecha.mes, almuerzo[i].fecha.anio);
    }
    printf("\n\n");
    system("pause");
}



void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec){


int totales[tamSec];
int mayor;
int flag = 0;

for(int i=0; i < tamSec; i++){

        totales[i] = 0;
        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1){
                totales[i]++;
            }
        }
    }

     for(int i=0; i < tamSec; i++){
            if( flag == 0 || mayor < totales[i]){
                mayor = totales[i];
                flag = 1;
            }
     }

     printf("Cantidad mayor de empleados %d\n\n", mayor);
     printf("En el o los siguientes sectore\n\n");

      for(int i=0; i < tamSec; i++){
            if( totales[i] == mayor){
                printf("%s\n", sectores[i].descripcion);
            }

      }
}

void mostrarEmpleadosXComida(eComida* comidas, int lenComida, eEmpleado* empleados, int lenEmpleado, eAlmuerzo* almuerzos, int lenAlmuerzos, eSector* sectores, int lenSectores)
{
    int numComida;

    mostrarComidas(comidas, lenComida);
    printf("\nIngrese el ID de la comida: ");
    scanf("%d", &numComida);

    if(obtenerComida(comidas, lenComida, numComida)==1)
    {
        for(int i=0; i<lenAlmuerzos; i++)
        {
            if(almuerzos[i].idComida==numComida)
            {
                for(int j=0; j<lenEmpleado; j++)
                {
                    if(almuerzos[i].idEmpleado==empleados[j].legajo && empleados[j].ocupado==1)
                    {
                        mostrarEmpleado(sectores, lenSectores, empleados[j]);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\n OPCION ERRONEA\n\n");
    }
    system("pause");
}

void mostrarCantidadComidasXEmpleado(eComida* comidas, int lenComidas, eAlmuerzo* almuerzos, int lenAlmuerzos)
{
    int cantidadComida[lenComidas];

    for(int i=0; i<lenComidas; i++)
    {
        cantidadComida[i]=0;

        for(int j=0; j<lenAlmuerzos; j++)
        {
            if(almuerzos[j].idComida==comidas[i].id)
            {
                cantidadComida[i]++;
            }
        }
    }
    for(int i=0; i<lenComidas; i++)
    {
        printf("%s: %d \n", comidas[i].descripcion, cantidadComida[i]);
    }
    system("\npause");
}

int ordenarPorNombreYLegajo(eEmpleado* list, int len, int order)
{
    int retorno=-1;
    eEmpleado auxlist;
    int i,j;
    if(list!=NULL)
    {
        for(i=0; i < len - 1; i++)
        {
            for(j=i+1; j < len; j++)
            {
                if((order==0 && strcmp(list[j].nombre, list[i].nombre)<0)
                    || (order==1 && strcmp(list[j].nombre, list[i].nombre) > 0))
                {
                    auxlist = list[j];
                    list[j] = list[i];
                    list[i] = auxlist;
                }
                else if(strcmp(list[j].nombre, list[i].nombre) == 0)
                {
                    if((order==0 && list[j].legajo < list[i].legajo) || (order==1 && list[j].legajo > list[i].legajo))
                    {
                        auxlist = list[j];
                        list[j] = list[i];
                        list[i] = auxlist;
                    }
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
