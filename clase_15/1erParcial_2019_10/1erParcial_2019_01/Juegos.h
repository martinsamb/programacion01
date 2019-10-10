#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char Descripcion[TEXT_SIZE];
    float Importe;

}Juego;


int juego_Inicializar(Juego array[], int size);                                    //cambiar juego
int juego_buscarEmpty(Juego array[], int size, int* posicion);                    //cambiar juego
int juego_buscarID(Juego array[], int size, int valorBuscado, int* posicion);                    //cambiar juego
int juego_buscarInt(Juego array[], int size, int valorBuscado, int* posicion);                    //cambiar juego
int juego_buscarString(Juego array[], int size, char* valorBuscado, int* indice);                    //cambiar juego
int juego_alta(Juego array[], int size, int* contadorID);                          //cambiar juego
int juego_baja(Juego array[], int sizeArray);                                      //cambiar juego
int juego_bajaValorRepetidoInt(Juego array[], int sizeArray, int valorBuscado);
int juego_modificar(Juego array[], int sizeArray);                                //cambiar juego
int juego_ordenarPorString(Juego array[],int size);                              //cambiar juego
int juego_listar(Juego array[], int size);                      //cambiar juego




#endif // JUEGOS_H_INCLUDED
