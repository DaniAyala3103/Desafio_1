#include "fichas.h"

int calcularByte(int fila, int columna, int columnas)
{
    int indice= fila*columnas+columna;
    int bitInicial= indice *3;
    return bitInicial /8;
}

int posicionEnByte(int fila, int columna, int columnas)
{
    int indice = fila*columnas+columna;
    int bitInicial = indice*3;
    return bitInicial %8;
}
