#include <stdio.h>
#include <stdlib.h>
#include "Cachorro.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "utn.h"

int main()
{
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaDepurada;
    int flag = 0;
    char auxiliar[10];
    int auxInt;
    int option;
    int problema;
    char archivo[20];
    do
    {
        do
        {
            auxInt = utn_getInter("1-Cargar Archivo\n2-Imprimir lista\n3-Filtrar menores de 45 dias\n4-Filtrar machos\n5-Generar listado de callejeros\n4-Salir\n","ERROR\n",0,5,3,auxiliar);
            utn_clean();
        }
        while(auxInt != 0);
            option = atoi(auxiliar);

        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    printf("Ingrese nombre del archivo:");
                    //fpurge(stdin);
                    fflush(stdin);
                    scanf("%s",archivo);
                    if(controller_loadFromText(archivo,listaCachorros))
                    {
                        printf("La lista se cargo de manera efectiva\n");
                    }
                    else
                    {
                        printf("El nombre del archivo no es valido\n");
                        option = 4;
                    }
                }
                else
                {
                    printf("No puede volver a ingresar la opcion 1\n");
                }
                break;
            case 2:
                if(ll_len(listaCachorros)>0)
                {
                    controller_imprimirCachorros(listaCachorros);
                }
                else
                {
                    printf("ingrese primero la opcion 1\n");
                }
                break;
            /*
            case 3:
                if(ll_len(listaCachorros)>0)
                {
                    listaDepurada = ll_filter(listaCachorros,);
                    controller_writeText("depurado.csv",cahorro_menores45);
                }
                break;
            case 4:
                if(ll_len(listaCachorros)>0)
                {
                    listaDepurada = ll_filter(listaCachorros,);
                    controller_writeText("depurado.csv",cahorro_filtrarMachos);
                }
                break;


            case 5:
                if(ll_len(listaCachorros)>0)
                {
                    listaDepurada = ll_filter(listaCachorros,);
                    controller_writeText("depurado.csv",cahorro_menores45);
                }
                break;

            case 6:
                if(ll_len(listaCachorros)>0)
                {
                    listaDepurada = ll_filter(listaCachorros,);
                    controller_writeText("depurado.csv",cahorro_listaCallejeros);
                }
                break;
              */
        }
        utn_pauseClean();
    }
    while(option != 3);
    ll_deleteLinkedList(listaCachorros);
    return 0;
}
