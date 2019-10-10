#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getInt(char *msj, char *errorMsj, int minimo, int maximo, int reintentos, int *resultado);
int getFloat(char *msj, char *errorMsj, float minimo, float maximo, int reintentos, float *resultado);
int getChar(char *msj, char *errorMsj, char minimo, char maximo, int reintentos, char *resultado);
int getDni (char* msj, char* msjError,int minimo, int maximo, int reintentos, char* resultado);
int getCuit (char* msg, char* msgError,int minimo, int maximo,int reintentos,char* resultado);
int getTelefono (char* msg, char* msgError,int minimo, int maximo,int reintentos,char* resultado);
int getName (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado);
int getApellido (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado);
int getString(char* msj, char* errorMsj,int minimo, int maximo, int reintentos, char* resultado);
int getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int getEmail(char* msj, char* msjError, int minimo, int maximo, int reintentos, char* resultado);
int getAlfanumerico(char* msj, char* msjError, int minSize, int maxSize, int reintentos, char* resultado);
int getFecha(char* msj,char* msjError,int minimo, int maximo, int reintentos,char* resultado);

#endif // FUNCIONES_H_INCLUDED
