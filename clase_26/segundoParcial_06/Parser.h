#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"

int parser_parseEmpleados(char* fileName, LinkedList* pArrayListEmpleados);
int parser_empleadoFromText(FILE* pFile, LinkedList* pArrayListEmpleados);
int generarArchivoSueldos(char* fileName, LinkedList* pArrayListEmpleados);
int save_empleadosToText(FILE* pFile, LinkedList* pArrayListEmpleados);






#endif // PARSER_H_INCLUDED
