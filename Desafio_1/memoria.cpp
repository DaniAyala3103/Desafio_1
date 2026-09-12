#include "memoria.h"

int calcularbytes(int filas, int columnas)
{
    int cantidadFichas= filas * columnas;
    int cantidadBits = cantidadFichas *3;

    int cantidadBytes= cantidadBits/8;

    if(cantidadBits %8 !=0)
    {
        cantidadBytes++;

    }
    return cantidadBytes;
}
