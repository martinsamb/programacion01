#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "pedidos.h"
#include "clientes.h"

#define TRUE 1
#define FALSE 0



int menuInformes(int reintentos, int numOpcMin, int numOpcMax);

void informar_promedioDelTipoPlastico(ePedido* arrayPedido, int lenPedido);

void informar_ClienteDeMayorCantPlastico(eCliente* arrayCliente, int lenCliente, ePedido* arrayPedido, int lenPedido);

#endif // INFORMES_H_INCLUDED
