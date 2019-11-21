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
    if(this != NULL)                                    //consiguio espacio para un nuevo LinkedList
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
    if(this!=NULL)
        returnAux=this->size;

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
    int i;
    Node* pAux=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        pAux=this->pFirstNode;
        for(i=1; i<=nodeIndex; i++)
        {
            pAux=pAux->pNextNode;
        }
        pNode=pAux;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pAuxPrev=NULL;
    Node* pAuxNew=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))     //no se valida el elemento  && pElement!=NULL
    {
        pAuxNew = (Node*)malloc(sizeof(Node));
        pAuxPrev=getNode(this,nodeIndex-1);

        if(pAuxNew!=NULL)
        {
            pAuxNew->pElement=pElement;
            pAuxNew->pNextNode=getNode(this,nodeIndex);          //si es el ultimo elemento el get va a dar NULL, por lo que no apunta a nada

            if(nodeIndex==0)                    //Previo: donde almaceno la & del nuevo nodo
            {
                this->pFirstNode=pAuxNew;
            }
            else if(pAuxPrev!=NULL)             //el unico caso en que seria NULL es en index=0, asi que no es necesario checkear !=NULL
            {
                pAuxPrev->pNextNode=pAuxNew;
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}
// si el index ya està ocupado lo tengo que insertar
// si quiero insertar en un index mayor al tamaño? (no hay uno anterior)

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

    if(this!=NULL)
    {
        if(addNode(this,ll_len(this),pElement)==0)
            returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *          Retorna un puntero al elemento que se encuentra en el índice especificado
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAux=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pAux=getNode(this,index);           //puntero al nodo
        if(pAux!=NULL)
            returnAux=pAux->pElement;      //devuelve el puntero almacenado en el campo pElement
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
    Node* pAux=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pAux=getNode(this,index);                   //puntero al nodo
        if(pAux!=NULL)
        {
            pAux->pElement=pElement;                //almaceno nuevo elemento
            returnAux=0;
        }
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

    Node* pAuxActual=NULL;
    Node* pAuxPrev=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this) && ll_len(this)>0)
    {
        pAuxActual=getNode(this,index);
        pAuxPrev=getNode(this,index-1);

        if(pAuxActual!=NULL)
        {
            if(index==0)                    //Previo: donde almaceno la & del nodo siguiente
            {
                this->pFirstNode=pAuxActual->pNextNode;
            }
            else if(pAuxPrev!=NULL)
            {
                pAuxPrev->pNextNode=pAuxActual->pNextNode;
            }
            free(pAuxActual);
            this->size--;
            returnAux=0;
        }
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

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
            ll_remove(this,i);

        if(ll_len(this)==0)
            returnAux=0;
    }

    return returnAux;
}

//recorrer el arrayList (con el get) y uso remove p/c index, cuidado con el size que se va achicando, pedir siempre el 0 o el size (de atras p/adelante)

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

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}
//Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).

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
    int i=-1;
    void* pAux=NULL;

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pAux=ll_get(this,i);
            if(pAux==pElement)
                returnAux=i;
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
    //int i;
    //void* pAux=NULL;

    if(this!=NULL)
    {
        returnAux=1;
        /*
        for(i=0;i<ll_len(this);i++)
        {
            pAux=ll_get(this,i);
            if(pAux!=NULL)
            {
                returnAux=0;        //si alguno no es NULL hay un elemento cargado
                break;
            }
        }*/
        if(ll_len(this)>0)
            returnAux=0;

    }
    return returnAux;
}
//true>size=0
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
    if(this!=NULL && index>=0 && index<=ll_len(this))       //==len se agrega al final
    {
        if(addNode(this,index,pElement)==0)
            returnAux=0;
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

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}
//conserva el puntero del elemento (get + remove)

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
        returnAux=0;
        if(ll_indexOf(this,pElement)!=-1)
            returnAux=1;
    }
    return returnAux;
}

//si index !=NULL true
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
    void* pElement=NULL;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0;i<ll_len(this2);i++)
        {
            pElement=ll_get(this2,i);
            if(ll_contains(this,pElement)!=1)
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

// si dentro de la lista1 se encuentran todos los elementos de la lista 2
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
    int i;

    if(this!=NULL && from<to && from>=0 && to<ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        for(i=from;i<=to;i++)                               //el to se incluye? si lo incluyo da error el primer test (0-1), falla porque to==len (1)
        {
            addNode(cloneArray,i,ll_get(this,i));
        }
    }
    return cloneArray;
}

//construir un nuevo arrayList (get+ add )

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

    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        for(i=0;i<ll_len(this);i++)
        {
            addNode(cloneArray,i,ll_get(this,i));
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
    int i,j;
    Node* auxNode=NULL;

    if(this!=NULL && pFunc!=NULL && order>=-1 && order<=1)               //segun el test el orden solo puede ser 0 o 1, no -1, pero s/ PDF pueden ser los 3
    {
        for(i=0;i<ll_len(this);i++)
        {
            auxNode=getNode(this,i);
            j = i - 1;
            while ((j >= 0) && pFunc(auxNode->pElement,(getNode(this,j)->pElement))!=order)
            {
                j--;
            }
            if(j!=i-1)
            {
                addNode(this,j+1,auxNode->pElement);
                ll_remove(this,i+1);
            }
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Recorre la lista y ejecuta la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno=-1;
    int i;

    if(this!=NULL && pFunc!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pFunc(ll_get(this,i));
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Crea una nueva lista resultado de aplicar un filtro sobre la lista original utilizando la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param criterio void* Valor criterio para crear la lista
 * \param resultado int Resultado de la funcion comparacion
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* ,void*), void* criterio, int resultado)
{
    LinkedList* cloneArray = NULL;
    int i,j;

    if(this!=NULL && pFunc!=NULL)
    {
        cloneArray=ll_newLinkedList();
        for(i=0;i<ll_len(this);i++)
        {
            if(pFunc(ll_get(this,i),criterio)==resultado)
            {
                addNode(cloneArray,j,ll_get(this,i));
                j++;
            }
        }
    }
    return cloneArray;
}

/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param criterio void* Valor criterio para crear la lista
 * \param resultado int Resultado de la funcion comparacion
 * \return int Retorna  (-1) Error: si el puntero a la listas o pFunc es NULL
                                ( 0) Si ok
 */
int ll_reduce(LinkedList* this, int (*pFunc)(void* ,void*), void* criterio, int resultado)
{
    int retorno=-1;
    int i;

    if(this!=NULL && pFunc!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            if(pFunc(ll_get(this,i),criterio)!=resultado)
            {
                ll_remove(this,i);
                i--;
            }
        }
        retorno=0;
    }
    return retorno;
}
