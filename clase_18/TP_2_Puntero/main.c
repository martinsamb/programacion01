#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"


#define QTY_ARRAY_TIPO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
     Employee** lista = (Employee**) malloc(sizeof(Employee*));
     Employee** pAuxEmployee;
     int cont = 0;
     //int cant;
     char resp='s';
     int bufLegajo;
     char bufNombre[20];
     char bufApellido[20];
     float bufSueldo;

     eEmpleado* nuevoEmpleado = new_Empleado();

    int opcion;
    int opcionOrdenar;
    int contadorIdemployee=0;
    int flag = 0;
    /*
    float sumSalary;
    float aveSalary = 0;
    float qtySalary;
    aveSalary = sumSalary/qtySalary;
    */
    Employee arrayEmployee[QTY_ARRAY_TIPO];
    employee_Inicializar(arrayEmployee,QTY_ARRAY_TIPO);

    //*******************************************************************
    arrayEmployee[0].idUnico=0;
    arrayEmployee[0].isEmpty=0;
    arrayEmployee[0].sector=0;
    arrayEmployee[0].salary=0;
    strcpy(arrayEmployee[0].name,"CCCCC");
    strcpy(arrayEmployee[0].lastName,"CCCCC");
    contadorIdemployee++;

    arrayEmployee[1].idUnico=1;
    arrayEmployee[1].isEmpty=0;
    arrayEmployee[1].sector=0;
    arrayEmployee[1].salary=0;
    strcpy(arrayEmployee[1].name,"AAAAA");
    strcpy(arrayEmployee[1].lastName,"AAAAA");
    contadorIdemployee++;

    arrayEmployee[2].idUnico=0;
    arrayEmployee[2].isEmpty=0;
    arrayEmployee[2].sector=0;
    arrayEmployee[2].salary=20;
    strcpy(arrayEmployee[2].name,"BBBBB");
    strcpy(arrayEmployee[2].lastName,"BBBBBB");
    contadorIdemployee++;

    arrayEmployee[3].idUnico=0;
    arrayEmployee[3].isEmpty=0;
    arrayEmployee[3].sector=0;
    arrayEmployee[3].salary=10;
    strcpy(arrayEmployee[3].name,"BBBBB");
    strcpy(arrayEmployee[3].lastName,"BBBBBB");
    contadorIdemployee++;


    //********************************************************************

    do
    {
        menuPrincipal();
        utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                if(employee_alta(arrayEmployee,QTY_ARRAY_TIPO,&contadorIdemployee)==0)
                        flag=1;
                    break;

            case 2: //Modificar
                if(flag==0)
                    {
                        printf("\nNo se han ingresado empleados aun");
                    }
                    else
                        employee_modificar(arrayEmployee,QTY_ARRAY_TIPO);
                    break;

            case 3: //Baja
                if(flag==0)
                    {
                        printf("\nNo se han ingresado empleados aun");
                    }
                    else
                        employee_baja(arrayEmployee,QTY_ARRAY_TIPO);
                    break;

            case 4://Informe
                do
                {
                    menuInformes();
                    utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,4,1,&opcionOrdenar);
                    switch(opcionOrdenar)
                    {
                        case 1:
                            if(flag==0)
                        {
                            printf("\nNo se han ingresado empleados aun");
                        }
                        else
                        {
                            employee_ordenar(arrayEmployee,QTY_ARRAY_TIPO);
                            employee_listar(arrayEmployee,QTY_ARRAY_TIPO);
                        }
                        break;

                        case 2:
                            if(flag==0)
                        {
                            printf("\nNo se han ingresado empleados aun");
                        }
                        else
                            employee_informarSalario(arrayEmployee,QTY_ARRAY_TIPO);
                        break;

                        case 3:
                            break;
                        default:
                            printf("\nOpcion no valida");

                    }
                }while(opcionOrdenar != 3);
                break;

            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
