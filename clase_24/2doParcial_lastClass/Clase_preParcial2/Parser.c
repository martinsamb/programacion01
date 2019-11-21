#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* file;
    int parseo;

    file = fopen(fileName, "r");
    if(file==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    parseo = parser_EmployeeFromText(file, listaEmpleados);
    if(parseo!=TODOOK)
    {
        printf("\n\nSALIO MAL\n\n");
        return ERROR;
    }
    fclose(file);

    return 1; // OK
}

int parser_EmployeeFromText(FILE* pFile , LinkedList* pListaEmpleados)
{
    Empleado* this = employee_new();
    int retorno = ERROR;

    char buffer[3][30];

    int cant;

    //ESTO ES PARA LEER LA PRIMER FILA Q TIENE LA DESCRIPCION DEL STRUCT
    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);
    //printf(" %5s %15s %15s\n", buffer[0], buffer[1], buffer[2]);

    if(pFile!=NULL && pListaEmpleados!=NULL)
    {
        while(!feof(pFile))
        {
            cant =  fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);
            if(cant < 3)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }

            this = employee_newParametros(buffer[0], buffer[1], buffer[2]);
            if(this!=NULL)
            {
                ll_add(pListaEmpleados, this);
                //contadorID();
            }
        }
        retorno = TODOOK;
    }
    free(this);
    return retorno;
}


int generarArchivoSueldos(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pArchivo;
    int retorno=ERROR;
    if(fileName != NULL && listaEmpleados != NULL)
    {
        pArchivo=fopen(fileName,"w");
        if(pArchivo != NULL)
        {
            retorno=save_EmployeeToText(pArchivo,listaEmpleados);
            fclose(pArchivo);
        }
    }
    return retorno;
}

int save_EmployeeToText(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int i=0;
    int len, idAux, horasAux;
    float sueldoAux;
    Empleado* empleado;
    char nombreAux[50];

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        retorno=TODOOK;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        do
        {
            empleado=(Empleado*)ll_get(pArrayListEmployee,i);

            if(empleado!=NULL && employee_getNombre(empleado, nombreAux)==TODOOK
            && employee_getId(empleado,&idAux)==TODOOK
            && employee_getSueldo(empleado,&sueldoAux)==TODOOK
            && employee_getHorasTrabajadas(empleado,&horasAux)==TODOOK)
            {
                fprintf(pFile,"%d,%s,%d,%.2f\n",idAux,nombreAux,horasAux,sueldoAux);
            }
            i++;
        }while(i<len);
    }
    return retorno;
}

