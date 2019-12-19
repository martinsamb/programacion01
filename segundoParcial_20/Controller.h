#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(LinkedList* pListaComputers);
int controller_PrintComputers(LinkedList* pListaComputers, int index);
int controller_ListComputers(LinkedList* pListaComputers);
int controller_saveComputersAsText(FILE* pFile , LinkedList* pListaComputers);
int controller_saveAsText(char* fileName,LinkedList* listaComputers);
int controller_sortComputers(LinkedList* pListaComputers);
int controller_mapComputers(LinkedList* pListaComputers);

#endif // CONTROLLER_H_INCLUDED
