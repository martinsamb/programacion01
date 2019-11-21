#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "LinkedList.h"

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void empleado_calcularSueldo(void* pElement);

Empleado* newEmpleado();
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

int empleado_delete(Empleado* this);

int empleado_setId(Empleado* this,int id);
int empleado_getId(Empleado* this,int* id);
int empleado_setIdStr(Empleado* this,char* id);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);
//___________________________________________________________________
int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int empleado_setHorasTrabajadasStr(Empleado* this,char* horasTrabajadas);

int empleado_setSueldo(Empleado* this,float sueldo);
int empleado_getSueldo(Empleado* this,float* sueldo);
int empleado_setSueldoStr(Empleado* this,char* sueldo);


void empleado_mostrarEmpleado(Empleado* pEmpleado);
int empleado_ordenarPorSueldo(void* empleado1, void* empleado2);
int empleado_ordenarPorHoras(void* empleado1, void* empleado2);
int empleado_listaEmpleado(LinkedList* pArrayListEmpleado);




#endif // EMPLEADO_H_INCLUDED
