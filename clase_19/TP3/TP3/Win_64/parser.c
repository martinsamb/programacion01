#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
     Employee personas;
     int r,i;
     r = parseData("data.csv",personas,1000);
     for(i=0; i<r; i++)
     {
     printf("id:%d nombre:%s horasTrabajadas:%d Sueldo:%d\n",
            personas[i].id,
            personas[i].nombre,
            personas[i].horasTrabajadas,
            personas[i].sueldo);
     }
     exit(EXIT_SUCCESS);

    return 1;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
