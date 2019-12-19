#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"
#include "LinkedList.h"
#include "utn.h"

/** \brief Reserva espacio en memoria para un Computer
 *
 * \param void
 * \return Entrega*
 *
 */

Computer* computer_new()
{
	return (Computer*)malloc(sizeof(Computer));
}

/** \brief Valida los campos y los carga en una variable Computer
 *
 * \param idStr char*
 * \param tipoStr char*
 * \param cantidadStr char*
 * \param importeStr char*
 * \return Entrega*
 *
 */

Computer* computer_newParametros(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr, char* ofertaStr)
{
	Computer* aux;
	aux = computer_new();
	printf("newParam\n \nId:%s\ndescripcion: %s\nprecio: %s\nidTipo: %s\noferta: %s\n\n", idStr, descripcionStr, precioStr, idTipoStr, ofertaStr);
	if(aux != NULL)
    {
		int setId = computer_setIdStr(aux, idStr);
		int setDescripcion = computer_setDescripcion(aux, descripcionStr);
		int setPrecio = computer_setPrecioStr(aux, precioStr);
		int setIdTipo = computer_setIdTipoStr(aux, idTipoStr);
		int setOferta = computer_setOferta(aux, ofertaStr);

    if (setId != 0)
    {
      printf("Problema al cargar id\n");
      return NULL;
    }

    if (setDescripcion != 0)
    {
      printf("Problema al cargar la descripcion\n");
      return NULL;
    }

    if (setPrecio != 0)
    {
      printf("Problema al cargar el precio\n");
      return NULL;
    }

    if (setIdTipo != 0)
    {
      printf("Problema al cargar el id del tipo\n");
      return NULL;
    }

    if (setOferta != 0)
    {
      printf("Problema al cargar la oferta\n");
      return NULL;
    }
	}

	return aux;
}

/** \brief Libera el espacio reservado en memoria para un computer
 *
 * \param this Entrega*
 * \return void
 *
 */

int computer_delete(Computer* this)
{
	int ret = -1;
	if(this != NULL)
    {
		free(this);
		ret = 0;
	}
	return ret;
}
// ------------SETTERs Y GETTERs----------------

/** \brief Valida un campo y lo carga en la variable Computer
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */

int computer_setIdStr(Computer* this,char* idStr)
{
    int ret = -1;
    int auxId;
    if(this != NULL && idStr != NULL)
    {
        if(isValidNumber(idStr) == 0)
        {
            auxId = atoi(idStr);
            if(computer_setId(this, auxId) == 0)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Valida un campo y lo carga en la variable Computer
 *
 * \param this Entrega*
 * \param id int
 * \return int
 *
 */

int computer_setId(Computer* this,int id)
{
    int ret = -1;
    if(this != NULL && id >= 0)
    {
      this->id = id;
      ret = 0;
    }
    return ret;
}

/** \brief Devuelve el valor contenido en un campo de una variable Computer
 *
 * \param this Entrega*
 * \param id int*
 * \return int
 *
 */

int computer_getId(Computer* this,int* id)
{
    int ret = -1;
    if(this != NULL && id != NULL)
    {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int computer_setDescripcion(Computer* this,char* descripcion)
{
    int ret = -1;
    if(this != NULL && isValidText(descripcion) == 0)
    {
      strncpy(this->descripcion,descripcion,sizeof(this->descripcion));
      ret = 0;
    }
    return ret;
}

int computer_getDescripcion(Computer* this,char* descripcion)
{
    int ret = -1;
    if(this != NULL && descripcion != NULL)
    {
      strcpy(descripcion,this->descripcion);
      ret = 0;
    }
    return ret;
}

int computer_setPrecioStr(Computer* this,char* precioStr)
{
    int ret = -1;
    int auxPrecio;
    if(this != NULL && precioStr != NULL)
    {
      if(isValidNumber(precioStr) == 0)
      {
        auxPrecio = atoi(precioStr);
        if(computer_setPrecio(this, auxPrecio) == 0) {
        	computer_setPrecio(this, auxPrecio);
          ret = 0;
        }
      }
    }
    return ret;
}

int computer_setPrecio(Computer* this,int precio)
{
    int ret = -1;
    if(this != NULL && precio > 0)
    {
      this->precio = precio;
      ret = 0;
    }
    else
    {
    printf("error");
    }
    return ret;
}

int computer_getPrecio(Computer* this,int* precio)
{
  int ret = -1;
  if(this != NULL && precio != NULL)
  {
    *precio = this->precio;
    ret = 0;
  }
  return ret;
}

int computer_setIdTipoStr(Computer* this,char* idTipoStr)
{
    int ret = -1;
    int auxIdTipo;
    if(this != NULL && idTipoStr != NULL)
    {
        if(isValidNumber(idTipoStr) == 0)
        {
            auxIdTipo = atoi(idTipoStr);
            if(computer_setIdTipo(this, auxIdTipo) == 0)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int computer_setIdTipo(Computer* this,int idTipo)
{
    int ret = -1;
    if(this != NULL && idTipo >= 0)
    {
      this->idTipo = idTipo;
      ret = 0;
    }
    return ret;
}

int computer_getIdTipo(Computer* this,int* idTipo)
{
    int ret = -1;
    if(this != NULL && idTipo != NULL)
    {
      *idTipo = this->idTipo;
      ret = 0;
    }
    return ret;
}

int computer_setOferta(Computer* this,char* oferta)
{
    int ret = -1;
    if(this != NULL && isValidName(oferta) == 0)
    {
    	strncpy(this->oferta,oferta,sizeof(this->oferta));
    	ret = 0;
    }
    return ret;
}

int computer_getOferta(Computer* this,char* oferta)
{
  int ret = -1;
  if(this != NULL && oferta != NULL)
  {
	strcpy(oferta,this->oferta);
    ret = 0;
  }
  return ret;
}

/** \brief Compara dos ID
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */

int computer_compareIdTipo(void* pComputerA,void* pComputerB)
{
	int ret = 0;
	Computer* compA = (Computer*) pComputerA;
	Computer* compB = (Computer*) pComputerB;
	int tipo1=0;
	int tipo2=0;

	computer_getIdTipo(compA, &tipo1);
	computer_getIdTipo(compB, &tipo2);

    if(tipo1 > tipo2)
    {
        ret = 1;
    }
    else if(tipo1 < tipo2)
    {
        ret = -1;
    }
    return ret;
}

/** \brief Funcion criterio para pasar como argumento a la funcion ll_map
 *
 * \param pComputer void*
 * \return void
 *
 */
void computer_mapIdTipo(void* pComputer)
{
	Computer* comp = (Computer*) pComputer;
	if(comp->idTipo == 2)//LAPTOP
    {
		strcpy(comp->oferta, "SIN DATOS");//asigna al campo oferta la cadena "SIN DATOS"
	}
	else if(comp->idTipo == 1 && comp->precio > 20000)//FESKTOP, precio mayor 20000
    {
		strcpy(comp->oferta, "50% DESCUENTO");
	}
}

/** \brief Funcion criterio filtra equipos tipo desktop
 *
 * \param computer void*
 * \return int
 *
 */
int filtrar(void* computer)
{
	int returnAux = -1;
	int tipo;
	if(computer != NULL)
    {
		computer_getIdTipo(computer, &tipo);//Obtengo el valor de tipo
		if(tipo == 1)
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

