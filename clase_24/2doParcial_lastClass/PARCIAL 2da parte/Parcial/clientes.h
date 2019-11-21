/*
 * clientes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define TAM_CLIENTE 100
#define TAM_NOMBRE 64
#define TAM_PALABRAS 64
#define TAM_CUIT 14

#define TRUE 1
#define FALSE 0

typedef struct
{
   int id;
   char nombreEmpresa[TAM_NOMBRE];
   char cuit[TAM_CUIT];
   char direccion[TAM_PALABRAS];
   char localidad[TAM_PALABRAS];
   int isEmpty;

}eCliente;


/** \brief Pide al usuario una opcion del menu, siendo el numero del tipo entero, entre un minimo y maximo, y lo valida.
 *
 * \param reintentos int    Limite de intentos de la peticion del numero de opcion.
 * \param numOpcMin int     Numero de opcion minimo que se puede ingresar.
 * \param numOpcMax int     Numero de opcion maximo que se puede ingresar.
 * \return int      Devuelve -1 si no existe la opcion ingresada, o si esta OK, devuelve el numero de la opcion deseada.
 *
 */
int menuConOpcion(int reintentos, int numOpcMin, int numOpcMax);


/** \brief Inicializa el programa haciendo que todas las posiciones del array sean vacios,
 *           poniendo el valor de isEmpty en TRUE=1.
 *
 * \param list eCliente*      Puntero del array.
 * \param len int           Longitud del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int inicializar_Cliente(eCliente* list, int len);


/** \brief Valida los datos del array
 *
 * \param list eCliente*     Puntero del array.
 * \return int       Devuelve (0)
 *
 */
int hardcodear_Cliente(eCliente* list);


/** \brief Busca una posicion en el array con isEmpty en TRUE, y devuelve el primero que encuentra.
 *
 * \param list eCliente*      Puntero del array.
 * \param len int           Longitud del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve el numero de la posicion si esta OK
 *
 */
int buscarIndexVacio_Cliente(eCliente* list, int len);


/** \brief Solicita los datos del auto y los almacena en el array de Cliente en la primer posicion vacia.
 *          El valor de isEmpty de la posicion se vuelve FALSE.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \param id int           Numero Id que se le asigna a la posicion vacia del array.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int alta_Cliente(eCliente* list, int len, int id);


/** \brief Muestra los valores cargados en el array de Cliente.
 *
 * \param list eCliente       Array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \return void
 *
 */
void mostrar_Cliente(eCliente list, int len);


/** \brief Pide el ID del Cliente e imprime el indice del array.
* \param list Cliente* Puntero del array de Cliente.
* \param id int ID del array.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve el numero de la posicion si existe.
*
*/
int buscar_ClienteById(eCliente* list, int id, int len);


/** \brief Solicita y busca la patente en el array de Cliente y modifica los valores, segun la opcion que se elija.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int editar_Cliente(eCliente* list, int len);


/** \brief Solicita y busca la patente en el array de Cliente y realiza una baja logica cambiando el valor isEmpty a TRUE.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \return int       Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve (0) si esta OK
 *
 */
int baja_Cliente(eCliente* list, int len);


/** \brief Imprime los datos cargados en el array del indice.
* \param list eCliente* Puntero del array de eCliente.
* \param index int Posicion en el array.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int print_Cliente(eCliente* list, int index, int len);


/** \brief Imprime en una lista los valores cargados en el array de Cliente.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \return void
 *
 */
void listar_Cliente(eCliente* list, int len);



/* \brief Lista los datos cargados en el array de Cliente, solicita ingresar la patente deseada y devuelve el numero de posicion de la patente.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \param marcas eMarcas*   Puntero del array de Marcas.
 * \param lenMarcas int     Longitud del array de Marcas.
 * \param colores eColores* Puntero del array de Colores.
 * \param lenColores int    Longitud del array de Colores.
 * \return int      Devuelve (-1) si se ingresa mal la patente o no existe, o devuelve numero de posicion si esta OK
 *
 *
int elegirAutoXPatente(eCliente* list, int len, eMarcas* marcas, int lenMarcas, eColores* colores, int lenColores);*/


/*\brief Ordena las marcas y las patentes de forma albabetica, de todos los valores del array de Cliente.
 *
 * \param list eCliente*      Puntero del array de Cliente.
 * \param len int           Longitud del array de Cliente.
 * \param marcas eMarcas*   Puntero del array de Marcas.
 * \param lenMarcas int     Longitud del array de Marcas.
 * \return void
 *
 *
void ordenarXMarcaYPatente(eCliente* list, int len, eMarcas* marcas, int lenMarcas);*/


#endif /* CLIENTES_H_ */
