#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


typedef struct
{
    int idPublicidad;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char cuit[TEXT_SIZE];
    int contrataciones;
    int importeTotal;
}Cliente;


int Informes_listarPantallasPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado);
int Informes_listarFacturacionPorCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ, char* cuitBuscado);
int Informes_listarContrataciones(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ);
int Informes_listarCuit(Publicidad arrayPublicidad[], Pantalla arrayPantalla[], int sizeI, int sizeJ);


#endif // INFORMES_H_INCLUDED
