#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

//********************************INFORMES*****************************************
// 1 *************************Listar Orquesta de lugar*****************************

/** \brief Listar orquesta de un lugar , ingresando por usuario,imprimir,IR, orquesta,nombre,ripo y lugar
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int listar_orquesta_deLugar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    int flag = -1;
    char criterio[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        if(utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,criterio)== 0)
        {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty!=1 && strcmp(array[i].lugar,criterio)==0)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                    array[i].idUnico,array[i].nombre,array[i].lugar);
                    if(array[i].tipo==1)
                        printf("Sinfonica");
                    else if(array[i].tipo==2)
                        printf("Filarmonica");
                    else if(array[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");
                        flag = 0;
                }
            }
            if(flag ==-1)
                printf("\nNo se han encontrado orquestas para el lugar indicado");
        }
        retorno = 0;
    }
    return retorno;
}

// 2 *****************listar_musicos_menores*******************************

/** \brief Listar los musicos menores de 25 años, mostrar ID, nombre,apellido,edad,instrumento, orquesta
* \param arrayM Musico Array de Musico
* \param arrayO Orquesta Array de Orquesta
* \param arrayI Instrumento Array de Instrumento
* \param sizeM int Tamaño del arrayM
* \param sizeO int Tamaño del arrayO
* \param sizeI int Tamaño del arrayI
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int listar_musico_menores(Musico arrayM[], Orquesta arrayO[], Instrumento arrayI[], int sizeM, int sizeO, int sizeI)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int flag = -1;
    if(arrayM!=NULL && sizeM>=0 && arrayO!=NULL && sizeO>=0 && arrayI!=NULL && sizeI>=0)
    {
        printf("\nMusicos con menos de 25 años:");
        for(i=0;i<sizeM;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayM[i].isEmpty!=1 && arrayM[i].edad<25)
            {
                if(orquesta_buscarID(arrayO,sizeO,arrayM[i].idOrquesta,&j)== -1)
                    j = -1;
                    if(instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&k)== -1)
                        k = -1;
                        printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d",
                       arrayM[i].idUnico,
                       arrayM[i].nombre,
                       arrayM[i].apellido,
                       arrayM[i].edad);
                    if(k == -1)
                        printf("Instrumento desconocido");
                    else
                        printf("Nombre del instrumento: %s",arrayI[k].nombre);
                    if(j == -1)
                        printf("Orquesta desconocida");
                    else
                        printf("Nombre orquesta: %s",arrayO[j].nombre);
                    flag = 0;
            }
        }
        if(flag == -1)
            printf("\nNo se encontraron musicos menores de 25");
        retorno=0;
    }
    return retorno;
}
// 3 *******************************listar_orquestas_menosMusico**********************************************
//********Listar orquestas con menos de 6 musicos, imprime ID orquesta, nombre, tipo y lugar******************
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayO Orquesta Array de Orquesta
* \param arrayM Musico Array de Musico
* \param sizeO int Tamaño del arrayO
* \param sizeM int Tamaño del arrayM
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int listar_orquesta_menosMusico(Orquesta arrayO[], Musico arrayM[], int sizeO, int sizeM)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int flag=-1;
    if(arrayO!=NULL && sizeO>=0 && arrayM!=NULL && sizeM>=0)
    {
        printf("\nOrquestas con menos de 6 musicos:");
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty!=1)
            {
                for(j=0,contador=0;j<sizeM;j++)
                {
                    if(arrayM[j].isEmpty!=1 && arrayO[i].idUnico==arrayM[j].idOrquesta)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }
                if (contador<6)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayO[i].idUnico,arrayO[i].nombre,arrayO[i].lugar);
                    if(arrayO[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayO[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayO[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");
                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron orquestas con menos de 6 musicos");
        retorno=0;
    }
    return retorno;
}
// 4 *************listar_instrumento_orquesta*************************
/** \brief Selecita un ID de orquesta y lista sus Instrumentos
* \param arrayM Musico Array de Musico
* \param arrayI Instrumento Array de Instrumento
* \param sizeM int Tamaño del arrayM
* \param sizeI int Tamaño del arrayI
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_instrumento_orquesta(Musico arrayM[], Instrumento arrayI[], int sizeM, int sizeI)
{
    int retorno=-1;
    int i;
    int j;
    int criterio;
    int flag=-1;
    if(arrayM!=NULL && sizeM>=0 && arrayI!=NULL && sizeI>=0)
    {
        if(utn_getUnsignedInt("\nID orquesta: ","\nError",1,sizeof(int),1,&criterio)==0)
        {
            printf("\nInstrumentos de la orquesta:");
            for(i=0;i<sizeM;i++)
            {
                if(arrayM[i].isEmpty!=1 && arrayM[i].idOrquesta==criterio)
                {
                    if(instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&j)==0)
                    {
                        printf("\nNombre: %s  Tipo: ",arrayI[j].nombre);
                        if(arrayI[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayI[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayI[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayI[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");
                    }
                    else
                        printf("\nTipo de instrumento desconocido");

                    printf("  Nombre musico: %s",arrayM[i].nombre);
                    flag=0;
                }
            }
            if(flag==-1)
                printf("\nLa orquesta no tiene instrumentos ingresados");
        }
        retorno=0;
    }
    return retorno;
}


//  5  *********************************listar_orquesta_completa**********************************************
/** \brief Listar las orquestas completas de acuerdo a la cantidad de instrumentos
* \param arrayO Orquesta Array de Orquesta
* \param arrayM Musico Array de Musico
* \param arrayI Instrumento Array de Instrumento
* \param sizeO int Tamaño del arrayO
* \param sizeM int Tamaño del arrayM
* \param sizeI int Tamaño del arrayI
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_orquesta_completa(Orquesta arrayO[], Musico arrayM[], Instrumento arrayI[], int sizeO, int sizeM, int sizeI)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPercusion=0;
    int flag=-1;
    if(arrayO!=NULL && sizeO>=0 && arrayM!=NULL && sizeM>=0 && arrayI!=NULL && sizeI>=0)
    {
        printf("\nOrquestas completas:");
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty!=1)
            {
                for(j=0,contadorCuerda=0, contadorViento=0, contadorPercusion=0;j<sizeM;j++)
                {
                    if(arrayM[j].isEmpty!=1 && arrayO[i].idUnico==arrayM[j].idOrquesta)     //Busco todas las veces que aparece ese id
                    {
                        instrumento_buscarID(arrayI,sizeI,arrayM[j].idInstrumento,&k);
                        if(arrayI[k].tipo==1)
                            contadorCuerda++;
                        else if(arrayI[k].tipo==2 || arrayI[k].tipo==3)
                            contadorViento++;
                        else if(arrayI[k].tipo==4)
                            contadorPercusion++;
                    }
                }
                if (contadorCuerda>=4 && contadorViento>=4 && contadorPercusion>=1)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayO[i].idUnico,
                           arrayO[i].nombre,
                           arrayO[i].lugar);
                    if(arrayO[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayO[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayO[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");

                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron orquestas completas");
        retorno=0;
    }
    return retorno;
}

// 6  ***************************imprimir_orquesta_menores********************************
/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayO Orquesta Array de Orquesta
* \param arrayM Musico Array de Musico
* \param sizeO int Tamaño del arrayO
* \param sizeM int Tamaño del arrayM
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int imprimir_orquesta_menores(Orquesta arrayO[], Musico arrayM[], int sizeO, int sizeM)
{
    int retorno=-1;
    int i;
    int j;
    int minContador=0;
    int contador=0;
    int iMin[sizeO];

    if(arrayO!=NULL && sizeO>=0 && arrayM!=NULL && sizeM>=0)
    {
        for(i=0;i<sizeO;i++)
        {
            iMin[i]=-2;                        //Para marcar los lugares vacios
            if(arrayO[i].isEmpty!=1)
            {
                for(j=0,contador=0;j<sizeM;j++)
                {
                    if(arrayM[j].isEmpty!=1 && arrayO[i].idUnico==arrayM[j].idOrquesta)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }

                if(i==0)
                    minContador=contador;
                else if(contador<minContador)
                {
                    minContador=contador;
                    iMin[i-1]=-1;
                    iMin[i]=i;
                }
                else if(contador==minContador)
                    iMin[i]=i;
            }
        }

        printf("\nMenor cantidad de musicos: %d \nOrquestas: ",minContador);
        for(i--;iMin[i]!=-1 && i>=0;i--)
        {
            if(iMin[i]!=-2)                         //Salteo los vacios
            {
                printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       arrayO[iMin[i]].idUnico,
                       arrayO[iMin[i]].nombre,
                       arrayO[iMin[i]].lugar);
                if(arrayO[iMin[i]].tipo==1)
                    printf("Sinfonica");
                else if(arrayO[iMin[i]].tipo==2)
                    printf("Filarmonica");
                else if(arrayO[iMin[i]].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//  7  **********************************imprimir_promedio_musico********************************************
/** \brief Imprimir el promedio de instrumentos por orquesta
* \param arrayO Orquesta Array de Orquesta
* \param arrayM Musico Array de Musico
* \param sizeO int Tamaño del arrayO
* \param sizeM int Tamaño del arrayM
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int imprimir_promedio_musico(Orquesta arrayO[], Instrumento arrayI[], int sizeO, int sizeI)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int contadorOrquesta=0;
    int contadorInstrumento=0;
    int promedio;

    if(arrayO!=NULL && sizeO>=0 && arrayI!=NULL && sizeI>=0)
    {
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty!=1)
                contadorOrquesta++;
        }
        for(i=0;i<sizeI;i++)
        {
            if(arrayI[i].isEmpty!=1)
                contadorInstrumento++;
        }

        promedio=contadorInstrumento/contadorOrquesta;

        printf("\nPromedio de instrumentos por orquesta: %d",promedio);
        retorno=0;
    }
    return retorno;
}


// 8  *************************listar_musico_instrumentoViento***************************************
/** \brief Lista los musicos excepto aquellos qe toquen instrumento de viento, ordenados por apellido
* \param arrayM Musico Array de Musico
* \param arrayI Instrumento Array de Instrumento
* \param sizeM int Tamaño del arrayM
* \param sizeI int Tamaño del arrayI
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int listar_musico_instrumentoViento(Musico arrayM[], Instrumento arrayI[], int sizeM, int sizeI)
{
    int retorno=-1;
    int i;
    int j;
    int flag=-1;
    if(arrayM!=NULL && sizeM>=0 && arrayI!=NULL && sizeI>=0)
    {
        musico_ordenarPorApellido(arrayM,sizeM);
        for(i=0;i<sizeM;i++)                                  // posicion de musico
        {
            if(arrayM[i].isEmpty!=1)
            {
                if(instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&j)==-1)      //Obtengo la posicion de Instrumento buscando por el campo en comun
                    j=-1;
                if(arrayI[j].tipo!=2 && arrayI[j].tipo!=3)
                {
                    printf("\nNombre: %s  Apellido: %s    Edad: %d    ",
                           arrayM[i].nombre,
                           arrayM[i].apellido,
                           arrayM[i].edad);
                    if(j==-1)
                        printf("    ID instrumento desconocido");
                    else
                    {
                        printf("     Nombre instrumento: %s     Tipo instrumento: ",arrayI[j].nombre);
                        if(arrayI[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayI[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayI[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayI[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");
                    }
                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron musicos de instrumentos que no sean de viento");
        retorno=0;
    }
    return retorno;
}

//***************************AMB**************************************

//*******************listar musicos***********************************
/** \brief Lista los elementos de dos arrays vinculados
* \param arrayM Musico Array de Musico
* \param arrayI Instrumento Array de Instrumento
* \param sizeM int Tamaño del arrayM
* \param sizeI int Tamaño del arrayI
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarMusico(Musico arrayM[], Instrumento arrayI[], int sizeM, int sizeI)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayM!=NULL && sizeM>=0 && arrayI!=NULL && sizeI>=0)
    {
        for(i=0;i<sizeM;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayM[i].isEmpty!=1)
            {
                instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&j);                           //Obtengo la posicion de la 2da entidad buscando por el campo en comun


                printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d    Nombre instrumento: %s     Tipo instrumento: ",
                       arrayM[i].idUnico,arrayM[i].nombre,arrayM[i].apellido,arrayM[i].edad,arrayI[j].nombre);
                if(arrayI[j].tipo==1)
                    printf("Cuerdas");
                else if(arrayI[j].tipo==2)
                    printf("Viento-madera");
                else if(arrayI[j].tipo==3)
                    printf("Viento-metal");
                else if(arrayI[j].tipo==4)
                    printf("Percusion");
                else
                    printf("Desconocido");

            }
        }
        retorno=0;
    }
    return retorno;
}
