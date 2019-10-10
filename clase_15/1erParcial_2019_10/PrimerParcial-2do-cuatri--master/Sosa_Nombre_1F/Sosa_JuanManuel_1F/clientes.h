#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[31];
    char apellido[31];
    char sexo;
    char domicilio[51];
    int telefono[21];
    int isEmpty;//estado habilitado 0 no habilitado 1
}Cliente;

//int clientes_baja(Cliente* arrayCliente,int limiteCliente, Instrumento* arrayInstrumento, int limiteInstrumento);
int clientes_baja(Cliente* arrayCliente,int limite);
int clientes_initStruct(Cliente* arrayCliente, int limite);
int clientes_findEmpty (Cliente* arrayCliente,int limite, int* resultado);
void clientes_print(Cliente* arrayCliente, int limite);
//int musico_alta(Cliente* arrayCliente, Orquesta* arrayOrquesta, int* id, int limite);
void clientes_print(Cliente* arrayCliente, int limite);
void harcodearClientes(Cliente* arrayA, int limite);
int clientes_findById(char* msj,Cliente* arrayCliente,int* idEncontrado, int limite);
int musico_buscarID(Cliente* arrayCliente, int limite, int valorBuscado, int* posicion) ;


#endif // MUSICO_H_INCLUDED
