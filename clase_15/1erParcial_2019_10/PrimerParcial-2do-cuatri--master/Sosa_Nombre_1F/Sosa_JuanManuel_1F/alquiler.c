
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "alquiler.h"
#include "juegos.h"


#include "funciones.h"

#define TRIES 3





int alquiler_initStruct(eAlquiler* arrayAlquiler, int limite)
{
    int retorno = -1;
    int i;
    if (arrayAlquiler!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayAlquiler[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int alquiler_findEmpty (eAlquiler* arrayAlquiler,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayAlquiler!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayAlquiler[i].isEmpty==1)
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
