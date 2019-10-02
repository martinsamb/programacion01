#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idPantalla;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char direccion[TEXT_SIZE];
    char tipo[TEXT_SIZE];
    float precio;

}Pantalla;


#endif // PANTALLA_H_INCLUDED

int pantalla_Inicializar(Pantalla array[], int size);                                    //cambiar pantalla
int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion);                    //cambiar pantalla
int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* indice);                    //cambiar pantalla
int pantalla_alta(Pantalla array[], int size, int* contadorID);                          //cambiar pantalla
int pantalla_baja(Pantalla array[], int sizeArray, int* id);                                      //cambiar pantalla
int pantalla_modificar(Pantalla array[], int sizeArray);                                //cambiar pantalla
int pantalla_listar(Pantalla array[], int size);                      //cambiar pantalla



