#include<stdio.h>

int mail()
{
    long edad,aux;
    long *p;
    long *p1;
    long *pAux;

    edad=50;
    p = &edad;

    p1=p;

    printf("La edad es %ld\n",edad);
    printf("Dierccion de memoria de edad: %p",edad);
    printf("p es %p\n",p);
    printf("p1 es %p\n",p1);
    printf("p es %d\n",*p);
    printf("*p1 es %d\n",*p1);

}
