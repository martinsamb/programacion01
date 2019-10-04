#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;

}Musico;


int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico array[], int size, int* contadorID);                          //cambiar musico
int musico_baja(Musico array[], int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);                                //cambiar musico
int musico_ordenarPorString(Musico array[],int size);                              //cambiar musico
int musico_listar(Musico array[], int size);                      //cambiar musicoR

#endif // MUSICOS_H_INCLUDED


