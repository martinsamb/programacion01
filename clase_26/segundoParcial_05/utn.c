#include "utn.h"
/** \brief Solicita el ingreso de un string y valida su tamaño
* \param msg char* Mensaje a mostrar
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño minimo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getString ( char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getChar ( char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)<2)
            {
                strncpy(resultado,bufferStr,2);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getDate ( char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr) > 7 && strlen(bufferStr) < 9)
            {
                strncpy(resultado,bufferStr,9);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}
//--------------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (solo letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getChar (char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getChar(msg,msgError,reintentos,bufferStr))
        {
            if(isValidChar(bufferStr))
            {
                strncpy(resultado, bufferStr,2);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidChar (char* cadena)
{
    int retorno = TRUE;
    if((*cadena > 'Z' || *cadena < 'A') && (*cadena > 'z' || *cadena < 'a')  )
    {
        retorno = FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getSexo (char* msg,char* msgError,int reintentos,char* resultado) //CADENA= &VARIABLE
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getChar(msg,msgError,reintentos,bufferStr))
        {
            if(isValidSexo(bufferStr))
            {
                strncpy(resultado, bufferStr,2);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidSexo (char* cadena)
{
    int retorno = TRUE;
    if(*cadena != 'M' && *cadena != 'm' && *cadena != 'F' && *cadena != 'f')
    {
        retorno = FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getInter(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidInter(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidInter (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            if( (i==0 && cadena[i]=='-') )
            {
                continue;
            }
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getPositiveInter(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidPositiveInter(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidPositiveInter (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------
//EL MAXIMO HAY QUE SUMARLE 1
int utn_getFloat(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidFloat(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidFloat (char* cadena)
{
    int retorno = TRUE;
    int i;
    int contador=0;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(i==0 && cadena[i]=='-')
        {
            continue;
        }
        if(contador<1&&cadena[i]=='.')
        {
            contador++;
            continue;
        }
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    if(cadena[0]=='-' && (cadena[1] < '0' || cadena[1] > '9'))
    {
        retorno=FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getEmail(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidEmail(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidEmail (char* cadena)
{
    int retorno = TRUE;
    int contador1=0;
    int contador2=0;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(contador1<1&&cadena[i]=='@')
        {
            contador1++;
            continue;
        }
        if(contador2<2&&cadena[i]=='.')
        {
            contador2++;
            continue;
        }
        if( (cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') )
        {
            retorno = FALSE;
            break;
        }
    }
    if(contador1==0 || contador2==0)
    {
        retorno=FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getTelephone(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidTelephone(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidTelephone (char* cadena)
{
    int retorno = TRUE;
    int contador=0;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(contador<2&&cadena[i]=='-')
        {
            contador++;
            continue;
        }
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getFecha (char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getDate(msg,msgError,reintentos,bufferStr))
        {
            if(isValidFecha(bufferStr))
            {
                strncpy(resultado, bufferStr,9);
                retorno = 0;
            }
        }

    }
    return retorno;
}
//10 CARACTERES ENTONCES EL STRING DEBE TENER 11
int isValidFecha (char* cadena)
{
    int retorno=-1; //DEVUELVE -1 SI LA CADENA ES NULL
    int i;
    int contador=0;
    if(cadena!=NULL && strlen(cadena)==10)
    {
        for(i=0;i<10;i++)
        {
            if(i==2 && cadena[i]=='/')
            {
                contador++;
                continue;
            }
            if(i==5 && cadena[i]=='/')
            {
                contador++;
                continue;
            }
            if((cadena[i] < '0' || cadena[i] > '9'))
            {
                retorno=0;
                break;
            }
        }
        if( (cadena[0]=='0'&&cadena[1]=='0') || (cadena[3]=='0'&&cadena[4]=='0') ) //NO HAYA DOS 00 EN EL DIA
        {
            retorno=0;
        }
        if(cadena[0]=='3'&&cadena[1]>'1') //31 DIAS MAXIMO
        {
            retorno=0;
        }
        if(cadena[3]>'1') //MES MAXIMO EMPIEZA CON 1
        {
            retorno=0;
        }
        if(cadena[3]=='1'&&cadena[4]>'2') //NO EXISTE EL MAYOR QUE EL 12
        {
            retorno=0;
        }
    }
    else
    {
        retorno=0;
    }
    if(retorno==-1) //SI NO HUBO UN DATO ERRONE SE DEVUELVE TRUE
    {
        retorno=1;
    }
    if(contador!=2) //SI NO TIENE 2 BARRAS ESTA MAL
    {
        retorno=0;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getAlphaNumerico (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidAlphaNumerico(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidAlphaNumerico (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(cadena[i]==' ')
        {
            continue;
        }
        if( (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getDni (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidTelephone(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}
int isValidDni (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if( (cadena[i] < '0' || cadena[i] > '9') )
        {
            if(cadena[i]=='.')
            {
                continue;
            }
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}
//--------------------------------------------------------------------------------------------------

//10 CARACTERES ENTONCES EL STRING DEBE TENER 11
int isValidCuit (char* cadena)
{
    int retorno=-1; //DEVUELVE -1 SI LA CADENA ES NULL
    int i;
    int contador=0;
    if(cadena!=NULL && strlen(cadena)<=13)
    {
        for(i=0;i<strlen(cadena);i++)
        {
            if(i==2 && cadena[i]=='-')
            {
                contador++;
                continue;
            }
            if(i==9 && cadena[i]=='-')
            {
                contador++;
                continue;
            }
            if(i==10 && cadena[i]=='-')
            {
                contador++;
                continue;
            }
            if(i==11 && cadena[i]=='-')
            {
                contador++;
                continue;
            }
            if((cadena[i] < '0' || cadena[i] > '9'))
            {
                retorno=0;
                break;
            }
        }
    }
    else
    {
        retorno=0;
    }
    if(retorno==-1) //SI NO HUBO UN DATO ERRONE SE DEVUELVE TRUE
    {
        retorno=1;
    }
    if(contador!=2) //SI NO HAY 2 GUIONES ESTA MAL
    {
        retorno=0;
    }
    return retorno;
}
/*
int esCuit(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
        i++;
    }
    return 1;
}
*/
//--------------------------------------------------------------------------------------------------

void utn_clean(void)
{
    system("cls");
}

void utn_pauseClean(void)
{
    system("pause");
    system("cls");
}

//--------------------------------------------------------------------------------------------------

int utn_isValidLenght(char* palabra,int min,int max)
{
    if(palabra!=NULL && strlen(palabra)>min &&strlen(palabra)<max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//--------------------------------------------------------------------------------------------------



