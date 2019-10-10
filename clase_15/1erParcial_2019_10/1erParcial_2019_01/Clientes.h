#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#define TEXT_SHORT 21
#define TEXT_MEDIUM 31
#define TEXT_LARGE 51

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char Apellido[TEXT_MEDIUM];
    char Nombre[TEXT_MEDIUM];
    char Sexo;
    char Domicilio[TEXT_LARGE];
    char Telefono[TEXT_SHORT];


}Cliente;


int cliente_Inicializar(Cliente array[], int size);                                    //cambiar cliente
int cliente_buscarEmpty(Cliente array[], int size, int* posicion);                    //cambiar cliente
int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion);                    //cambiar cliente
int cliente_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion);                    //cambiar cliente
int cliente_buscarString(Cliente array[], int size, char* valorBuscado, int* indice);                    //cambiar cliente
int cliente_alta(Cliente array[], int size, int* contadorID);                          //cambiar cliente
int cliente_baja(Cliente array[], int sizeArray);                                      //cambiar cliente
int cliente_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado);
int cliente_modificar(Cliente array[], int sizeArray);                                //cambiar cliente
int cliente_ordenarPorString(Cliente array[],int size);                              //cambiar cliente
int cliente_listar(Cliente array[], int size);                      //cambiar cliente




#endif // CLIENTES_H_INCLUDED
