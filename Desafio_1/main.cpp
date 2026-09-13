#include <iostream>
#include "memoria.h"
#include "fichas.h"
using namespace std;

int main()
{
    // int filas = 3, columnas = 3;
    // unsigned char* memoria = reservarMemoria(filas, columnas);

    // // Prueba caso simple
    // escribirFicha(memoria, 0, 0, columnas, 5);
    // unsigned char r1 = leerFicha(memoria, 0, 0, columnas); // debería ser 5

    // // Prueba con varias fichas para forzar casos repartidos entre bytes
    // for (int f = 0; f < filas; f++)
    //     for (int c = 0; c < columnas; c++)
    //         escribirFicha(memoria, f, c, columnas, (f+c) % 6); // valores 0-5

    // bool ok = true;
    // for (int f = 0; f < filas; f++)
    //     for (int c = 0; c < columnas; c++)
    //         if (leerFicha(memoria, f, c, columnas) != (f+c) % 6)
    //             ok = false;


    // delete[] memoria;
    // return 0;
}
