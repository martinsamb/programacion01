#include <stdio.h>
#include <stdlib.h>

int main()
{
    eEmpleado** lista = (eEmpleado**)malloc(sizeof(eEmpleado*));
    eEmpleado** pAuxEmpleado; // Para el realloc no me la pise
    int cont = 0;//manejar los indice o cntidad de elemento del array

    char resp='s';
    int bufLegajo;//campos de la estructura guardar datos
    char bufNombre[20];
    char bufApellido[20];
    float bufSueldo;

    eEmpleado* nuevoEmpleado = new_Empleado; //Nuevo empleado inicializarlo/Crea un nuevo empleado
    //if(nuevoEmpleado!=NULL)//validar que no da nulo

    while()

    nuevoEmpleado = new_EmpleadoParam(bufLegajo,bufNombre,bufApellido,bufSueldo);//Constructor parametrico

    //accedo a mi lista aritmetica de punteros asignando la direccion de memoria de nuevoEmpleado
    *(lista+cont) = nuevoEmpleado;//variable puntero
    //lista [cont] = nuevoEmpleado//notcion vectorial;
    printf("\n Desa ingresar otro empleado");

    eEmpleado* new_Empleado()
    {
        eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));//Pide espacio de memoria

        if(emp != NULL) // validacion que no sea null//valida espacio de la memoria
        emp->legajo = 0;//Puntero a empleado accedo atrvez de flecha
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;
        emp->fechaingreso.dia;// emp es un puntero / fechaingreso es un campo de la estructura
    }
    return emp;
}


