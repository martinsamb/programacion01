#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#include "informes.h"

#define CANTIDAD_ORQUESTA 50  //50
#define CANTIDAD_INSTRUMENTO 20  //20
#define CANTIDAD_MUSICO 100  //100

int cargarDatos(Instrumento arrayInstrumento[], Musico arrayMusico[], Orquesta arrayOrquesta[], int *contadorIdOrquesta, int *contadorIdInstrumento, int *contadorIdMusico);

int main()
{
    int opcion;
    int opcionI;

    int contadorIdOrquesta=1;
    int flagOrquesta=0;
    Orquesta arrayOrquesta[CANTIDAD_ORQUESTA];
    orquesta_inicializar(arrayOrquesta,CANTIDAD_ORQUESTA);

    int contadorIdInstrumento=1;
    int flagMusico=0;
    Instrumento arrayInstrumento[CANTIDAD_INSTRUMENTO];
    instrumento_inicializar(arrayInstrumento,CANTIDAD_INSTRUMENTO);

    int contadorIdMusico=1;
    int flagInstrumento=0;
    Musico arrayMusico[CANTIDAD_MUSICO];
    musico_inicializar(arrayMusico,CANTIDAD_MUSICO);

    cargarDatos(arrayInstrumento, arrayMusico, arrayOrquesta, &contadorIdOrquesta, &contadorIdInstrumento, &contadorIdMusico);
    do
    {
        menuPrincipal();
        utn_getUnsignedInt("","\nError",1,sizeof(int),1,&opcion);
        switch(opcion)
        {
             case 1://alta orquests
                if(orquesta_alta(arrayOrquesta,CANTIDAD_ORQUESTA,&contadorIdOrquesta)== 0)
                flagOrquesta = 1;
                break;
            case 2://baja orquesta
                if(flagOrquesta == 0)
                {
                    printf("\nNo se ha dado de alta ninguna Orquestas");
                }
                else
                    orquesta_baja(arrayOrquesta,CANTIDAD_ORQUESTA,arrayMusico,CANTIDAD_MUSICO);
                break;

            case 3:// listar orquesta
                if(flagOrquesta == 0)
                {
                    printf("\nNo se ha dado del alta ninguna orquesta");
                }
                else
                    orquesta_listar(arrayOrquesta,CANTIDAD_ORQUESTA);
                break;

            case 4://alta musicos
                if(musico_alta(arrayMusico,CANTIDAD_MUSICO,&contadorIdMusico)== 0)
                    flagMusico = 1;
                break;

            case 5://Modificar musicos
                if(flagMusico == 0)
                {
                    printf("\nNo se ha dado de alta ningun musico");
                }
                else
                    musico_modificar(arrayMusico,CANTIDAD_MUSICO);
                break;

            case 6://baja musicos
                if(flagMusico == 0)
                {
                    printf("\nNo se ha dado de alta ningun musico");
                }
                else
                    musico_baja(arrayMusico,CANTIDAD_MUSICO);
                break;

            case 7://listar musicos
                if(flagMusico == 0)
                {
                    printf("\nNo se ha dado de alta ningun musico");
                }
                else
                    Informes_listarMusico(arrayMusico,arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                break;

            case 8://alta instrumentos
                if(instrumento_alta(arrayInstrumento,CANTIDAD_INSTRUMENTO,&contadorIdInstrumento)==0)
                    flagInstrumento = 1;
                break;

            case 9://listar instrumentos
                if(flagInstrumento == 0)
                {
                    printf("\nNo se ha dado de alta ningun instrumento");
                }
                else
                    instrumento_listar(arrayInstrumento,CANTIDAD_INSTRUMENTO);
                break;

            case 10://informes
                do
                {
                    menuInformes();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,&opcionI);
                    switch(opcionI)
                    {
                        case 1://alta orquests
                                listar_orquesta_deLugar(arrayOrquesta,CANTIDAD_ORQUESTA);
                            break;
                        case 2://baja orquesta
                                listar_musico_menores(arrayMusico, arrayOrquesta, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_ORQUESTA,CANTIDAD_INSTRUMENTO );
                            break;
                        case 3:// listar orquesta
                                listar_orquesta_menosMusico(arrayOrquesta, arrayMusico,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO);
                            break;
                        case 4:// listar orquesta
                                listar_instrumento_orquesta(arrayMusico, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 5:// listar orquesta
                                listar_orquesta_completa(arrayOrquesta, arrayMusico, arrayInstrumento,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 6:// listar orquesta
                                imprimir_orquesta_menores(arrayOrquesta, arrayMusico,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO);
                            break;
                        case 7:// listar orquesta
                                imprimir_promedio_musico(arrayOrquesta, arrayInstrumento,CANTIDAD_ORQUESTA,CANTIDAD_INSTRUMENTO);
                            break;
                        case 8:// listar orquesta
                                listar_musico_instrumentoViento(arrayMusico, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 9://Salir
                                break;
                            default:
                                printf("\nOpcion no valida");
                    }
                }while(opcionI != 9);
                break;
                    printf("\nOpcion no valida");
            case 11://Salir
                break;
            default:
                    printf("\nOpcion no valida");
        }

    }while(opcion!=11);


    return 0;

}
//----------------------------------------------------------------------------

int cargarDatos(Instrumento arrayInstrumento[], Musico arrayMusico[], Orquesta arrayOrquesta[],int *contadorIdOrquesta,int *contadorIdInstrumento,int *contadorIdMusico)
{
    int i=0;
    //instrumento
    arrayInstrumento[i].isEmpty=0;
    arrayInstrumento[i].idUnico=*contadorIdInstrumento;
    arrayInstrumento[i].tipo=1;
    strcpy(arrayInstrumento[i].nombre,"Inst 1");
    (*contadorIdInstrumento)++;
    i++;

    arrayInstrumento[i].isEmpty=0;
    arrayInstrumento[i].idUnico=*contadorIdInstrumento;
    arrayInstrumento[i].tipo=2;
    strcpy(arrayInstrumento[i].nombre,"Inst 2");
    (*contadorIdInstrumento)++;
    i++;

    arrayInstrumento[i].isEmpty=0;
    arrayInstrumento[i].idUnico=*contadorIdInstrumento;
    arrayInstrumento[i].tipo=3;
    strcpy(arrayInstrumento[i].nombre,"Inst 3");
    (*contadorIdInstrumento)++;
    i++;

    arrayInstrumento[i].isEmpty=0;
    arrayInstrumento[i].idUnico=*contadorIdInstrumento;
    arrayInstrumento[i].tipo=3;
    strcpy(arrayInstrumento[i].nombre,"Inst 3");
    (*contadorIdInstrumento)++;
    i++;

    arrayInstrumento[i].isEmpty=0;
    arrayInstrumento[i].idUnico=*contadorIdInstrumento;
    arrayInstrumento[i].tipo=4;
    strcpy(arrayInstrumento[i].nombre,"Inst 4");
    (*contadorIdInstrumento)++;
    i++;

    i=0;
 //------------------------------------------------------
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=30;
    arrayMusico[i].idOrquesta=2;
    arrayMusico[i].idInstrumento=1;
    strcpy(arrayMusico[i].nombre,"Mus1");
    strcpy(arrayMusico[i].apellido,"AMus1");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=20;
    arrayMusico[i].idOrquesta=5;
    arrayMusico[i].idInstrumento=2;
    strcpy(arrayMusico[i].nombre,"Mus2");
    strcpy(arrayMusico[i].apellido,"AMus2");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=25;
    arrayMusico[i].idOrquesta=2;
    arrayMusico[i].idInstrumento=4;
    strcpy(arrayMusico[i].nombre,"Mus3");
    strcpy(arrayMusico[i].apellido,"AMus3");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=27;
    arrayMusico[i].idOrquesta=1;
    arrayMusico[i].idInstrumento=4;
    strcpy(arrayMusico[i].nombre,"Mus4");
    strcpy(arrayMusico[i].apellido,"AMus4");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=22;
    arrayMusico[i].idOrquesta=3;
    arrayMusico[i].idInstrumento=1;
    strcpy(arrayMusico[i].nombre,"Mus5");
    strcpy(arrayMusico[i].apellido,"AMus5");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=35;
    arrayMusico[i].idOrquesta=4;
    arrayMusico[i].idInstrumento=3;
    strcpy(arrayMusico[i].nombre,"Mus6");
    strcpy(arrayMusico[i].apellido,"AMus6");
    (*contadorIdMusico)++;
    i++;
//-----------------------------------------------
    i=0;
    //orquesta
    arrayOrquesta[i].isEmpty=0;
    arrayOrquesta[i].idUnico=*contadorIdOrquesta;
    arrayOrquesta[i].tipo=1;
    strcpy(arrayOrquesta[i].nombre,"Orquesta1");
    strcpy(arrayOrquesta[i].lugar,"Lugar1");
    (*contadorIdOrquesta)++;
    i++;
    //orquesta
    arrayOrquesta[i].isEmpty=0;
    arrayOrquesta[i].idUnico=*contadorIdOrquesta;
    arrayOrquesta[i].tipo=2;
    strcpy(arrayOrquesta[i].nombre,"Orquesta2");
    strcpy(arrayOrquesta[i].lugar,"Lugar1");
    (*contadorIdOrquesta)++;
    i++;
    //orquesta
    arrayOrquesta[i].isEmpty=0;
    arrayOrquesta[i].idUnico=*contadorIdOrquesta;
    arrayOrquesta[i].tipo=3;
    strcpy(arrayOrquesta[i].nombre,"Orquesta3");
    strcpy(arrayOrquesta[i].lugar,"Lugar2");
    (*contadorIdOrquesta)++;
    i++;
    //orquesta
    arrayOrquesta[i].isEmpty=0;
    arrayOrquesta[i].idUnico=*contadorIdOrquesta;
    arrayOrquesta[i].tipo=2;
    strcpy(arrayOrquesta[i].nombre,"Orquesta4");
    strcpy(arrayOrquesta[i].lugar,"Lugar3");
    (*contadorIdOrquesta)++;
    i++;

    return 0;
}

/*
Entidades:
    Orquesta
        ID
        Nombre
        Lugar
        Tipo

    Musico
        ID musico
        Nombre
        Apellido
        Edad
        ID orquesta
        ID instrumento

    Instrumento
        ID
        Nombre
        Tipo

Falta: validar tipos, no mayor a 3 o 4


*/



