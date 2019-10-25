#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    Cliente* listClientes[1000];//obtengo un array de puntero de tipo clientes
    int posicion = 0;
    for(i = 0; i < 1000; i++)//Inicializa con NULL el array
        listaClientes[i] = NULL;

 FILE *pFile;
 int r;
 char var1[50],var3[50],var2[50],var4[50];
 pFile = fopen("clientes.txt","r");
 if(pFile == NULL)
 {
 printf("El archivo no existe");
 exit(EXIT_FAILURE);
 }
 do
 {
 r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
 if(r==4)
 {
     printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
     //Hacer un new para generar un cliente
     //cargar los campos con los datos
     //guardar las addr en la lista
     int id = atoi(var1);
     Cliente* pc = new_clienteParametros(var2,var4,var5,var3,i,1);
     if(pc! = NULL)
     {
         listaClientes[posicion] = pc;
         posicion++;
         if(posicion>=1000)
            break;
     }

 }
 else
 break;
 }while(!feof(pFile));
 fclose(pFile);
 exit(EXIT_SUCCESS);
}
