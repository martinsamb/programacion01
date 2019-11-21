#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"

void empleado_calcularSueldo(void* pElement)
{
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado

	//pe->horasTrabajadas;
	//pe->sueldo = 99; //hacer cuenta
	Empleado* element = pElement;
    int horasTrabajadas;
    float sueldo;

    if(empleado_getHorasTrabajadas(element,&horasTrabajadas)== 0 && horasTrabajadas != 0)
    {
        if(horasTrabajadas>0 && horasTrabajadas>=120)
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
        empleado_setSueldo(element, sueldo);
    }

}
//int funcionCriterioFiltro(void* p)
Empleado* newEmpleado()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

/** \brief Valida los campos y los carga en una variable Entrega
 *
 * \param idStr char*
 * \param tipoStr char*
 * \param cantidadStr char*
 * \param importeStr char*
 * \return Entrega*
 *
 */
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Empleado* retorno=NULL;
    Empleado* bufferP;

    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL)
    {
        bufferP=newEmpleado();
        if(bufferP!=NULL)
        {
            if(!empleado_setIdStr(bufferP,idStr) &&
                !empleado_setNombre(bufferP,nombreStr) &&
                !empleado_setHorasTrabajadasStr(bufferP,horasTrabajadasStr))
            {
                free(bufferP);
                bufferP = NULL;
            }
        }
    }
    return bufferP;
}

int empleado_delete(Empleado* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}

int empleado_setId(Empleado* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int empleado_getId(Empleado* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}


int empleado_setIdStr(Empleado* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=empleado_setId(this,atoi(id));
    }
    return retorno;
}

int empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

//_____________________________________________________

int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int empleado_setHorasTrabajadasStr(Empleado* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL && isValidNumber(horasTrabajadas))
    {
        retorno=empleado_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}
//------------------------------------------------------------------------
int empleado_setSueldo(Empleado* this,float sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

int empleado_getSueldo(Empleado* this,float* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}


int empleado_setSueldoStr(Empleado* this,char* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL && isValidNumber(sueldo))
    {
        retorno=empleado_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

void empleado_mostrarEmpleado(Empleado* pEmpleado)
{
    if(pEmpleado != NULL)
    {
        printf("\n%2d%10s%12d%.2f",(pEmpleado)->id, (pEmpleado)->nombre, (pEmpleado)->horasTrabajadas, (pEmpleado)->sueldo);
    }
}

int empleado_ordenarPorSueldo(void* empleado1, void* empleado2)
{
    int retorno = 0;
    Empleado* p1;
    Empleado* p2;

    if(empleado1 != NULL && empleado2 != NULL)
    {
        if(p1->sueldo > p2->sueldo)
        {
            retorno = -1;
        }
        else if(p1->sueldo < p2->sueldo)
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

int empleado_ordenarPorHoras(void* empleado1, void* empleado2)
{
    int retorno = 0;
    Empleado* p1;
    Empleado* p2;

    if(empleado1 != NULL && empleado2 != NULL)
    {
        if(p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno = -1;
        }
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
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

int empleado_listaEmpleado(LinkedList* pArrayListEmpleado)
{
    int retorno =-1;
    int len = ll_len(pArrayListEmpleado);
    int i;
    Empleado* pEmpleado;

    if(pArrayListEmpleado != NULL && len>=0)
    {
        printf("\nID   Nombre   Horas Trabajadas  Sueldo");
        printf("\n--------------------------------------");
        for(i=0;i<len;i++)
        {
            pEmpleado = (Empleado*)ll_get(pArrayListEmpleado, i);
            empleado_mostrarEmpleado(pEmpleado);
        }
        retorno = 0;
    }
    return retorno;
}



