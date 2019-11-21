/*
 ============================================================================
 Name        : Parcial.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>

#include "validaciones.h"
#include "pedidos.h"
#include "clientes.h"
#include "informes.h"

#define OPCIONMIN 1
#define OPCIONMAX 11

int main()
{
    int salir=0;
    int clienteID=1;
    int pedidoID=1;
    int index;
    int flag1=0;
    int flag2=0;
    int flagHardcode=1;

    eCliente cliente[TAM_CLIENTE];
    inicializar_Cliente(cliente, TAM_CLIENTE);
    hardcodear_Cliente(cliente); ///ACTIVADOR DE HARDCODEO

    ePedido pedido[TAM_PEDIDOS];
    inicializar_Pedido(pedido, TAM_PEDIDOS);
    hardcodear_Pedido(pedido);

    do{
        //system("cls");
        switch(menuConOpcion(3,OPCIONMIN,OPCIONMAX))
        {
            case 1:
                //system("cls");
                printf("\n***ALTA DE CLIENTE***\n\n");
                if(alta_Cliente(cliente, TAM_CLIENTE, clienteID)==-1)
                    printf("\nError en el Alta de la Cliente\n");
                else
                {
                    index = buscar_ClienteById(cliente, clienteID, TAM_CLIENTE);
                    printf("\nAlta Exitosa\n\n");
                    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
                    printf("--\t------\t\t----\t\t---------\t---------\n");
                    print_Cliente(cliente, index, TAM_CLIENTE);
                    clienteID++;
                    flag1=1;
                }
                break;

            case 2:
                //system("cls");
                if(flag1==1)
                {
                    if(editar_Cliente(cliente, TAM_CLIENTE)==-1)
                        printf("\n\nError en la Modificacion\n");
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

            case 3:
                //system("cls");
                if(flag1==1)
                {
                    if(baja_Cliente(cliente, TAM_CLIENTE)==-1)
                        printf("\n\nError en la Baja\n");
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

            case 4:
                //system("cls");
                if(flag1==0)
                {
                    printf("\nNO SE CARGO NINGUNA CLIENTE\n");
                    break;
                }
                printf("\n***ALTA DE PEDIDOS***\n\n");
                if(alta_Pedido(pedido, TAM_PEDIDOS, pedidoID, cliente, TAM_CLIENTE)==-1)
                    printf("\nError en el Alta del Cliente\n");
                else
                {
                    printf("\nAlta Exitosa\n\n");
                    pedidoID++;
                    flag2=1;
                }
                break;

            case 5:
                //system("cls");
                if(flag2==1)
                {
                    if(procesarResiduos(pedido, TAM_PEDIDOS, cliente, TAM_CLIENTE)==-1)
                        printf("\n\nError en la Modificacion\n");
                    else
                    	printf("\nProceso realizado correctamete");
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

            case 6:
                if(flag1==1 || flagHardcode==1)
                {
                    listar_ClienteConPedido(pedido, TAM_PEDIDOS, cliente, TAM_CLIENTE);
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

           case 7:
                if(flag2==1 || flagHardcode==1)
                {
                    listar_PedidoPendiente(pedido, TAM_PEDIDOS, cliente, TAM_CLIENTE);
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

            case 8:
                if(flag2==1 || flagHardcode==1)
                {
                    listar_PedidoProcesado(pedido, TAM_PEDIDOS, cliente, TAM_CLIENTE);
                }
                else
                    printf("\n\nNo hay datos cargados en el Alta\n\n");
                break;

            case 9:
                //system("cls");
                switch(menuInformes(3, 1, 12))
                {
                    case 1:
                            informar_promedioDelTipoPlastico(pedido, TAM_PEDIDOS);
                        break;

                    case 2:
                            informar_ClienteDeMayorCantPlastico(cliente, TAM_CLIENTE, pedido, TAM_PEDIDOS);
                        break;

                    case 3:
                            //listarTrabajosXAuto(trabajos, CANTTRABAJOS, autos, TAMAUTOS, servicios, CANTSERVICIOS, marcas, CANTMARCAS, colores, CANTCOLORES);
                        break;
                }
                break;

            case 11:
                salir=1;
                break;

            default:
                printf("\n\nError, intentelo mas tarde\n\n");
                break;
        }
    printf("\n");
    //system("pause");
    }while(salir==0);

    return EXIT_SUCCESS;
}

