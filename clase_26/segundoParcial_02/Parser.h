#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayList);

int Informes_ContadorAcumulado(LinkedList* pArrayList, int* contadorGold, int* contadorRegular, int* contadorPlus, int* acumuladoCantidad, int* promedioCantidad, int* promedioImporte);
int informeEntrega_saveAsText(char* path , LinkedList* pArrayList);

#endif // PARSER_H_INCLUDED
