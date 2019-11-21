#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int isValidInt(char* buffer, int min, int max);
int isValidFloat(char* buffer);
int isValidName (char* buffer);
int isValidOpcion (char* buffer);
int isValidPhone (char* buffer, int caracteres);
int isValidSexo (char* buffer);
int isValidTitulo(char *pBuffer);
int isValidMail(char *pBuffer, int limite);
int isValidFecha (char* bufferDia, char* bufferMes, char* bufferAnio);
int isValidId (char* buffer);
int isValidFLoatStr(char* buffer);
int isValidFechaArchivo (char* buffer);
int isCuitArchivo (char* buffer);



#endif // UTN_H_INCLUDED
