#include "eliminaciones.h"
#include "fichas.h"

void eliminarFicha(unsigned char *memoria, int fila, int columna, int columnas)
{
    escribirFicha(memoria, fila, columna, columnas, 6);     //6 estado libre
}
