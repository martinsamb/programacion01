#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int isValidInt(int numero, int minimo, int maximo);
int isValidFloat(float numero, float minimo, float maximo);
int isValidChar(char letra, char minimo, char maximo);
int isValidName (char* cadena);
int isValidApellido (char* cadena);
int isValidDni(char* cadena);//aca dni
int isValidFecha(char *cadena);
//int isDni (char* pString);
int isNumber(char* pString);
int isCuit (char* pString);
int isTelefono (char* pString);
int isValidSex(char letra, char maximo, char minimo);
int isValidEmail(char* cadena);
int isEmail(char* cadena);
int isValidAlphanumeric(char* stringRecibido);

#endif // VALIDACIONES_H_INCLUDED
