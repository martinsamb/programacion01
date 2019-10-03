#ifndef ARMADURA_H_INCLUDED
#define ARMADURA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

}Fantasma;

typedef struct
{
    char tipo[TEXT_SIZE];
    char nombre[TEXT_SIZE];
    char direccion[TEXT_SIZE];
    float precio;
    int isEmpty;
    int idPantalla;

}ePantalla;

typedef struct
{
    int isEmpty;
    int idPantalla;
    char cuit[TEXT_SIZE];
    int diasPublicacion;
    char nombreArchivo[TEXT_SIZE];
    int idPublicacion;

}ePublicacion;


typedef struct
{
    int idEmpleado;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

#endif


int pantalla_Inicializar(ePantalla array[], int size);
int publicacion_Inicializar(ePublicacion array[], int size);

int pantalla_buscarEmpty(ePantalla array[], int size, int* posicion);
int publicacion_buscarEmpty(ePublicacion array[], int size, int* posicion);

int fantasma_Inicializar(Fantasma array[], int size);                                    //cambiar fantasma
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion);                    //cambiar fantasma
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int fantasma_alta(Fantasma array[], int size, int* contadorID);                          //cambiar fantasma
int fantasma_baja(Fantasma array[], int sizeArray);                                      //cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int sizeArray);                                //cambiar fantasma
int fantasma_ordenarPorString(Fantasma array[],int size);                              //cambiar fantasma
int fantasma_listar(Fantasma array[], int size);                      //cambiar fantasma


