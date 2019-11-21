#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
		returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i = 0;
    Node* pAuxNode = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(this->size != 0 && (this->pFirstNode != NULL))
        {
            if(nodeIndex == i) ///caso indice 0
            {
                pNode = this->pFirstNode;
                i++;
            }
            else
            {
               pAuxNode = this->pFirstNode;
                do
                {
                    if(nodeIndex == i && nodeIndex != ll_len(this))
                    {
                        pNode = pAuxNode;
                        break;
                    }
                    else
                    {
                        pAuxNode = pAuxNode->pNextNode;
                        i++;
                    }
                }while(ll_len(this) != i);
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)//Donde quiere que entre
//Me quiero meter entre dos nodos
{
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex>=0 && nodeIndex <= ll_len(this))
    {
        pNodoNuevo = (Node*) malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL)
                {
                    pNodoNuevo->pNextNode = NULL;
                }
                if(this->pFirstNode != NULL)
                {
                    pNodoNuevo->pNextNode = this->pFirstNode;
                }
                this->pFirstNode = pNodoNuevo;
            }
            else
            {
                pNodoAnterior = getNode(this,nodeIndex-1);
                pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode = pNodoNuevo;
            }
            this->size++;
            returnAux = 0;
        }
	}
	return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if( this != NULL)
    {
        if(addNode(this,ll_len(this),pElement)== 0)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxiliar = NULL;

    if(this != NULL && index >= 0 && index<ll_len(this))
    {
        pAuxiliar = getNode(this,index);
        if(pAuxiliar != NULL)
        {
            returnAux = pAuxiliar->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAuxiliar;
    if(this!=NULL && index<ll_len(this) && index>=0)
    {
        nodoAuxiliar = getNode(this, index);
        nodoAuxiliar->pElement = pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAuxiliar;
    Node* nodoAnterior;
    Node* nodoProximo;
    if(this!=NULL && ll_len(this)>0 && index>=0 && index<ll_len(this))
    {
        nodoAuxiliar = getNode(this, index);
        nodoProximo = getNode(this, index+1);
        if(index==0)
        {
            this->pFirstNode = nodoProximo;
        }
        else
        {
            nodoAnterior = getNode(this, index-1);
            nodoAnterior->pNextNode = nodoProximo;
        }
        free(nodoAuxiliar);
        returnAux=0;
        this->size-=1;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i = 0;i<ll_len(this);i++)
        {
            ll_remove(this,i);
        }
        if(ll_len(this) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i = 0;i<ll_len(this);i++)
        {
            if(ll_get(this,i) == pElement)
            {
                returnAux = i;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;
        if(ll_len(this)>0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index>= 0 && index >= ll_len(this))
    {
        if(addNode(this,index,pElement)== 0)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index>= 0 && index<ll_len(this))
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if (ll_indexOf(this, pElement) != -1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElementBuscado;
    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0; i<ll_len(this2); i++)
        {
            pElementBuscado = ll_get(this2, i);
            if(ll_contains(this, pElementBuscado)!=1)
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if( this != NULL &&
        from >=0 &&
        from < to &&
        to <=ll_len(this) &&
        to > from)
        {
            cloneArray = ll_newLinkedList();
            do
            {
                if(cloneArray != NULL)
                {
                    ll_add(cloneArray,ll_get(this,from));
                    from++;
                }
                else
                {
                    cloneArray = NULL;
                }
            }while(from != to);
        }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i= 0; i < ll_len(this); i++)
            {
                ll_add(cloneArray,ll_get(this, i));
            }
        }
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int flagSwap;
    void *pElementA;
    void *pElementB;
    if( this != NULL &&
        pFunc != NULL &&
        (order == 1 || order == 0))
        {
            do
            {
                flagSwap=0;
                for (i = 0; i < ll_len(this)-1; i++)
                {
                    pElementA = ll_get(this, i);
                    pElementB = ll_get(this, i+1);
                    if( (pFunc(pElementA, pElementB) < 0 && !order) ||
                        (pFunc(pElementA, pElementB) > 0 && order) )
                    {
                        ll_set(this,i,pElementB);
                        ll_set(this,i+1,pElementA);
                        flagSwap=1;
                    }
                }
            }while(flagSwap);
            returnAux = 0;
        }

    return returnAux;
}

/** \brief INTERCAMBIA LOS ELEMENTOS DE DOS NODOS CONSECUTIVOS
 * \param LinkedList* this PUNTERO A LA LISTA
 * \param Node* pNodeAnterior ES EL NODO DEL PRIMER ELEMENTO
 * \return -1 Error: SI EL PUNTERO A LA LISTA ES NULL O EL NODO ES NULL
            0 SI SALIO TODO BIEN
 */
int ll_swapElement(LinkedList* this, Node* pNodeAnterior)
{
    int returnAux = -1;
    Node* pNodeSiguiente = pNodeAnterior->pNextNode;
    void* auxElement = NULL;
    if(this != NULL && pNodeAnterior != NULL && pNodeSiguiente != NULL)
    {
        auxElement = pNodeAnterior->pElement;
        pNodeAnterior->pElement = pNodeSiguiente->pElement;
        pNodeSiguiente->pElement = auxElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief SE LE APLICA UNA FUNCION A TODOS LOS ELEMENTOS DE LA LISTA
 * \param LinkedList* this LA LISTA DE EMPLEADOS
 * \param int (*pFunc)(void*) LA FUNCION QUE SE LE APLICA A CADA EMPLEADO
 * \return -1 SI LA LISTA ES NULL O EL PUNTERO A FUNCION ES NULL
            1 SI LOS PARAMETROS SON CORRECTOS Y SE LE PUDO APLICAR LA FUNCION A TODOS LOS ELEMENTOS DE LA LISTA
 */
int ll_map (LinkedList* this, void (*pFunc)(void*))
{
    int returnAux = -1;
    void* auxElement = NULL;
    if (this != NULL && pFunc != NULL)
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            auxElement = ll_get(this, i);
            pFunc(auxElement);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief FUNCION QUE CREA Y DEVUELVA UNA NUEVA LISTA DE EMPLEADOS, CUYOS EMPLEADOS CUMPLE CON UN CIERTO CRITERIO
 * \param LinkedList* this PUNTERO A LA LISTA DE EMPLEADOS
 * \param int (*pFunc)(void*) CRITERIO PARA AGREGAR A LA NUEVA LISTA
 * \return NULL SI NO SE PUDO CREAR LA NUEVA LISTA, LA LISTA POR PARAMETROS ES NULL Y/O LA FUNCION ES NULL
 *         UN PUNTERO A UNA NUEVA LISTA DE EMPLEADOS
 */
LinkedList* ll_filter (LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* returnLista = ll_newLinkedList();
    void* pElement = NULL;
    if (this != NULL && pFunc != NULL && returnLista != NULL)
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if (pFunc(pElement))
            {
                ll_add(returnLista, pElement);
            }
        }
    }
    return returnLista;
}

/** \brief DE UNA LISTA, ELIMINA ELEMENTOS SI NO CUMPLEN CON SUS PARAMETROS
 * \param LinkedList* this PUNTERO A LA LISTA
 * \param int (*pFunc)(void*) FUNCION PARAMETRO
 * \return -1 SI LEL PUNTERO A LA LISTA ES NULL O EL PUNTERO A FUNCION ES NULL
            0 SI LOS PARAMETROS SON CORRECTOS Y PUDO BORRAR LA LISTA NUEVA
 */
int ll_review (LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    void* pElement = NULL;
    if (this != NULL && pFunc != NULL)
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if (pFunc(pElement))
            {
                free(ll_pop(this, i));
                i--;
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief DE UNA LISTA, cuenta los elementos que cumplen con un criterio
 * \param LinkedList* this PUNTERO A LA LISTA
 * \param int (*pFunc)(void*) FUNCION PARAMETRO
 * \return  0 si el punterio es null o no cumple el parametro
            1 si cumple con el paremtro
 */
int ll_count(LinkedList* this, int (*pFunc)(void*))
{
    int contador = 0;
    void* pElement = NULL;
    if (this != NULL && pFunc != NULL)
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if (pFunc(pElement))
            {
                contador++;
            }
        }
    }
    return contador;
}

