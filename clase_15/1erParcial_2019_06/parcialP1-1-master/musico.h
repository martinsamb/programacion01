#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;

}Musico;


#endif // MUSICO_H_INCLUDED

int musico_inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarOrquesta(Musico array[], int size, int valosBuscado, int* posicion);
int musico_buscarInstrumento(Musico array[], int size, int valosBuscado, int* posicion);

int musico_alta(Musico array[], int size, int* contadorID);
int musico_baja(Musico array[], int sizeArray);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);
int musico_listar(Musico array[], int size);
int musico_ordenarPorApellido(Musico array[],int size);





