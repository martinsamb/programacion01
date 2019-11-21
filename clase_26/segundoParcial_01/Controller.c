#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entregas.h"
#include "Parser.h"
#include "utn.h"

int controller_cantidadEntregada(LinkedList* pArrayListEntrega)
{
     Entrega* pAux;
     int length;
     int contadorCantidad = 0;
     int cantidadActual;
     int i;
     if(pArrayListEntrega != NULL)
     {
         length = ll_len(pArrayListEntrega);
         for(i=0;i<length;i++)
         {
             pAux= ll_get(pArrayListEntrega,i);
             if(!entrega_getCantidad(pAux, &cantidadActual))
             {
                 contadorCantidad += cantidadActual;
             }
         }
     }
    return contadorCantidad;
}
int controller_importeEntregado(LinkedList* pArrayListEntrega)
{
    Entrega* pAux;
    int length;
    int contadorCantidad = 0;
    int cantidadActual;
    int i;
    if(pArrayListEntrega != NULL)
    {
        length = ll_len(pArrayListEntrega);
        for(i=0;i<length;i++)
        {
            pAux = ll_get(pArrayListEntrega,i);
            if(!entrega_getCantidad(pAux, &cantidadActual))
            {
                contadorCantidad += cantidadActual;
            }
        }
    }
    return contadorCantidad;
}
int controller_loadFromText(char* path, LinkedList* pArrayListEntrega)
{
    int retorno =-1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(path != NULL && pArrayListEntrega != NULL)
        {
            if(!parser_EntregaFromText(pFile,pArrayListEntrega))
            {
                printf("\nCarga exitosa");
                fclose(pFile);
                retorno = 0;
            }
        }
    }
    return retorno;

}
/** \brief Guarda los datos de las entregas en el archivo informe.txt(Modo texto)
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* registro)
{
    int retorno = -1;
    int cantidadDeEntregas;
    int cantidadDeBultos=0;
    int totalRegular, totalPlus, totalGold;
    float promedioDeBultos = 0;
    float importeTotal= 0;
    float promedioDeImporte = 0;
    LinkedList* registroGold = ll_newLinkedList();
    LinkedList* registroPlus = ll_newLinkedList();
    LinkedList* registroRegular = ll_newLinkedList();

    FILE* pFile = NULL;
    if(path != NULL && registro != NULL)
    {
        pFile=fopen(path,"w");
        if(pFile != NULL)
        {
            //Cantidad total de entregas
            registroGold = ll_filter(registro, entrega_filtrarGold);
            registroPlus = ll_filter(registro, entrega_filtrarPlus);
            registroRegular = ll_filter(registro, entrega_filtrarRegular);
            totalGold = ll_len(registroGold);
            totalPlus = ll_len(registroPlus);
            totalRegular = ll_len(registroRegular);

            //Cantidad y promedio de bultos
            cantidadDeBultos = controller_cantidadEntregada(registro);
            promedioDeBultos = (float)cantidadDeBultos/cantidadDeEntregas;

            //Importe promedio
            importeTotal = controller_importeEntregado(registro);
            promedioDeImporte = importeTotal / cantidadDeEntregas;

            //carga de archivo

            fprintf(pFile,"--------------------Informe de Ventas----------------------------------\n");
            fprintf(pFile,"- Cantidad total de Entregas: %d\n", cantidadDeEntregas);
            fprintf(pFile, "- Cantidad de entregas por Tipo: %d (GOLD) - %d (PLUS) - %d(REGULAR)\n",totalGold, totalPlus, totalRegular);
            fprintf(pFile,"Cantidad Total de Bultos Entregados: %d\n",cantidadDeBultos);
            fprintf(pFile,"Promedio de Bultos por entrega: %.2f\n",promedioDeBultos);
            fprintf(pFile,"Importe promedio por Entrega: %.2f\n", promedioDeImporte);
            fprintf(pFile,"-------------------------------------------------------------------------");
            retorno = 0;
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("\nInforme generado exitosamente");
    }

    return retorno;
}
