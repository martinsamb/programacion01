#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int idProducto;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int idUsuario;
    float precio;
    int stock;
    int cantidadVendida;
    int estado;



}Producto;



int producto_Inicializar(Producto array[], int size);                                    //cambiar producto
int producto_buscarEmpty(Producto array[], int size, int* posicion);                    //cambiar producto
int producto_buscarID(Producto array[], int size, int valorBuscado, int* posicion);                    //cambiar producto
int producto_buscarInt(Producto array[], int size, int valorBuscado, int* posicion);                    //cambiar producto
int producto_buscarString(Producto array[], int size, char* valorBuscado, int* indice);                    //cambiar producto
int producto_alta(Producto array[], int size, int* contadorID);                          //cambiar producto
int producto_baja(Producto array[], int sizeArray);                                      //cambiar producto
int producto_bajaValorRepetidoInt(Producto array[], int sizeArray, int valorBuscado);
int producto_modificar(Producto array[], int sizeArray);                                //cambiar producto
int producto_ordenarPorString(Producto array[],int size);                              //cambiar producto
int producto_listar(Producto array[], int size);                      //cambiar producto





#endif // PRODUCTOS_H_INCLUDED
