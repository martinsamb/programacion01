#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicidad.h"
#include "pantalla.h"
#include "informes.h"

//​Se pedirá que se ingrese el cuit del cliente y se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos
int Informes_listarPantallasPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0 && cuitBuscado!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayPublicidad[i].isEmpty==1 && strcmp(arrayPublicidad[i].cuit,cuitBuscado)!=0)
                continue;
            else
            {
                Pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID publicidad: %d\nID pantalla: %d\nNombre: %s\nDireccion: %s\nTipo: %s\nPrecio: %.2f",
                       arrayPublicidad[i].idPublicidad,arrayPublicidad[i].idPantalla,arrayPantalla[j].nombre,arrayPantalla[j].direccion,arrayPantalla[j].tipo,arrayPantalla[j].precio);
            }
        }
        retorno=0;
    }
    return retorno;
}

//Se deberá ingresar el cuit del cliente y se deberá listar el importe a​ ​pagar​ ​por​ ​cada​ ​contratación.
int Informes_listarFacturacionPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado)
{
    int retorno=-1;
    int i;
    int j;
    int importe;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0 && cuitBuscado!=NULL)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayPublicidad[i].isEmpty==1 && strcmp(arrayPublicidad[i].cuit,cuitBuscado)!=0)
                continue;
            else
            {
                Pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                importe=(arrayPublicidad[i].dias*arrayPantalla[j].precio);
                printf("\nID publicidad: %d\nID pantalla: %d\nDias: %d\nPrecio: %.2f\nImporte: %d",
                       arrayPublicidad[i].idPublicidad,arrayPublicidad[i].idPantalla,arrayPublicidad[i].dias,arrayPantalla[j].precio,importe);
            }
        }
        retorno=0;
    }
    return retorno;
}

//​Se deberán listar las contrataciones indicando nombre de la pantalla,​ ​nombre​ ​de​ ​video,​ ​cantidad​ ​de​ ​días​ ​y​ ​cuit​ ​de​ ​cliente.
int Informes_listarContrataciones(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayPublicidad[i].isEmpty==1)
                continue;
            else
            {
                Pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                printf("\nID publicidad: %d\nNombre pantalla: %s\nNombre video: %s\nDias: %d\nCuit cliente: %s",
                       arrayPublicidad[i].idPublicidad,arrayPantalla[j].nombre,arrayPublicidad[i].archivo,arrayPublicidad[i].dias,arrayPublicidad[i].cuit);
            }
        }
        retorno=0;
    }
    return retorno;
}


//Lista​ ​de​ ​cada​ ​cliente​ ​con​ ​cantidad​ ​de​ ​contrataciones​ ​e​ ​importe​ ​a​ ​pagar​ ​por​ ​cada​ ​una.
int Informes_listarCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int importe;
    int auxPosicion;
    int contadorContrataciones;

    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            Publicidad_buscarCuit(arrayPublicidad,i-1,arrayPublicidad[i].cuit,&auxPosicion);      //Si ese CUIT ya aparecio > continue
            if(arrayPublicidad[i].isEmpty==1 && auxPosicion!=-1)
                continue;
            else
            {
                printf("\nCUIT: %s",arrayPublicidad[i].cuit);                                   //Imprimo el cuit que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayPublicidad[k].isEmpty!=1 && strcmp(arrayPublicidad[k].cuit,arrayPublicidad[i].cuit)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        contadorContrataciones++;
                        Pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                        importe=(arrayPublicidad[k].dias*arrayPantalla[j].precio);
                        printf("\nID publicidad: %d     Importe: %d",
                               arrayPublicidad[k].idPublicidad,importe);
                    }
                }
                printf("\nCantidad contrataciones: %d",contadorContrataciones);
                contadorContrataciones=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

//Cliente​ ​con​ ​importe​ ​más​ ​alto​ ​a​ ​facturar​ ​(si​ ​hay​ ​más​ ​de​ ​uno​ ​indicar​ ​el​ ​primero)
int Informes_mayorFacturacionPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxFacturacion=0;
    int acumuladorFacturacion=0;
    int iMaxCuit [sizeI];

    if(arrayPublicidad!=NULL && sizeI>=0 && arrayPantalla!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            Publicidad_buscarCuit(arrayPublicidad,i-1,arrayPublicidad[i].cuit,&auxPosicion);      //Si ese CUIT ya aparecio > continue
            if(arrayPublicidad[i].isEmpty==1 && auxPosicion!=-1)
                continue;
            else
            {
                for(k=i;k<sizeI;k++)
                {
                    if(arrayPublicidad[k].isEmpty!=1 && strcmp(arrayPublicidad[k].cuit,arrayPublicidad[i].cuit)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        Pantalla_buscarID(arrayPantalla,sizeJ,arrayPublicidad[i].idPantalla,&j);
                        acumuladorFacturacion+=(arrayPublicidad[k].dias*arrayPantalla[j].precio);
                    }
                }
                if(acumuladorFacturacion>maxFacturacion)
                {
                    maxFacturacion=acumuladorFacturacion;
                    iMaxCuit[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxCuit[i]=i;
                }
                else if(acumuladorFacturacion==maxFacturacion)
                    iMaxCuit[i]=i;
                else
                    iMaxCuit[i]=-2;                         //Para marcar los lugares vacios

                acumuladorFacturacion=0;
            }
        }

        printf("\nMayor facturacion: %d \nCuit clientes con mayor facturacion: ",maxFacturacion);
        for(;i!=-1;i--)
        {
            if(iMaxCuit[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayPublicidad[iMaxCuit[i]].cuit);
            }
        }

        retorno=0;
    }
    return retorno;

}




//Clase 11

//Ordenar pantallas por precio, ante igualdad de precio ordenar por nombre
/*
int Informes_ordenarPorPrecio(Pantalla* array, int size)
{
    int j;
    int flag;
    Pantalla buffer;

    do
    {
        flag=0;
        for(j=0;j<size-1;j++)
        {

            if(pPantalla[j].precio<pPantalla[j+1].precio)
            {
                //swap
                flag=1;
            }
            else if(pPantalla[j].precio==pPantalla[j+1].precio)
            {
                if(strncmp(pPantalla[j].nombre,pPantalla[j+1].nombre,50)>0)
                {
                    //swap  armar una funcion swap
                    flag=1;
                } //Mejoras: continue si alguno de los dos elementos esta empty
            }
        }
    }
}
*/

//F Todas las contrataciones cuya cantidad de dias es menor o igual a 10, indicando nombre de la pantalla contratada, precio unitario, dias y precio total de la contratacion

int Informes_listarPorDias(Publicidad arrayA[], Pantalla arrayB[], int sizePublicidad, int sizePantalla)
{
    int retorno=-1;
    int j;
    int i;
    int precioTotal;

    for(i=0;i<sizePublicidad;i++)
    {
        if(arrayA[i].dias<=10)
        {

            Pantalla_buscarID(arrayB,sizePantalla,arrayA[i].idPantalla,&j);
            precioTotal=arrayA[i].dias*arrayB[j].precio;

            printf("\nNombre: %s \nPrecio: %.2f \nDias: %d, \nPrecioTotal: %d",
                    arrayB[j].nombre,arrayB[j].precio,arrayA[i].dias,precioTotal);
            //El cliente puede contratar una pantalla una unica vez
        }

    }

    return retorno;
}

//H. La o las pantallas con mas contrataciones
int Informes_masContrataciones(Pantalla arrayPantalla[], Publicidad arrayPublicidad[], int sizePantalla, int sizePublicidad)
{
    int retorno=-1;
    int i;
    int j;
    int contadorAnterior=0;
    int contador;
    int iMayor[sizePublicidad];

    for(i=0;i<sizePantalla;i++)
    {
        for(j=0;j<sizePublicidad;j++)
        {
            if(arrayPublicidad[j].idPantalla==arrayPantalla[i].idPantalla)
                contador++;
        }
        if(contador>contadorAnterior)
        {
            contadorAnterior=contador;
            iMayor[i-1]=-1;
            iMayor[i]=i;
        }
        else if(contador==contadorAnterior)
            iMayor[i]=i;
    }

    printf("\nMayor cantidad de contrataciones: %d \nPantallas: ",contadorAnterior);
    for(;i!=-1;i--)
    {
        printf("\n ID: %d",arrayPantalla[i].idPantalla);
    }

    return retorno;
}

//I. La o las pantallas con mas clientes
int Informes_masClientes(Pantalla arrayPantalla, Publicidad arrayPublicidad, int sizePantalla, int sizePublicidad)
{
    int retorno=-1;
    int i;
    int j;
    int contadorAnterior=0;
    int contadorCuit;
    int iMayor[sizePublicidad];

    for(i=0;i<sizePantalla,i++)
    {
        for(j=0;j<sizePublicidad,j++)
        {
            if(Publicidad[j].idPantalla==Pantalla[i].idPantalla)
                contador++;
        }
        if(contador>contadorAnterior)
        {
            contadorAnterior=contador;
            iMayor[i-1]=-1;
            iMayor[i]=i;
        }
        else if(contador==contadorAnterior)
            iMayor[i]=i;
    }

    printf("\nMayor cantidad de contrataciones: %d \nPantallas: ",contadorAnterior);
    for(;i!=-1;i--)
    {
        printf("\n ID: %d",Pantalla[i].idPantalla);
    }

    return retorno;
}

//H. La o las pantallas mas ha facturado
int Informes_mayorFacturacion(Pantalla arrayPantalla, Publicidad arrayPublicidad, int sizePantalla, int sizePublicidad)
{
    int retorno=-1;
    int i;
    int j;
    int acumuladoAnterior=0;
    int acumulado=0;
    int iMayor[sizePublicidad];

    for(i=0;i<sizePantalla,i++)
    {
        for(j=0;j<sizePublicidad,j++)
        {
            if(Publicidad[j].idPantalla==Pantalla[i].idPantalla)
            {
                acumulado+=(Publicidad[j].dias*Pantalla[i].precio);
            }
        }
        if(acumulado>acumuladoAnterior)
        {
            acumuladoAnterior=acumulado;
            iMayor[i-1]=-1;
            iMayor[i]=i;
        }
        else if(acumulado==acumuladoAnterior)
            iMayor[i]=i;
    }

    printf("\nMayor facturacion: %d \nPantallas: ",acumuladoAnterior);
    for(;i!=-1;i--)
    {
        printf("\n ID: %d",Pantalla[i].idPantalla);
    }

    return retorno;
}

/*
G.  Listado de clientes en el cual se indique la cantidad de contrataciones que ha realizado y por que importe. Ordenado por los siguientes
    criterios:
        -Importe(descendentemente)
        -Cuit(ascendentemente)
Armar un array de clientes/cuits, aunque sea temporal, cada cuit tiene que aparecer una sola vez
    Recorrer el array de clientes
    contador ++ y acumulador facturacion cada vez que aparece en el array contrataciones
*/
int Informes_listarClientesContadorAcumulado(Publicidad arrayA[], Pantalla arrayB[], int sizeI, int sizeJ)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Cliente arrayAux[sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            Publicidad_buscarCuit(arrayA,i,arrayA[i].cuit,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].cuit,arrayA[i].cuit)
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].cuit,arrayA[i].cuit)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        Pantalla_buscarID(arrayB,sizeJ,arrayA[k].idEntidad,&j);                 //cambiar Tipo, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].dias*arrayB[j].precio);
                    }
                }
                arrayAux[i].contrataciones=contador;
                arrayAux[i].importeTotal=acumulado;
                arrayAux[i].isEmpty=0;
                contador=0;
                acumulado=0;
            }
        }

        ordenarAuxiliar(arrayAux,sizeI);
        //listarAuxiliar

        retorno=0;
    }
    return retorno;
}

int ordenarAuxiliar(Cliente array[], int size)
{
    int retorno=-1;
    int i, j;
    char bufferCuit[TEXT_SIZE];
    int bufferIsEmpty;
    int bufferImporte;
    int bufferContrataciones;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferCuit,array[i].cuit);                      //cambiar campo varString
            bufferIsEmpty=array[i].isEmpty;
            bufferImporte=array[i].importeTotal;
            bufferContrataciones=array[i].contrataciones;

            j = i - 1;
            while ((j >= 0) && (bufferImporte>array[j].importeTotal || (bufferImporte==array[j].importeTotal && strcmp(bufferCuit,array[j].cuit)<0)))         //cambiar campo varString      //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].cuit,array[j].cuit);          //cambiar campo varString
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].importeTotal=array[j].importeTotal;                        //cambiar campo varInt
                array[j + 1].contrataciones=array[j].contrataciones;                    //cambiar campo varFloat

                j--;
            }
            strcpy(array[j + 1].cuit,bufferCuit);                     //cambiar campo varString
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].importeTotal=bufferImporte;                                                        //cambiar campo varInt
            array[j + 1].contrataciones=bufferContrataciones;                                                    //cambiar campo varFloat
        }
        retorno=0;
    }
    return retorno;
}






