#include "memoria.h"
#include "fichas.h"
#include "tablero.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    int filas = 5, columnas = 5;
    unsigned char* memoria = reservarMemoria(filas, columnas);

    llenarTablero(memoria, filas, columnas);
    mostrarTablero(memoria, filas, columnas);

    delete[] memoria;
    return 0;
}
