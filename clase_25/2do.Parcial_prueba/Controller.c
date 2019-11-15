#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmpleados LinkedList*
 * \return int
 *
 */

  int controller_loadFromText(char* path , LinkedList* pArrayListEmpleados)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListEmpleados != NULL)
        {
             if(!parser_EmployeeFromText(pFile , pArrayListEmpleados))
             {
                printf("\nCarga exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}
