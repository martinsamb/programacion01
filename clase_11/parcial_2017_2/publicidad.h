#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idPublicidad;
    int isEmpty;
    //-----------------
    char cuit[TEXT_SIZE];
    int dias;
    char archivo[TEXT_SIZE];
    int idPantalla;

}Publicidad;


#endif // FANTASMA_H_INCLUDED

int publicidad_Inicializar(Publicidad array[], int size);                                    //cambiar publicidad
int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion);                    //cambiar publicidad
int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion);                    //cambiar publicidad
int publicidad_buscarCuit(Publicidad array[], int size, char* valorBuscado, int* indice);                    //cambiar publicidad
int publicidad_alta(Publicidad array[], int size, int* contadorID);                          //cambiar publicidad
int publicidad_baja(Publicidad array[], int sizeArray);                                      //cambiar publicidad
int publicidad_bajaPantalla(Publicidad array[], int sizeArray, int valorIdPantalla);
int publicidad_bajaPantallaCuit(Publicidad array[], int sizeArray, char* cuitBuscado);
int publicidad_modificar(Publicidad array[], int sizeArray);                                //cambiar publicidad
int publicidad_listar(Publicidad array[], int size);                      //cambiar publicidad
//int publicidad_listarPorCuit(Publicidad array[], int size, char*cuit);



