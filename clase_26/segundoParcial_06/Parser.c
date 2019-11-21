#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"

int parser_parseEmpleados(char* fileName, LinkedList* pArrayListEmpleados)
{
    FILE* pFile;
    int parseo;

    pFile = fopen(fileName, "r");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    parseo=parser_empleadoFromText(pFile,pArrayListEmpleados);
    if(parseo != 0)
    {
        printf("\n\nSALTO MAL\n\n");
        return -1;
    }
    fclose(pFile);

    return 1;

}

int parser_empleadoFromText(FILE* pFile, LinkedList* pArrayListEmpleados)
{
    Empleado* this = newEmpleado();
    int retorno = -1;
    char buffer[3][30];
    int cant;

    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);

    if(pFile != NULL && pArrayListEmpleados != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
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
            this = empleado_newParametros(buffer[0],buffer[1],buffer[2]);
            if(this != NULL)
            {
                ll_add(pArrayListEmpleados, this);//agergo un nuevo elemento a la lista
            }
        }
        retorno = 0;
    }
    free(this);
    return retorno;
}

int generarArchivoSueldos(char* fileName, LinkedList* pArrayListEmpleados)
{
    FILE* pArchivo;
    int retorno = -1;
    if(fileName != NULL && pArrayListEmpleados != NULL)
    {
        pArchivo = fopen(fileName,"w");
        if(pArchivo != NULL)
        {
            retorno = save_empleadosToText(pArchivo,pArrayListEmpleados);
            fclose(pArchivo);
        }
    }
    return retorno;
}

int save_empleadosToText(FILE* pFile, LinkedList* pArrayListEmpleados)
{
    int retorno = -1;
    int i = 0;
    int len, idAux, horasAux;
    float sueldoAux;
    Empleado* pEmpleado;
    char nombreAux[50];
    if(pFile != NULL && pArrayListEmpleados != NULL)
    {
        retorno = 0;
        fprintf(pFile,"id, nombre, horasTrabajadas, sueldo\n");
        len = ll_len(pArrayListEmpleados);
        do
        {
            pEmpleado = (Empleado*)ll_get(pArrayListEmpleados,i);

            if(pEmpleado != NULL && empleado_getNombre(pEmpleado,nombreAux)== 0
               && empleado_getId(pEmpleado, &idAux)==0
               && empleado_getSueldo(pEmpleado,&sueldoAux)== 0
               && empleado_getHorasTrabajadas(pEmpleado,&horasAux)== 0)
            {
                fprintf(pFile,"%d,%s,%d,%.2f\n",idAux, nombreAux,horasAux, sueldoAux);
            }
            i++;
        }while(i<len);
    }
    return retorno;
}
