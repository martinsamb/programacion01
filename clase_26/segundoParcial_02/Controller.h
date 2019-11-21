#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


int controllerEntrega_loadFromText(char* path , LinkedList* pArrayList);
int controllerEntrega_loadFromBinary(char* path , LinkedList* pArrayList);
int controllerEntrega_add(LinkedList* pArrayList, int* ultimoId);
int controllerEntrega_edit(LinkedList* pArrayList);
int controllerEntrega_remove(LinkedList* pArrayList);
int controllerEntrega_list(LinkedList* pArrayList);
int controllerEntrega_sort(LinkedList* pArrayList);
int controllerEntrega_saveAsText(char* path , LinkedList* pArrayList);
int controllerEntrega_saveAsBinary(char* path , LinkedList* pArrayList);


#endif // CONTROLLER_H_INCLUDED
