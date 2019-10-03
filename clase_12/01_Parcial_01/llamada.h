#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idLlamada;
    int isEmpty;
    //-----------------
    char motivo[TEXT_SIZE];
    int estado;
    int idAsociado;
    int idAmbulancia;
    int tiempo;

}llamada;


#endif // ASOCIADO_H_INCLUDED

int llamada_Inicializar(Llamada array[], int size);                                    //cambiar llamada
int llamada_buscarEmpty(Llamada array[], int size, int* posicion);                    //cambiar llamada
int llamada_buscarID(Llamada array[], int size, int valorBuscado, int* posicion);                    //cambiar llamada
int llamada_buscarInt(Llamada array[], int size, int valorBuscado, int* posicion);                    //cambiar llamada
int llamada_buscarString(Llamada array[], int size, char* valorB#endif // llamada_H_INCLUDEDuscado, int* indice);                    //cambiar llamada
int llamada_alta(Llamada array[], int size, int* contadorID);                          //cambiar llamada
int llamada_baja(Llamada array[], int sizeArray);                                      //cambiar llamada
int llamada_bajaValorRepetidoInt(Llamada array[], int sizeArray, int valorBuscado);
int llamada_modificar(Llamada array[], int sizeArray);                                //cambiar llamada
int llamada_ordenarPorString(Llamada array[],int size);                              //cambiar llamada
int llamada_listar(Llamada array[], int size);




