/*
 * clientes.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */


#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"
#include "clientes.h"



int menuConOpcion(int reintentos, int numOpcMin, int numOpcMax)
{
    int opcion;
    int auxOpcion;

    printf("\n -*- MENU DE OPCIONES -*-\n\n");
    printf(" 1. ALTA CLIENTE\n");
    printf(" 2. MODIFICAR CLIENTE\n");
    printf(" 3. ELIMINAR CLIENTE\n");
    printf(" 4. CREAR PEDIDOS\n");
    printf(" 5. PROCESAR RESIDUOS\n");
    printf(" 6. IMPRIMIR CLIENTES\n");
    printf(" 7. IMPRIMIR PEDIDOS PENDIENTES\n");
    printf(" 8. IMPRIMIR PEDIDOS PROCESADOS\n");
    printf(" 9. MENU DE INFORMES\n ");
    printf("11. SALIR del programa\n ");

    //__fpurge(stdin);
    fflush(stdin);
    if(getNumInt(&auxOpcion, reintentos, numOpcMin, numOpcMax, "\n\nIngrese una opcion: ", "Opcion Incorrecta")==0)
        opcion = auxOpcion;
    else
        opcion = -1;

    return opcion;
}

int inicializar_Cliente(eCliente* list, int len)
{
    int i;
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = TRUE;
        }
        retorno=0;
    }
    return retorno;
}

int hardcodear_Cliente(eCliente* list)
{
    eCliente auxlist[]=
    {
       {1, "MANAOS", "30-11111111-1", "Manaos 111", "Lanus", FALSE},
       {2, "ARCOR", "30-22222222-2", "Arcor 222", "Olivos", FALSE},
       {3, "SAMSUNG", "30-33333333-3", "Samsung 333", "Corea", FALSE},
       {4, "SONY", "30-44444444-4", "Sony 444", "CABA", FALSE},
       {5, "TOYOTA", "30-55555555-5", "Toyota 555", "Zarate", FALSE},
       {6, "QUERUBIN", "30-66666666-6", "Querubin 666", "Mataderos", FALSE},
    };

    for(int i=0; i<6; i++)
    {
        if(auxlist[i].isEmpty==FALSE)
            list[i] = auxlist[i];
    }
    return 0;
}

int buscarIndexVacio_Cliente(eCliente* list, int len)
{
    int retorno=-1;
    int index;
    if(list!=NULL && len>0)
    {
        for(index=0;index<len;index++)
        {
            if(list[index].isEmpty==TRUE)
            {
                retorno = index;
                break;
            }
        }
    }
    return retorno;
}

int alta_Cliente(eCliente* list, int len, int id)
{
    int retorno=-1;
    int index;
    eCliente auxList;

    index = buscarIndexVacio_Cliente(list, len);
    if(list!=NULL && index>=0 && index<len)
    {
        if(getString(auxList.nombreEmpresa, TAM_CLIENTE , 3, "\nEscriba el nombre de la empresa: ", "Error, intente nuevamente\n") == 0
        && getCuit(auxList.cuit, TAM_CUIT, 3, "\nEscriba el CUIT (con guiones): ", "Error, intente nuevamente\n") == 0
		&& getStringAlfaNum(auxList.direccion, TAM_PALABRAS, 3, "\nEscriba la direccion: ", "Error, intente nuevamente\n") == 0
		&& getString(auxList.localidad, TAM_PALABRAS, 3, "\nEscriba la Localidad: ", "Error, intente nuevamente\n") == 0)
        {
            list[index] = auxList;
            list[index].id = id;
            list[index].isEmpty = FALSE;
            retorno = 0;
        }
    }
    else
    {
        printf("\n\nNo hay mas espacio para guardar Clientes");
    }
    return retorno;
}


int buscar_ClienteById(eCliente* list, int id, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE && list[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro el ID\n");
    }
    return retorno;
}

int print_Cliente(eCliente* list, int index, int len)
{
    int retorno=-1;
    //char descripcion[20];
    if(list!=NULL && index<len)
    {
        //cargarDescripcionCliente(list[index].tipo, descripcion);
        printf("%d      %-14s%10s  \t%s  \t%s\n",list[index].id, list[index].nombreEmpresa, list[index].cuit, list[index].direccion, list[index].localidad);
        retorno=0;
    }
    else
    {
        printf("Error al imprimir los datos del cliente \n");
    }
    return retorno;
}

void listar_Cliente(eCliente* list, int len)
{
    int i;

    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
    printf("--\t------\t\t----\t\t---------\t---------\n");
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            print_Cliente(list,i,len);
        }
    }
}

int editar_Cliente(eCliente* list, int len)
{
    int retorno=-1;
    int index;
    int id;
    int opcion;
    int salir=0;
    eCliente auxList;

    listar_Cliente(list, len);
    if(getNumInt(&id, 3, 0, TAM_CLIENTE, "\n** MODIFICACION DE DATOS **\n\nIngrese el ID: \n", "ERRROR")==0)
       {
           index = buscar_ClienteById(list, id, len);
           if(list!=NULL && index>=0 && index<len)
           {
               do{
                    //system("cls");
            	    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
                    printf("--\t------\t\t----\t\t---------\t---------\n");
                    print_Cliente(list, index, len);

                    printf("\nQue desea modificar?:\n\n ");
                    printf(" 1. DIRECCION\n ");
                    printf(" 2. LOCALIDAD\n ");
                    printf(" 3. SALIR\n ");

                    if(getNumInt(&opcion, 3, 1, 3, "\nElija una opcion: ", "\nOpcion Incorrecta\n")==0)
                    {
                        switch(opcion)
                        {
                            case 1:
                                if(getString(auxList.direccion, TAM_PALABRAS , 3, "\nEscriba la direccion: ", "Error, intente nuevamente\n") == 0)
                                {
                                    strcpy(list[index].direccion, auxList.direccion);
                                    retorno = 0;
                                }
                                break;

                            case 2:
                                if(getString(auxList.localidad, TAM_PALABRAS , 3, "\nEscriba la localidad: ", "Error, intente nuevamente\n") == 0)
                                {
                                    strcpy(list[index].localidad, auxList.localidad);
                                    retorno = 0;
                                }
                                break;

                            case 3:
                                salir = 1;
                                retorno = 0;
                                break;

                            default:
                                printf("NO EXISTE LA OPCION, Intente nuevamente");
                        }
                    }
                    else
                       printf("NO EXISTE LA OPCION, Intente nuevamente");
                    if(retorno==0)
                        printf("\n--MODIFICACION EXITOSA--\n\n");

                    //system("pause");
                }while(salir==0);
            }
    }
    return retorno;
}

int baja_Cliente(eCliente* list, int len)
{
    int retorno=-1;
    int index;
    int id;
    int opcion;

    listar_Cliente(list, len);
    if(getNumInt(&id, 3, 0, TAM_CLIENTE, "\n** BAJA DE CLIENTE **\n\nIngrese el ID: \n", "ERRROR")==0)
    {
        index = buscar_ClienteById(list, id, len);
        if(index!=-1)
        {
            printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
            printf("--\t------\t\t----\t\t---------\t---------\n");
        	print_Cliente(list, index, len);

        	printf("\nConfirmar borrado?: \n\n ");
        	printf(" 1. SI\n ");
        	printf(" 2. NO\n ");
        	if(getNumInt(&opcion, 2, 1, 2, "\nElija una opcion: ", "Error\n")==0 && opcion==1)
        	{
        		list[index].isEmpty=TRUE;
        		printf("\n--BAJA EXITOSA--\n\n");
        		retorno=0;
        	}
        }
    }
    return retorno;
}

