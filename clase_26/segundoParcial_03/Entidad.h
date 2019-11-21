#ifndef ENTIDAD_H_INCLUDED
#define ENTIDAD_H_INCLUDED

typedef struct
{
    int id;
    char fecha[20];
    char foto[30];
    int cantidad;
    float precio;
    char cuit[15];
}Entidad;

Entidad* entidad_newEntidad();
Entidad* entidad_newEntidadParametros(char* id, char* fecha, char* foto, char* cantidad,
                                      char* precio, char* cuit);
int entidad_delete(Entidad* this);

int entidad_setId(Entidad* this,int id);
int entidad_getId(Entidad* this,int* id);
int entidad_setIdStr(Entidad* this, char* id);

int entidad_setFecha(Entidad* this,char* fecha);
int entidad_getFecha(Entidad* this,char* fecha);

int entidad_setFoto(Entidad* this,char* foto);
int entidad_getFoto(Entidad* this,char* foto);

int entidad_setCantidad(Entidad* this,int cantidad);
int entidad_getCantidad(Entidad* this,int* cantidad);
int entidad_setCantidadStr(Entidad* this, char* cantidad);

int entidad_setPrecio(Entidad* this,float precio);
int entidad_getPrecio(Entidad* this,float* precio);
int entidad_setPrecioStr(Entidad* this, char* precio);

int entidad_setCuit(Entidad* this,char* cuit);
int entidad_getCuit(Entidad* this,char* cuit);





#endif // ENTIDAD_H_INCLUDED
