#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "Parser.h"
#include "Empleado.h"

/// recibo elemento empleado como void.
/// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
void em_calcularSueldo(void* pElement)
{
    Empleado* element = pElement;
    int horasTrabajadas;
    float sueldo;

    if(employee_getHorasTrabajadas(element, &horasTrabajadas)==TODOOK && horasTrabajadas!=0)
    {
        if(horasTrabajadas>0 && horasTrabajadas<=120)
        {
            sueldo = (float)(horasTrabajadas*1.5);
        }
        if(horasTrabajadas>120 && horasTrabajadas<=160)
        {
            horasTrabajadas = horasTrabajadas-120;
            sueldo = (float)(horasTrabajadas*6)+180;
        }
        if(horasTrabajadas>160 && horasTrabajadas<=240)
        {
            horasTrabajadas = horasTrabajadas-160;
            sueldo = (float)(horasTrabajadas*4.375)+420;
        }
        employee_setSueldo(element, sueldo);
    }
}


int employee_setId(Empleado* this,int id)
{

    int todoOk = ERROR;

    if(this!=NULL && id > 0)
    {
        this->id = id;
        todoOk = TODOOK;
    }

    return todoOk;
}


int employee_getId(Empleado* this,int* id)
{

    int todoOk = ERROR;

    if( this != NULL && id != NULL )
    {
        *id = this->id;
        todoOk = TODOOK;
    }
    return todoOk;
}


int employee_setNombre(Empleado* this, char* nombre)
{

    int todoOk = ERROR;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = TODOOK;
    }

    return todoOk;

}

int employee_getNombre(Empleado* this, char* nombre)
{

    int todoOk = ERROR;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = TODOOK;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{

    int todoOk = ERROR;

    if( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = TODOOK;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{

    int todoOk = ERROR;

    if( this != NULL && horasTrabajadas != NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = TODOOK;
    }
    return todoOk;

}

int employee_setSueldo(Empleado* this, float sueldo)
{

    int todoOk = ERROR;

    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = TODOOK;
    }

    return todoOk;

}
int employee_getSueldo(Empleado* this, float* sueldo)
{
    int todoOk = ERROR;

    if( this != NULL && sueldo != NULL )
    {
        *sueldo = this->sueldo;
        todoOk = TODOOK;
    }
    return todoOk;
}

Empleado* employee_new()
{

    Empleado* this = (Empleado*) malloc(sizeof(Empleado));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Empleado* this;

        if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
        {
            this  = employee_new();
            if(this != NULL)
            {

                if(employee_setId(this, atoi(idStr))==ERROR
                || employee_setNombre(this, nombreStr)==ERROR
                || employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))==ERROR)
                {
                    free(this);
                    this = NULL;
                }
            }
        }
    return this;
}

void mostrarEmpleado(Empleado* empleado)
{
    if(empleado != NULL)
    {
        printf("\n%2d%10s%12d hs       %.2f", (empleado)->id, (empleado)->nombre, (empleado)->horasTrabajadas, (empleado)->sueldo);
    }
}


int ordenarXSueldo( void* emp1, void* emp2){

    int retorno = 0;
    Empleado* p1;
    Empleado* p2;

    if( emp1 != NULL && emp2 != NULL)
    {
        p1 = (Empleado*) emp1;
        p2 = (Empleado*) emp2;

        if( p1->sueldo > p2-> sueldo)
        {
            retorno = 1;
        }
        else if( p1->sueldo < p2-> sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarXHoras( void* emp1, void* emp2){

    int retorno = 0;
    Empleado* p1;
    Empleado* p2;

    if( emp1 != NULL && emp2 != NULL)
    {

        p1 = (Empleado*) emp1;
        p2 = (Empleado*) emp2;

        if( p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if( p1->horasTrabajadas < p2->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int employee_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    int len = ll_len(pArrayListEmployee);
    int i;
    Empleado* empleado;

    if(pArrayListEmployee!=NULL && len>=0)
    {
        printf("\nID    Nombre    Horas Trabajadas  Sueldo");
        printf("\n--    ------    ----------------  ------");
        for(i=0;i<len;i++)
        {
            empleado = (Empleado*)ll_get(pArrayListEmployee, i);
            mostrarEmpleado(empleado);
        }
        retorno = TODOOK;
    }
    return retorno;
}
