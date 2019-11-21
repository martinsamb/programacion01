#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int getString (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int getChar ( char* msg,char* msgError,int reintentos,char* resultado);

int getDate (char* msg,char* msgError,int reintentos,char* resultado);

//-------------------------------------

int utn_getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidName (char* cadena);

//-------------------------------------

int utn_getChar (char* msg,char* msgError,int reintentos,char* resultado); //CADENA= &VARIABLE

int isValidChar (char* cadena);

//-------------------------------------

int utn_getSexo (char* msg,char* msgError,int reintentos,char* resultado); //CADENA= &VARIABLE

int isValidSexo (char* cadena);

//-------------------------------------

int utn_getInter (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidInter (char* cadena);

//-------------------------------------

int utn_getPositiveInter (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidPositiveInter (char* cadena);

//-------------------------------------

int utn_getFloat (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidFloat (char* cadena);

//-------------------------------------

int utn_getEmail (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidEmail (char* cadena);

//-------------------------------------

int utn_getTelephone (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidTelephone (char* cadena);

//-------------------------------------

int utn_getFecha (char* msg,char* msgError,int reintentos,char* resultado);  //SE PONE 9 EN MAXIMO

int isValidFecha (char* cadena);

//-------------------------------------

int utn_getAlphaNumerico (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidAlphaNumerico (char* cadena);

//-------------------------------------

int utn_getDni (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);

int isValidDni (char* cadena);

//-------------------------------------

void utn_clean(void);

void utn_pauseClean(void);

//-------------------------------------

int utn_isValidLenght(char* palabra,int min,int max);



#endif // UTN_H_INCLUDED
