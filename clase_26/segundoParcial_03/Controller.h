#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"

int controller_loadFromText(char* archivo, LinkedList* ListaEntidad);
int controller_saveAsText(char* archivo, int total, int mayor150, int mayor300, int polaroids);

#endif // CONTROLLER_H_INCLUDED
