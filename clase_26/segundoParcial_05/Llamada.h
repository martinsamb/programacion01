#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int id;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucion[5];

}Llamada;

Llamada* newLlamada();

int deleteLlamada(Llamada* this);

int getId(Llamada* this,int* id);
int setId(Llamada* this,int id);

int getFecha(Llamada* this,char* fecha);
int setFecha(Llamada* this,char* fecha);

int getNumeroCliente(Llamada* this,int* numeroCliente);
int setNumeroCliente(Llamada* this,int numeroCliente);

int getIdProblema(Llamada* this,int* idProblema);
int setIdProblema(Llamada* this,int idProblema);

int getSolucion(Llamada* this,char* solucion);
int setSolucion(Llamada* this,char* solucion);

int problema1(void* elemento);
int problema2(void* elemento);
int problema3(void* elemento);
int problema4(void* elemento);
int problema5(void* elemento);



#endif // LLAMADA_H_INCLUDED
