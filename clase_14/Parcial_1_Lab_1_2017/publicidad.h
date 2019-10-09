#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idPublicidad;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char cuit[TEXT_SIZE];
    int dias;
    char archivo[TEXT_SIZE];
    int idPantalla;

}Publicidad;

/*
Init
BuscarEmpty
buscarString
Alta
Baja
Modificar
Ordenar
Listar
*/

int Publicidad_Inicializar(Publicidad array[], int size);
int Publicidad_buscarEmpty(Publicidad array[], int size, int* posicion);
int Publicidad_buscarID(Publicidad array[], int size, int valosBuscado, int* posicion);
int Publicidad_buscarCuit(Publicidad array[], int size, char* valorBuscado, int* indice);
int Publicidad_alta(Publicidad array[], int size, int* contadorID);
int Publicidad_baja(Publicidad array[], int sizeArray);
int Publicidad_bajaPantalla(Publicidad array[], int sizeArray, int valorIDPantalla);
int Publicidad_bajaPantallaCuit(Publicidad array[], int sizeArray, char* cuitBuscado);
int Publicidad_modificar(Publicidad array[], int sizeArray);
int Publicidad_listar(Publicidad array[], int size);
int Publicidad_listarPorCuit(Publicidad array[], int size, char* cuit);



#endif // PUBLICIDAD_H_INCLUDED
