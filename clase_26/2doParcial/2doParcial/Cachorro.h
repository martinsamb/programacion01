#ifndef CACHORRO_H_INCLUDED
#define CACHORRO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[5];
    char genero[5];

}Cachorro;

Cachorro* newCachorro();

int deleteCachorro(Cachorro* this);

int getId(Cachorro* this,int* id);
int setId(Cachorro* this,int id);

int getNombre(Cachorro* this,char* nombre);
int setNombre(Cachorro* this,char* nombre);

int getDias(Cachorro* this,int* dias);
int setDias(Cachorro* this,int dias);

int getRaza(Cachorro* this,char* raza);
int setRaza(Cachorro* this,char* raza);

int getReservado(Cachorro* this,char* reservado);
int setReservado(Cachorro* this,char* reservado);

int getGenero(Cachorro* this,char* genero);
int setGenero(Cachorro* this,char* genero);

void cahorro_menores45(void* pElement);

/*
int problema1(void* elemento);
int problema2(void* elemento);
int problema3(void* elemento);
int problema4(void* elemento);
int problema5(void* elemento);
*/


#endif // CACHORRO_H_INCLUDED
