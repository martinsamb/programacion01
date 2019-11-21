/*
 * pedidos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOSS_H_
#define PEDIDOSS_H_

#include "clientes.h"

#define TAM_PEDIDOS 1000
#define PENDIENTE 1
#define COMPLETADO 2

#define TRUE 1
#define FALSE 0

typedef struct
{
   int id;
   int idCliente;
   int kilos;
   float hdpe;
   float ldpe;
   float pp;
   int estado;
   int isEmpty;

}ePedido;



/** \brief Inicializa el programa haciendo que todas las posiciones del array sean vacios,
 *           poniendo el valor de isEmpty en TRUE=1.
 *
 * \param list ePedido*      Puntero del array.
 * \param len int           Longitud del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int inicializar_Pedido(ePedido* list, int len);


/** \brief Valida los datos del array
 *
 * \param list ePedido*     Puntero del array.
 * \return int       Devuelve (0)
 *
 */
int hardcodear_Pedido(ePedido* list);


/** \brief Busca una posicion en el array con isEmpty en TRUE, y devuelve el primero que encuentra.
 *
 * \param list ePedido*      Puntero del array.
 * \param len int           Longitud del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve el numero de la posicion si esta OK
 *
 */
int buscarIndexVacio_Pedido(ePedido* list, int len);


/** \brief Solicita los datos de los Clientes y los almacena en el array de Pedido en la primer posicion vacia.
 *          El valor de isEmpty de la posicion se vuelve FALSE.
 *
 * \param list ePedido*      Puntero del array de Pedido.
 * \param len int           Longitud del array de Pedido.
 * \param id int           Numero Id que se le asigna a la posicion vacia del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int alta_Pedido(ePedido* list, int len, int id, eCliente* arrayCliente, int lenCliente);


/** \brief Muestra los valores cargados en el array de Pedido.
 *
 * \param list ePedido       Array de Pedido.
 * \param len int           Longitud del array de Pedido.
 * \return void
 *
 */
void mostrar_Pedido(ePedido list, int len);


/** \brief Pide el ID del Pedido e imprime el indice del array.
* \param list Pedido* Puntero del array de Pedido.
* \param id int ID del array.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve el numero de la posicion si existe.
*
*/
int buscar_PedidoById(ePedido* list, int id, int len);



/** \brief Imprime los datos cargados en el array del indice.
* \param list ePedido* Puntero del array de ePedido.
* \param index int Posicion en el array.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int print_PedidoPendiente(ePedido* list, int index, int len, eCliente* arrayCliente, int lenCliente);


/** \brief Imprime en una lista los valores cargados en el array de Pedido.
 *
 * \param list ePedido*      Puntero del array de Pedido.
 * \param len int           Longitud del array de Pedido.
 * \return void
 *
 */
void listar_PedidoPendiente(ePedido* list, int len, eCliente* arrayCliente, int lenCliente);


void listar_PedidoProcesado(ePedido* list, int len, eCliente* arrayCliente, int lenCliente);


void cargarDescripcionPedido(int idPedido, char desc[]);


int procesarResiduos(ePedido* list, int len, eCliente* arrayCliente, int lenCliente);


int cantidadPedidosXCliente(ePedido* list, int len, eCliente* arrayCliente, int indexCliente);

int print_ClienteConPedido(ePedido* list, int len, eCliente* arrayCliente, int indexCliente, int lenCliente);

void listar_ClienteConPedido(ePedido* list, int len, eCliente* arrayCliente, int lenCliente);

#endif /* PEDIDOSS_H_ */
