#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados);
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int generarArchivoSueldos(char* fileName, LinkedList* listaEmpleados);
int save_EmployeeToText(FILE* pFile,LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
