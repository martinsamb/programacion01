#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     FILE *pFile;
     int r;
     int a,b,c,d;
     pFile = fopen("data.csv","r");
     if(pFile == NULL)
 {
     printf("El archivo no existe");
     exit(EXIT_FAILURE);
 }
 do
 {
     r = fscanf(pFile,"%d,%d,%d,%d\n",&a,&b,&c,&d);
     if(r==4){
     printf("Lei %d %d %d %d\n",a,b,c,d);
 }
     else
     break;
 }while(!feof(pFile));
     fclose(pFile);
     exit(EXIT_SUCCESS);
}

int parseData(char* fileName,Persona* arrayPersonas, int len)
{
     FILE *pFile;
     int r,i=0;
     char var1,var3[50],var2,var4;
     pFile = fopen(fileName,"r");
     if(pFile == NULL)
     {
        return -1;
     }
     do
     {
        r = fscanf(pFile,"%d,%[^,],%d,%d\n",var1,var2,var3,var4);
         if(r==4)
         {
             arrayPersonas[i].id = atoi(var1);
             strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
             strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
             arrayPersonas[i].edad = atoi(var4);
             i++;
         }
         else
         break;
     }while(!feof(pFile) && i<len);
         fclose(pFile);
         return i;
}


