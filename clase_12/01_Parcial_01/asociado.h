#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idAsociado;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int dni;
    int edad;

}Asociado;


#endif // ASOCIADO_H_INCLUDED

int asociado_Inicializar(Asociado array[], int size);                                    //cambiar asociado
int asociado_buscarEmpty(Asociado array[], int size, int* posicion);                    //cambiar asociado
int asociado_buscarID(Asociado array[], int size, int valorBuscado, int* posicion);                    //cambiar asociado
int asociado_buscarInt(Asociado array[], int size, int valorBuscado, int* posicion);                    //cambiar asociado
int asociado_buscarString(Asociado array[], int size, char* valorBuscado, int* indice);                    //cambiar asociado
int asociado_alta(Asociado array[], int size, int* contadorID);                          //cambiar asociado
int asociado_baja(Asociado array[], int sizeArray);                                      //cambiar asociado
int asociado_bajaValorRepetidoInt(Asociado array[], int sizeArray, int valorBuscado);
int asociado_modificar(Asociado array[], int sizeArray);                                //cambiar asociado
int asociado_ordenarPorString(Asociado array[],int size);                              //cambiar asociado
int asociado_listar(Asociado array[], int size);



