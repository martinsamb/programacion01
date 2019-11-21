#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "LinkedList.h"
#define TRUE 1
#define FALSE 0

#define ERROR -1
#define TODOOK 0

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  float sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);


Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);

int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int employee_setSueldo(Empleado* this,float sueldo);
int employee_getSueldo(Empleado* this,float* sueldo);

void mostrarEmpleado(Empleado* empleado);
int ordenarXSueldo( void* emp1, void* emp2);
int ordenarXHoras( void* emp1, void* emp2);

int menuConOpcion(int reintentos, int numOpcMin, int numOpcMax);
int opciones(int reintentos, int numOpcMin, int numOpcMax);
int contadorID(void);

int employee_ListEmployee(LinkedList* pArrayListEmployee);

#endif // EMPLEADO_H_INCLUDED
