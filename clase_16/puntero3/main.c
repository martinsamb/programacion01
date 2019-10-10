#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[8]={10,11,12,13,14,15,16,17};
    int *pVec;
    int i;

    pVec = &vec[0];

    for(i=0;i<8;i++)
    {
        printf("\n->Posicion %d->Valor %d",i,vec[i]);
    }
    //Acceder al5to elemento con notacion vectorial
    printf("\n->5ta Posicion %d",vec[4]);

    //Acceder sal 5to elemento con aritmetica de punteros
    printf("\n->5ta Posicion %d",pVec[4]);

    //Recorrido con Aritmetica de Punteros
    for(i=0;i<8;i++)
    {
        printf("\n->5ta Posicion %d",pVec[4]);
    }

    return 0;
}
