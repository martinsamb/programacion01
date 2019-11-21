#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Entregas.h"

int controller_cantidadEntregada(LinkedList* pArrayListEntrega);
int controller_importeEntregado(LinkedList* pArrayListEntrega);
int controller_loadFromText(char* path, LinkedList* pArrayListEntrega);
int controller_saveAsText(char* path, LinkedList* pArrayListEntrega);


#endif // CONTROLLER_H_INCLUDED
