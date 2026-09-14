#include "eliminaciones.h"
#include "fichas.h"


bool posicionValida(int fila, int columna, int filas, int columnas)
{
    return (fila>=0 && fila < filas && columna >=0 && columna < columnas);
}

void eliminarFicha(unsigned char *memoria, int fila, int columna, int columnas)
{
    escribirFicha(memoria, fila, columna, columnas, 6);     //6 estado libre
}

