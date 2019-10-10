#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "alquiler.h"
#include "juegos.h"


#include "funciones.h"

#define TRIES 3

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array cliente Array of cliente
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int clientes_initStruct(Cliente* arrayCliente, int limite)
{
    int retorno = -1;
    int i;
    if (arrayCliente!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayCliente[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Busca el primer lugar vacio en un array
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param resultado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int clientes_findEmpty (Cliente* arrayCliente,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayCliente!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayCliente[i].isEmpty==1)
            {
                *resultado=i;
                retorno=0;
                break;
            }
            //retorno = 1;
        }
    }
    return retorno;
}
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param ID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int clientes_alta(Cliente* arrayCliente, eAlquiler* arrayAlquiler,eJuego* arrayJuego,int *id,int limiteCliente,int limiteAlquiler, int limiteJuego)
{
    int retorno=-1;
    int lugarVacio;
    int idAlquiler;
    int idJuego;
    int auxEdad;
    fflush(stdin);

    if (limiteAlquiler>0 && id!=NULL && limiteCliente>0 && limiteJuego>0)
    {
        orquesta_print(arrayAlquiler,limiteAlquiler);
        if (orquesta_findById("\nIngrese id del orquesta: \n",arrayAlquiler,&idAlquiler,limiteAlquiler)==0)
        {
            juegos_print(arrayJuego,limiteJuego);
            if (juegos_findById("\nIngrese id de juegos: \n",arrayJuego,&idJuego,limiteJuego)==0)
            {
                if(clientes_findEmpty(arrayCliente,limiteCliente,&lugarVacio)!=-1)
                {
                    if(getName("\nIngrese nombre del cliente: \n","Error, nombre no valido.\n",1,31,TRIES,arrayCliente[lugarVacio].nombre)==0 &&
                        getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",1,12,TRIES,arrayCliente[lugarVacio].apellido)==0 &&
                        getSex("\nIngrese Sexo: \n","Error, Sexo no valido.\n",1,1,TRIES,arrayCliente[lugarVacio].sexo)&&
                        getInt("\nIngrese edad: \n","Error, edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                    {
                       arrayCliente[lugarVacio].idCliente=*id;
                       arrayCliente[lugarVacio].idAlquiler=idAlquiler;
                       arrayCliente[lugarVacio].idJuego=idJuego;
                       arrayCliente[lugarVacio].edad=auxEdad;
                        (*id)++;
                       arrayCliente[lugarVacio].isEmpty=0;
                       printf("\nSe cargaron con exito los datos.\n");
                       retorno=0;
                    }else
                        {
                            printf("\nNo se pudo cargar con exito.\n");
                        }
                }else
                {
                    printf("\nNo hay espacio vacio.\n");
                }
            }else
            {
                printf ("\nId del socio no encontrado.\n");
            }
        }else
        {
            printf ("\nId de cliente no encontrado.\n");
        }
    }
    return retorno;
}

void clientes_print(Cliente* arrayCliente, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayCliente[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del cliente: %s ",arrayCliente[i].nombre);
            printf ("\nApellido del cliente: %s ",arrayCliente[i].apellido);
            printf ("\nId del cliente: %d ",arrayCliente[i].idCliente);
        }
    }
}
/** \brief Borra un elemento del array por ID
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int clientes_baja(Cliente* arrayCliente,int limiteCliente)
{
    int posicion;
    int retorno=-1;
    if (arrayCliente!=NULL && limiteCliente>0)
    {
        clientes_print(arrayCliente,limiteCliente);
        //cliente_print(arrayCliente,limiteCliente,arrayJuego,limiteJuego);
        switch (clientes_findById("\nIngrese el id del cliente a dar de baja: \n",arrayCliente,&posicion,limiteCliente))
        {
            case 0:
            if (arrayCliente[posicion].isEmpty==0)
            {
                arrayCliente[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayCliente[posicion].idCliente);
                retorno=0;
            }
            break;
            case 1:
                printf ("\nNo se encontro el id.\n");
                break;
            default:
                printf ("\nNo encontro el id.\n");
                break;
        }
    }
    return retorno;
}


int clientes_modificar(Cliente* arrayCliente,eAlquiler* arrayAlquiler,int limiteAlquiler, int limiteCliente)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idAlquiler;
    int auxEdad;//
    if (arrayCliente!=NULL && limiteCliente>0 && limiteAlquiler>0 && arrayAlquiler!=NULL)
    {
        clientes_print(arrayCliente,limiteCliente);
        //cliente_findById("Ingrese el id del autor a modificar",arrayCliente,&posicion,limite);
        //posicion=cliente_getId(msj,arrayCliente,limite);
        if (clientes_findById("\nIngrese el id del cliente a modificar: \n",arrayCliente,&posicion,limiteCliente)==0)
        {
            while (opcion!=3)
            {
                getInt("\n1-Modificar edad.\n2-Modificar id de orquesta.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                system("cls");//
                //system("clear");
                fflush(stdin);
                //__fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getInt("\nIngrese nuevo edad: \n","Edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                    {
                        arrayCliente[posicion].edad=auxEdad;
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("\nModificacion sin exito.\n");
                        }
                    break;
                    case 2:
                    if (orquesta_findById("\nIngrese nuevo id del orquesta:\n",arrayAlquiler,&idAlquiler,limiteAlquiler)==0)
                    {
                        arrayCliente[posicion].idAlquiler=idAlquiler;
                        //strncpy(arrayCliente[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 3:
                        break;
                }//fin switch
            }
            retorno=0;//fin while
        }else
            printf("\nNo se encontro el id.\n");
    }
    return retorno;
}

int clientes_findById(char* msj,Cliente* arrayCliente,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxCliente;
    //revisar limite aca abajo
    if (msj!=NULL && arrayCliente !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxCliente)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayCliente[i].isEmpty==0)
                {
                    if (arrayCliente[i].idCliente == auxCliente)
                    {
                        retorno=0;
                        *idEncontrado=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int cliente_buscarID(Cliente* arrayCliente, int limite, int valorBuscado, int* posicion)                    //cambiar cliente
{
    int retorno=-1;
    int i;
    if(arrayCliente!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayCliente[i].isEmpty==1)
                continue;
            else if(arrayCliente[i].idCliente==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int clientes_bajaAlquiler(Cliente* arrayCliente,int limiteCliente, eAlquiler* arrayAlquiler, int limiteAlquiler)
{
    int retorno=-1;
    int i;
    int j;
    if (arrayCliente!=NULL && arrayAlquiler!=NULL && limiteCliente>0 && limiteAlquiler>0)
    {
        for (i=0;i<limiteAlquiler;i++)
        {
            if (arrayAlquiler[i].isEmpty==1)
            {
                for (j=0;j<limiteCliente;j++)
                {
                    arrayCliente[j].isEmpty=1;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int clientes_bajaPorAlquiler(Cliente* arrayCliente, int limite, int idAEliminar)                                      //cambiar cliente
{
    int retorno=-1;
    int i;
    if(arrayCliente!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayCliente[i].idAlquiler == idAEliminar)
            {
                arrayCliente[i].isEmpty=1;
                arrayCliente[i].idCliente=0;                                                                   //cambiar campo id
                arrayCliente[i].edad=0;                                                               //cambiar campo edad                                                            //cambiar campo varFloat
                strcpy(arrayCliente[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(arrayCliente[i].apellido,"");
                arrayCliente[i].idAlquiler = 0;
                arrayCliente[i].idJuego = 0;                                               //cambiar campo apellido
                retorno=0;
            }
        }
    }
    return retorno;
}
void harcodearClientes(Cliente* arrayCliente, int limite)
{
    strcpy(arrayCliente[0].nombre,"Daniel");
    strcpy(arrayCliente[0].apellido,"Moreno");
    arrayCliente[0].isEmpty=0;
    arrayCliente[0].idCliente=0;

    strcpy(arrayCliente[1].nombre,"Marta");
    strcpy(arrayCliente[1].apellido,"Suarez");
    arrayCliente[1].isEmpty=0;
    arrayCliente[1].idCliente=1;

    strcpy(arrayCliente[2].nombre,"Jose");
    strcpy(arrayCliente[2].apellido,"Pepe");
    arrayCliente[2].isEmpty=0;
    arrayCliente[2].idCliente=2;
}
#endif // MUSICO_C_INCLUDED
