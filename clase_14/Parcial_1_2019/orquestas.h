#ifndef ORQUESTAS_H_INCLUDED
#define ORQUESTAS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
    char lugar[TEXT_SIZE];

}Orquesta;



int orquesta_Inicializar(Orquesta array[], int schar nombre[TEXT_SIZE];ize);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);                    //cambiar orquesta
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], int sizeArray);                                      //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);                                //cambiar orquesta
int orquesta_ordenarPorString(Orquesta array[],int size);                              //cambiar orquesta
int orquesta_listar(Orquesta array[], int size);                      //cambiar orquesta





#endif // ORQUESTAS_H_INCLUDED
