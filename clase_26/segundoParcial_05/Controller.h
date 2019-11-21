#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Llamada.h"

int controller_loadFromText(char* path, LinkedList* this);
int controller_imprimirLlamadas(LinkedList* this);
int controller_askProblema();
int controller_writeText(char* path,LinkedList* this);



#endif // CONTROLLER_H_INCLUDED
