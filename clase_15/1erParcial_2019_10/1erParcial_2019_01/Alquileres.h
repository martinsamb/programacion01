#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{


    int idUnico;
    int isEmpty;
    //-----------------
    int idJuego;
    int idCliente;
    int Fecha;

}Alquiler;



int alquiler_Inicializar(Alquiler array[], int size);                                    //cambiar alquiler
int alquiler_buscarEmpty(Alquiler array[], int size, int* posicion);                    //cambiar alquiler
int alquiler_buscarID(Alquiler array[], int size, int valorBuscado, int* posicion);                    //cambiar alquiler
int alquiler_buscarInt(Alquiler array[], int size, int valorBuscado, int* posicion);                    //cambiar alquiler
int alquiler_buscarString(Alquiler array[], int size, char* valorBuscado, int* indice);                    //cambiar alquiler
int alquiler_alta(Alquiler array[], int size, int* contadorID);                          //cambiar alquiler
int alquiler_baja(Alquiler array[], int sizeArray);                                      //cambiar alquiler
int alquiler_bajaValorRepetidoInt(Alquiler array[], int sizeArray, int valorBuscado);
int alquiler_modificar(Alquiler array[], int sizeArray);                                //cambiar alquiler
int alquiler_ordenarPorString(Alquiler array[],int size);                              //cambiar alquiler
int alquiler_listar(Alquiler array[], int size);                      //cambiar alquiler



#endif // ALQUILERES_H_INCLUDED
