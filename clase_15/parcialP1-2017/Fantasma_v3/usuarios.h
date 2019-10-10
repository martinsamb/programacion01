#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUsuario;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char password[TEXT_SIZE];
    int calificaciones;

}Usuario;


int usuario_Inicializar(Usuario array[], int size);                                    //cambiar usuario
int usuario_buscarEmpty(Usuario array[], int size, int* posicion);                    //cambiar usuario
int usuario_buscarID(Usuario array[], int size, int valorBuscado, int* posicion);                    //cambiar usuario
int usuario_buscarInt(Usuario array[], int size, int valorBuscado, int* posicion);                    //cambiar usuario
int usuario_buscarString(Usuario array[], int size, char* valorBuscado, int* indice);                    //cambiar usuario
int usuario_alta(Usuario array[], int size, int* contadorID);                          //cambiar usuario
int usuario_baja(Usuario array[], int sizeArray);                                      //cambiar usuario
int usuario_bajaValorRepetidoInt(Usuario array[], int sizeArray, int valorBuscado);
int usuario_modificar(Usuario array[], int sizeArray);                                //cambiar usuario
int usuario_ordenarPorString(Usuario array[],int size);                              //cambiar usuario
int usuario_listar(Usuario array[], int size);                      //cambiar usuario





#endif // USUARIOS_H_INCLUDED
