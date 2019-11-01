#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define SRT_SIZE 50


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile != NULL)
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                printf("\n Carga Exitosa\n");
                fclose(pFile);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");
        if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            retorno = 0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    Employee* pEmpleado = NULL;
    int retorno =-1;
    FILE *pFile = NULL;
    int bufferID;
    int bufferHorasTrabajadas;
    int bufferSueldo;
    char bufferNombre[SRT_SIZE];
    int contador = 0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w");
        if(pFile != NULL)
        {
            for(i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado, &bufferID);
                employee_getNombre(pEmpleado,&bufferNombre);
                employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
                employee_getSueldo(pEmpleado,&bufferSueldo);

                if(fprintf(pFile,"%d,%s,%d,%d\n", bufferID,bufferNombre,bufferHorasTrabajadas,bufferSueldo)>8)
                contador++;
            }
            retorno = 0;
            fclose(pFile);
            printf("\n Elementos guardados exitosamente %d",contador);
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

