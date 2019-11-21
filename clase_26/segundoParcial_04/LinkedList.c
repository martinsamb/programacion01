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
    if(this!=NULL)
    {
        returnAux=this->size;
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
    int len;
    int i;
    len=ll_len(this);
    if(this!=NULL && len!=-1 && nodeIndex>=0 && nodeIndex<len)
    {
        pNode=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
            pNode=pNode->pNextNode;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* newNode = NULL;
    Node* previousNode = NULL;
    len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
        newNode = (Node*) malloc(sizeof(Node));
        if(newNode!=NULL)
        {
            newNode->pElement=pElement;
            if(nodeIndex==0)
            {
                if(this->pFirstNode==NULL)
                {
                    newNode->pNextNode=NULL;
                }
                else
                {
                    newNode->pNextNode=this->pFirstNode;
                }
                this->pFirstNode=newNode;
            }
            else
            {
                previousNode=getNode(this,nodeIndex-1);
                newNode->pNextNode=previousNode->pNextNode;
                previousNode->pNextNode=newNode;
            }
            this->size++;
            returnAux=0;
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
    int len;
    Node* newNode = NULL;
    if(this!=NULL)
    {
        newNode = (Node*) malloc(sizeof(Node));
        if(newNode!=NULL)
        {
            len=ll_len(this);
            if(!addNode(this,len,pElement))
            {
                returnAux=0;
            }
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
    int len;
    Node* auxNode = NULL;
    len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
        auxNode=getNode(this,index);
        if(auxNode!=NULL)
        {
            returnAux=auxNode->pElement;
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
    int len;
    Node* auxNode = NULL;
    len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
        auxNode=getNode(this,index);
        if(auxNode!=NULL)
        {
            auxNode->pElement=pElement;
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
    int len;
    Node* auxNode = NULL;
    Node* previousNode = NULL;
    len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
        if(index==0)
        {
            auxNode=getNode(this,index);
            this->pFirstNode=auxNode->pNextNode;
            free(auxNode);
        }
        else
        {
            previousNode=getNode(this,index-1);
            auxNode=getNode(this,index);
            previousNode->pNextNode=auxNode->pNextNode;
            free(auxNode);
        }
        this->size--;
        returnAux=0;
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
int ll_clear(LinkedList* this) // PEDIR SIEMPRE EL 0
{
    int returnAux = -1;
    if(this!=NULL)
    {
        while(ll_len(this)>0)
        {
            ll_remove(this,0);
        }
        returnAux=0;
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
    if(this!=NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux=0;
        }
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
    int len;
    int i;
    Node* auxNode = NULL;
    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            auxNode=getNode(this,i);
            if(auxNode!=NULL)
            {
                if(auxNode->pElement==pElement)
                {
                    returnAux=i;
                    break;
                }
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
    if(this!=NULL)
    {
        if(this->size>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
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
    if(!addNode(this,index,pElement))
    {
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
    returnAux=ll_get(this,index);
    if(returnAux!=NULL)
    {
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
    int len;
    int i;
    if(this!=NULL)
    {
        returnAux=0;
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            if(pElement==ll_get(this,i))
            {
                returnAux=1;
                break;
            }
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
    int len2;
    int contador=0;
    void* pElement;
    if(this!=NULL && this2!=NULL)
    {
        returnAux=0;
        len2=ll_len(this2);
        for(i=0;i<len2;i++)
        {
            pElement=ll_get(this2,0);
            if(ll_contains(this,pElement))
            {
                contador++;
            }
        }
        if(contador==len2)
        {
            returnAux=1;
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
    int len;
    int i;
    len=ll_len(this);
    void* pElement=NULL;
    if(this!=NULL && from>=0 && from<=to && to<=len)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(i=from;i<to;i++)
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }
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
    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            cloneArray=ll_subList(this,0,ll_len(this));
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
    void* elementoMinimo;
    void* elementoAux;
    int i,j;
    int resultado;
    int index;
    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        for(i=0;i<ll_len(this);i++)
        {
            elementoMinimo=ll_get(this,i);
            index=ll_indexOf(this,elementoMinimo);
            for(j=i+1;j<ll_len(this);j++)
            {
                elementoAux=ll_get(this,j);
                resultado=pFunc(elementoMinimo,elementoAux);
                switch(order)
                {
                    case 1:
                        if(resultado==1)
                        {
                            elementoMinimo=elementoAux;
                            index=ll_indexOf(this,elementoAux);
                        }
                        break;
                    case 0:
                        if(resultado==-1)
                        {
                            elementoMinimo=elementoAux;
                            index=ll_indexOf(this,elementoAux);
                        }
                        break;
                }
            }
            if(index!=i);
            {
                elementoAux=ll_get(this,i);
                ll_set(this,index,elementoAux);
                ll_set(this,i,elementoMinimo);
            }
        }
        returnAux=0;
    }
    return returnAux;
}
/*
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* elementoA;
    void* elementoB;
    int i,j;
    int resultado;
    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        for(i=0;i<ll_len(this)-1;i++)
        {
            for(j=0;j<ll_len(this)-1-i;j++)
            {
                elementoA=ll_get(this,j);
                elementoB=ll_get(this,j+1);
                resultado=pFunc(elementoA,elementoB);
                switch(order)
                {
                    case 1:
                       if(resultado==1)
                       {
                           ll_set(this,j,elementoB);
                           ll_set(this,j+1,elementoA);
                       }
                        break;
                    case 0:
                        if(resultado==-1)
                        {
                            ll_set(this,j,elementoB);
                            ll_set(this,j+1,elementoA);
                        }
                        break;
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}
*/

int ll_map(LinkedList*this,void (*pFunc)(void*))
{
    int retorno=0;
    int i;
    int len;
    void* elemento;
    len=ll_len(this);
    if(this!=NULL && pFunc!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            elemento=ll_get(this,i);
            pFunc(elemento);
            retorno=1;
        }
    }
    return retorno;
}

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* cloneArray=NULL;
    int i;
    int len;
    void* elemento;
    len=ll_len(this);
    cloneArray=ll_newLinkedList();
    if(this!=NULL && pFunc!=NULL && len>0 && cloneArray!=NULL)
    {
        for(i=0;i<len;i++)
        {
            elemento=ll_get(this,i);
            if(elemento!=NULL)
            {
                if(pFunc(elemento))
                {
                    ll_add(cloneArray,elemento);
                }
            }
        }
    }
    return cloneArray;
}

int ll_reduce(LinkedList* this,int (*pFunc)(void*))
{
    int retorno=0;
    int i;
    int len;
    void* elemento;
    len=ll_len(this);
    if(this!=NULL && pFunc!=NULL && len>0)
    {
        for(i=0;i<ll_len(this);i++)
        {
            elemento=ll_get(this,i);
            if(pFunc(elemento))
            {
                elemento=ll_pop(this,i);
                free(elemento);
                retorno=1;
                i--;
            }
        }
    }
    return retorno;
}

int ll_parcialInt(LinkedList* this,int (*pFunc)(void* , int*))
{
    int retorno=0;
    int i;
    int len;
    void* elemento;
    len=ll_len(this);
    int auxiliar;
    if(this!=NULL && pFunc!=NULL && len>0)
    {
        for(i=0;i<ll_len(this);i++)
        {
            elemento=ll_get(this,i);
            if(elemento!=NULL)
            {
                //auxiliar=pFunc(elemento);
                retorno = retorno + auxiliar;
            }
        }
    }
    return retorno;
}

int ll_countFloat(LinkedList* this,int (*pFunc)(void* , float*),float* resultado)
{
    int retorno=0;
    int i;
    int len;
    void* elemento;
    len=ll_len(this);
    float auxiliar=0;
    float contador=0;
    if(this!=NULL && pFunc!=NULL && len>0)
    {
        for(i=0;i<ll_len(this);i++)
        {
            elemento=ll_get(this,i);
            if(elemento!=NULL)
            {
                if(pFunc(elemento,&contador))
                {
                    *resultado = *resultado + contador;
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}


