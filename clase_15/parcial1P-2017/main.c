#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad


#define QTY_USUARIOS 100
#define QTY_PRODUCTOS 1000

int main()
{
    int opcion;
    int contadorIdUsuario=0;                   //cambiar

    Usuario arrayUsuario[QTY_USUARIOS];                   //cambiar
    usuario_Inicializar(arrayUsuario,QTY_USUARIOS);                   //cambiar

    int contadorIdProducto=0;                   //cambiar

    Producto arrayProducto[QTY_PRODUCTOS];                   //cambiar
    producto_Inicializar(arrayProducto,QTY_PRODUCTOS);                   //cambiar

    do
    {
        utn_getUnsignedInt("\n\n1) Alta usuario \n2) Modificar usuario \n3) Baja usuario \n4) Publicar producto \n5) Modificar producto \n6) Cancelar producto\n7)Comprar producto \n8)Listar productos usuarios \n9)Listar productos\n10)Listar usuarios",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                usuario_alta(arrayUsuario,QTY_USUARIOS,&contadorIdusuario);                   //cambiar
                break;

            case 2: //Modificar
                usuario_modificar(arrayUsuario,QTY_USUARIOS);                   //cambiar
                break;

            case 3: //Baja
                usuario_baja(arrayUsuario,QTY_USUARIOS);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorString(arrayFantasma,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
