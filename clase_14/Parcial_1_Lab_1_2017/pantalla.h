#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idPantalla;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char nombre[TEXT_SIZE];
    char direccion[TEXT_SIZE];
    char tipo [TEXT_SIZE];
    float precio;

}Pantalla;

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

int Pantalla_Inicializar(Pantalla array[], int size);
int Pantalla_buscarEmpty(Pantalla array[], int size, int* posicion);
int Pantalla_buscarID(Pantalla array[], int size, int valosBuscado, int* posicion);
int Pantalla_alta(Pantalla array[], int size, int* contadorID);
int Pantalla_baja(Pantalla array[], int sizeArray, int* id);
int Pantalla_modificar(Pantalla array[], int sizeArray);
int Pantalla_listar(Pantalla array[], int size);



#endif // PANTALLA_H_INCLUDED
