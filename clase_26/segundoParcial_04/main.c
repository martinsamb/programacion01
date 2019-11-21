#include <stdio.h>
#include <stdlib.h>
#include "Llamada.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "utn.h"

int main()
{
    LinkedList* listaLlamadas = ll_newLinkedList();
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
            auxInt = utn_getInter("1-Cargar Archivo\n2-Imprimir\n3-Generar archivo de salida\n4-Salir\n","ERROR\n",0,5,3,auxiliar);
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
                    if(controller_loadFromText(archivo,listaLlamadas))
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
                if(ll_len(listaLlamadas)>0)
                {
                    controller_imprimirLlamadas(listaLlamadas);
                }
                else
                {
                    printf("ingrese primero la opcion 1\n");
                }
                break;
            case 3:
                if(ll_len(listaLlamadas)>0)
                {
                    problema = controller_numeroProblema();
                    switch(problema)
                    {
                        case 1:
                            listaDepurada = ll_filter(listaLlamadas,problema1);
                            controller_writeText("depurado.csv",listaDepurada);
                            break;
                        case 2:
                            listaDepurada = ll_filter(listaLlamadas,problema2);
                            controller_writeText("depurado.csv",listaDepurada);
                            break;
                        case 3:
                            listaDepurada = ll_filter(listaLlamadas,problema3);
                            controller_writeText("depurado.csv",listaDepurada);
                            break;
                        case 4:
                            listaDepurada = ll_filter(listaLlamadas,problema4);
                            controller_writeText("depurado.csv",listaDepurada);
                            break;
                        case 5:
                            listaDepurada = ll_filter(listaLlamadas,problema5);
                            controller_writeText("depurado.csv",listaDepurada);
                            break;
                        default:
                            printf("La opcion ingresada no es valida\n");
                            break;
                    }
                }
                else
                {
                    printf("Ingrese primero la opcion 1\n");
                }
                break;
        }
        utn_pauseClean();
    }
    while(option != 4);
    ll_deleteLinkedList(listaLlamadas);
    return 0;
}
