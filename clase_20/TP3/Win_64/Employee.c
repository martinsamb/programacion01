#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"



Employee* employee_new(void)
{
    return(Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* retorno = NULL;
    Employee* bufferP;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        bufferP = employee_new();
        if(bufferP != NULL)
        {
            if(!employee_setIdStr(bufferP,idStr)&&
               !employee_setNombre(bufferP,nombreStr)&&
               !employee_setHorasTrabajadas(bufferP,horasTrabajadasStr)&&
               !employee_setSueldoStr(bufferP,sueldoStr))
            {
                retorno = bufferP;
            }
            else
            {
                employee_delete(bufferP);
            }
        }
    }
    return retorno;
}

Employee* employee_newParametrosInt(int id, char* nombreStr, int horasTrabajadas, int sueldo)
{
    void* retorno = NULL;
    Employee* pEmployee = employee_new();
    if(pEmployee != NULL &&
       id > 0 &&
       nombreStr != NULL &&
       horasTrabajadas > 0 &&
       sueldo > 0)
    {
        if(!employee_setId(pEmployee, id) &&
           !employee_setNombre(pEmployee,nombreStr)&&
           !employee_setHorasTrabajadas(pEmployee, horasTrabajadas)&&
           !employee_setSueldo(pEmployee, sueldo))
        {
            retorno = pEmployee;
        }
        else
        {
            employee_delete(pEmployee);
        }
    }
    return retorno;
}
void employee_delete()
{
    int retorno =-1;

    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno =-1;

    retun retorno;
}
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);




