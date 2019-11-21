#define TAM 15
#define TAMSEC 5
#define TAMALMUERZOS 10
#define TAMCOMIDAS 5

typedef struct
{
   int dia;
   int mes;
   int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20];

} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;

}eAlmuerzo;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int ocupado;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

} eSector;



int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarAlmuerzos (eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamComida);
void mostrarSectores( eSector sectores[], int tam);
void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
int obtenerComida(eComida comida[], int tam, int idComida);
void mostrarComidas( eComida comidas[], int tam);
void mostrarEmpleadosXComida(eComida* comidas, int lenComida, eEmpleado* empleados, int lenEmpleado, eAlmuerzo* almuerzos, int lenAlmuerzos, eSector* sectores, int lenSectores);
void mostrarCantidadComidasXEmpleado(eComida* comidas, int lenComidas, eAlmuerzo* almuerzos, int lenAlmuerzos);


int ordenarPorNombreYLegajo(eEmpleado* list, int len, int order);
