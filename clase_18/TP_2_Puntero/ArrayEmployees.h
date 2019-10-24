#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char name[TEXT_SIZE];
    int sector;
    float salary;
    char lastName[TEXT_SIZE];

}Employee;

void mostrarEmployee(Employee** lista, int len);
Employee* new_EmployeeeParam( char* name, int sector, float salary,char* lastName);
Employee* new_Employee();



#endif // ARRAYEMPLOYEES_H_INCLUDED

int employee_Inicializar(Employee array[], int size);
int employee_buscarEmpty(Employee array[], int size, int* posicion);
int employee_buscarID(Employee array[], int size, int valorBuscado, int* posicion);
int employee_alta(Employee array[], int size, int* contadorID);
int employee_baja(Employee array[], int sizeArray);
int employee_modificar(Employee array[], int sizeArray);
int employee_ordenar(Employee array[],int size);
int employee_listar(Employee array[], int size);
int employee_informarSalario(Employee array[], int size);
void menuPrincipal();
void menuInformes();




