#include "memoria.h"
#include "fichas.h"
#include "tablero.h"
#include "eliminaciones.h"
#include "iostream"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int filas, columnas;
    cout<<"Ingrese una cantidad de filas: ";
    cin >>filas;
    cout<<"Ingrese una cantidad de columnas: ";
    cin >>columnas;

    unsigned char *memoria =reservarMemoria(filas,columnas);
    llenarTablero(memoria, filas, columnas);
    mostrarTablero(memoria, filas, columnas);

    delete[] memoria;
    return 0;
}
