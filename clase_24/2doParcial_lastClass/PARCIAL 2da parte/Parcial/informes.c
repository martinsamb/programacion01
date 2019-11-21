#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>

#include "clientes.h"
#include "pedidos.h"
#include "validaciones.h"
#include "informes.h"


int menuInformes(int reintentos, int numOpcMin, int numOpcMax)
{
    int opcion;
    int auxOpcion;

    printf("\n -*- MENU DE INFORMES -*-\n\n ");
    printf(" 1. Mostrar promedio de cada tipo de plasticos totales\n ");
    printf(" 2. Mostrar Cliente con mayor cant de plasticos de cada tipo\n ");
    //printf(" 3. Mostrar todos los trabajos X auto seleccionado\n ");
    /*printf(" 4. LISTAR AUTOS\n ");
    printf(" 5. LISTAR MARCAS\n ");
    printf(" 6. LISTAR COLORES\n ");
    printf(" 7. LISTAR SERVICIOS\n ");
    printf(" 8. ALTA TRABAJO\n ");
    printf(" 9. LISTAR TRABAJOS\n ");
    printf(" 10. INFORMES\n ");
    printf(" 11. SALIR del programa\n ");*/

    fflush(stdin);
    if(getNumInt(&auxOpcion, reintentos, numOpcMin, numOpcMax, "\n\nIngrese una opcion: ", "Opcion Incorrecta")==0)
        opcion = auxOpcion;
    else
        opcion = -1;

    return opcion;
}

///PROMEDIO DEL TOTAL DE CADA TIPO DE PLASTICO DE TODOS LOS PEDIDOS
void informar_promedioDelTipoPlastico(ePedido* arrayPedido, int lenPedido)
{
    int i;

    float totalHDPE=0;
    float totalLDPE=0;
    float totalPP=0;

    int cant=0;

    float promedioHDPE;
    float promedioLDPE;
    float promedioPP;

    for(i=0;i<lenPedido;i++)
    {
        if(arrayPedido[i].isEmpty==FALSE && arrayPedido[i].estado==COMPLETADO)
        {
            totalHDPE = totalHDPE + arrayPedido[i].hdpe;
            totalLDPE = totalLDPE + arrayPedido[i].ldpe;
            totalPP = totalPP + arrayPedido[i].pp;
            cant++;
        }
    }

    promedioHDPE = totalHDPE / (float)cant;
    promedioLDPE = totalLDPE / (float)cant;
    promedioPP = totalPP / (float)cant;

    printf("\nPromedio total de Plasticos HDPE: %.2f", promedioHDPE);
    printf("\nPromedio total de Plasticos LDPE: %.2f", promedioLDPE);
    printf("\nPromedio total de Plasticos PP: %.2f\n\n", promedioPP);

}


///CLIENTE CON LA MAYOR CANT DE PLASTICO
void informar_ClienteDeMayorCantPlastico(eCliente* arrayCliente, int lenCliente, ePedido* arrayPedido, int lenPedido)
{
    int indexClienteMayorHDPE;
    int indexClienteMayorLDPE;
    int indexClienteMayorPP;

    int i;
    int j;

    float maxHDPE=0;
    float maxLDPE=0;
    float maxPP=0;

    for(i=0;i<lenPedido;i++)
    {
        if(arrayPedido[i].isEmpty==FALSE && arrayPedido[i].estado==COMPLETADO)
        {
            if(maxHDPE<arrayPedido[i].hdpe)
            {
                maxHDPE = arrayPedido[i].hdpe;
                for(j=0;j<lenCliente;j++)
                {
                    if(arrayCliente[j].isEmpty==FALSE && arrayCliente[j].id==arrayPedido[i].idCliente)
                    {
                        indexClienteMayorHDPE = j;
                        break;
                    }
                }
            }

            if(maxLDPE<arrayPedido[i].ldpe)
            {
                maxLDPE = arrayPedido[i].ldpe;
                for(j=0;j<lenCliente;j++)
                {
                    if(arrayCliente[j].isEmpty==FALSE && arrayCliente[j].id==arrayPedido[i].idCliente)
                    {
                        indexClienteMayorLDPE = j;
                        break;
                    }
                }
            }

            if(maxPP<arrayPedido[i].pp)
            {
                maxPP = arrayPedido[i].pp;
                for(j=0;j<lenCliente;j++)
                {
                    if(arrayCliente[j].isEmpty==FALSE && arrayCliente[j].id==arrayPedido[i].idCliente)
                    {
                        indexClienteMayorPP = j;
                        break;
                    }
                }
            }
        }
    }

    printf("\nMAYOR HDPE: %.2f Kg", maxHDPE);
    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
    printf("--\t------\t\t----\t\t---------\t---------\n");
    print_Cliente(arrayCliente, indexClienteMayorHDPE, lenCliente);

    printf("\nMAYOR LDPE: %.2f Kg", maxLDPE);
    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
    printf("--\t------\t\t----\t\t---------\t---------\n");
    print_Cliente(arrayCliente, indexClienteMayorLDPE, lenCliente);

    printf("\nMAYOR PP: %.2f Kg", maxPP);
    printf("\n\nID\tNOMBRE\t\tCUIT\t\tDireccion\tLocalidad\n");
    printf("--\t------\t\t----\t\t---------\t---------\n");
    print_Cliente(arrayCliente, indexClienteMayorPP, lenCliente);


}

/*void informar_ordenarXAlgo(VentasAfiches* list, int len, int order)
{
    int retorno=-1;
    VentasAfiches auxlist;
    int i,j;
    if(list!=NULL)
    {
        for(i=0; i < len - 1; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                continue;
            }
            for(j=i+1; j < len; j++)
            {
                if(list[j].isEmpty == TRUE)
                {
                    continue;
                }
                if((order==0 && strcmp(list[j].barrioZona, list[i].barrioZona)<0)
                    || (order==1 && strcmp(list[j].barrioZona, list[i].barrioZona) > 0))
                {
                    auxlist = list[j];
                    list[j] = list[i];
                    list[i] = auxlist;
                }
                else if(strcmp(list[j].barrioZona, list[i].barrioZona) == 0)
                {
                    if((order==0 && list[j].nomArchivoImagAfiche < list[i].nomArchivoImagAfiche) || (order==1 && list[j].nomArchivoImagAfiche > list[i].nomArchivoImagAfiche))
                    {
                        auxlist = list[j];
                        list[j] = list[i];
                        list[i] = auxlist;
                    }
                }
            }
        }
    retorno = 0;
    }
    return retorno;
}
*/










