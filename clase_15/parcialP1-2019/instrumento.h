#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
}Instrumento;

#endif // INSTRUMENTO_H_INCLUDED

int instrumento_inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_listar(Instrumento array[], int size);
void menuInformes();
void menuPrincipal();
