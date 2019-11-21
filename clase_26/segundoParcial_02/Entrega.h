#ifndef ENTREGA_H_INCLUDED
#define ENTREGA_H_INCLUDED


#define STR_SIZE 128

typedef struct //Replace Entrega (tipo) y entrega (f)     campos: Cantidad + cantidad // Importe + importe // Cantidad2 + tipo2
{
    int id;
    char tipo[STR_SIZE];
    int cantidad;
    float importe;
}Entrega;

Entrega* entrega_new();
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr);
Entrega* entrega_newBinario(Entrega entrega);

void entrega_delete();

int entrega_setIdStr(Entrega* this,char* id);
int entrega_setId(Entrega* this,int id);
int entrega_getId(Entrega* this,int* id);

int entrega_setTipo(Entrega* this,char* tipo);
int entrega_getTipo(Entrega* this,char* tipo);

int entrega_setCantidadStr(Entrega* this,char* cantidad);
int entrega_setCantidad(Entrega* this,int cantidad);
int entrega_getCantidad(Entrega* this,int* cantidad);

int entrega_setImporteStr(Entrega* this,char* importe);
int entrega_setImporte(Entrega* this,float importe);
int entrega_getImporte(Entrega* this,float* importe);

int entrega_cmpId(void* punteroI, void* punteroJ);
int entrega_cmpTipo(void* this1, void* this2);
int entrega_cmpCriterio(void* this1, char* criterio);


int entrega_searchId(LinkedList* pArrayList, int valorBuscado, int* index);
int entrega_searchMaxId(LinkedList* pArrayList, int* maxID);



#endif // ENTREGA_H_INCLUDED
