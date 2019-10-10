typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int fecha;
    int isEmpty;
}eAlquiler;

int alquiler_findEmpty (eAlquiler* arrayAlquiler,int limite, int* resultado);
int alquiler_initStruct(eAlquiler* arrayAlquiler, int limite);
