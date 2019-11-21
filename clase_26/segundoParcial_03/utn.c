#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"

#define FALSE 0
#define TRUE 1
#define LLENO -1


int isValidInt(char* buffer, int min, int max)
{
    int retorno = FALSE;
    if(buffer != NULL && max > min)
    {
        int valid = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                valid = FALSE;
                break;
            }
        }

        if (valid == TRUE)
        {
            valid = atoi(buffer);
            if (valid > min && valid <= max)
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}


int isValidFloat(char* buffer)
{
    int retorno = FALSE;
    if(buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0;buffer[i] == '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


int isValidName (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if(!(tolower(buffer[i]) >= 'a' && tolower(buffer[i]) <= 'z'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}



int isValidOpcion (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


int isValidPhone (char* buffer, int caracteres)
{
    int retorno = FALSE;
    if (buffer != NULL && caracteres > 0)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


int isValidSexo (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        if (*buffer == 'm' || *buffer == 'f')
        {
            retorno = TRUE;
        }
    }
    return retorno;
}


int isValidTitulo(char *pBuffer)
{
    int retorno = FALSE;
    if(pBuffer != NULL)
    {
        retorno = TRUE;
        for(int i = 0; pBuffer[i] != '\0'; i++)
        {
            if(!(   (pBuffer[i] >= ' ' && pBuffer[i] <= '"') ||
                    (pBuffer[i] == '(' || pBuffer[i] == ')') ||
                    (pBuffer[i] >= ',' && pBuffer[i] <= '.') ||
                    (pBuffer[i] >= '0' && pBuffer[i] <= ';') ||
                    (pBuffer[i] >= '?' && pBuffer[i] <= 'Z') ||
                    (pBuffer[i] >= 'a' && pBuffer[i] <= 'z')))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


int isValidMail(char *pBuffer, int limite)
{
    int retorno = FALSE;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        strlen(pBuffer) > 0 &&
        tolower(pBuffer[0]) >= 'a' &&
        tolower(pBuffer[0]) <= 'z')
    {
        retorno = TRUE;
        flagLetraIntroducida = TRUE;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                    (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDeArrobas == FALSE))
            {
                flagLetraIntroducida = TRUE;
            }
            else if(pBuffer[i] == '@' && contadorDeArrobas == FALSE && flagLetraIntroducida == TRUE)
            {
                contadorDeArrobas++;
                flagLetraIntroducida = FALSE;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == TRUE)
            {
                flagLetraIntroducida = FALSE;
                if(contadorDeArrobas == TRUE)
                {
                    contadorDePuntosTrasArroba++;
                }
            }
            else if(pBuffer[i] == '_' && flagLetraIntroducida == TRUE && contadorDeArrobas == FALSE)
            {
                flagLetraIntroducida = FALSE;
            }
            else
            {
                retorno = FALSE;
                break;
            }
        }
    }
    if(retorno == TRUE && contadorDeArrobas == TRUE && contadorDePuntosTrasArroba > FALSE)
    {
        retorno = TRUE;
    }
    else
    {
        retorno = FALSE;
    }
    return retorno;
}


int isValidFecha (char* bufferDia, char* bufferMes, char* bufferAnio)
{
    int retorno = FALSE;
    int dia;
    int mes;
    if (bufferDia != NULL && bufferMes != NULL && bufferAnio != NULL)
    {
        retorno = TRUE;
        for (int i = 0; bufferDia[i] != '\0'; i++)
        {
            if(!(bufferDia[i] >= '0' && bufferDia[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
        if (retorno == TRUE)
        {
            for (int i = 0; bufferMes[i] != '\0'; i++)
            {
                if(!(bufferMes[i] >= '0' && bufferMes[i] <= '9'))
                {
                    retorno = FALSE;
                    break;
                }
            }
        }
        if (retorno == TRUE)
        {
            for (int i = 0; bufferAnio[i] != '\0'; i++)
            {
                if(!(bufferAnio[i] >= '0' && bufferAnio[i] <= '9'))
                {
                    retorno = FALSE;
                    break;
                }
            }
        }
        if (retorno == TRUE)
        {
            dia = atoi(bufferDia);
            mes = atoi(bufferMes);
            if (!(mes >= 1 && mes <= 12))
            {
                 switch (mes)
                {
                    case 1:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 2:
                        if (!(dia >= 1 && dia <= 28))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 3:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 4:
                        if (!(dia >= 1 && dia <= 30))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 5:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 6:
                        if (!(dia >= 1 && dia <= 30))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 7:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 8:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 9:
                        if (!(dia >= 1 && dia <= 30))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 10:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 11:
                        if (!(dia >= 1 && dia <= 30))
                        {
                            retorno = FALSE;
                        }
                        break;
                    case 12:
                        if (!(dia >= 1 && dia <= 31))
                        {
                            retorno = FALSE;
                        }
                        break;
                    default:
                        retorno = FALSE;
                }
            } else
            {
                retorno = FALSE;
            }
        }
    }
    return retorno;
}

int isValidFechaArchivo (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                if (buffer[i] != '/')
                {
                    retorno = FALSE;
                }
            }
        }
    }
    return retorno;
}

int isCuitArchivo (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                if (buffer[i] != '-')
                {
                    retorno = FALSE;
                }
            }
        }
    }
    return retorno;
}

int isValidId (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}



int isValidFLoatStr(char* buffer)
{
    int retorno = FALSE;
    int flag = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                if(buffer[i] != '.')
                {
                    retorno = FALSE;
                }
            }
        }
    }
    return retorno;
}
