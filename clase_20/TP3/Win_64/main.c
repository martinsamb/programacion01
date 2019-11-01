#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
***************************;**************************/


int main()
{
    int option = 0;
    int ultimoId = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();//creacion de memoria en el Linkedlist
    //es equivalente a una lista dinamica
    do{
        menuPrincipal();
        if(utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,&option)!= 0)
        {
            option = 10;
        }
        else
        {
            switch(option)
            {
                case 1:
                    controller_loadFromText("data.csv",listaEmpleados);
                    employee_searchMaxId(listaEmpleados,&ultimoId);
                    break;

                case 2:
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    employee_searchMaxId(listaEmpleados,&ultimoId);
                    break;

                case 3:
                    break;

                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    break;

                case 7:
                    break;

                case 8:
                    break;

                case 9:
                    break;

                case 10:
                    break;
            }
        }
    }while(option != 10);
    return 0;
}
