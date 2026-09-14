#include "memoria.h"
#include "fichas.h"
#include "tablero.h"
#include "eliminaciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "combinaciones.h"

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



    int filaJugador, columnaJugador;
    do
    {
        cout <<"ingrese la fila de la ficha a eliminar: ";
        cin >>filaJugador;

        if (filaJugador <1 || filaJugador > filas)
            cout <<"fila invalida, intentalo de nuevo."<<endl;

    }while(filaJugador<1||filaJugador>filas);

    do
    {
        cout<<"Ingrese la columna de la ficha a eliminar: ";
        cin >>columnaJugador;

        if(columnaJugador<1||columnaJugador>columnas)
            cout<<"columna invalida, intente de nuevo."<<endl;


    }
    while(columnaJugador <1 || columnaJugador >columnas);

    //convertimos el indice internamente(0 a filas-1, 0 a columnas-1) antes de usarlass
    eliminarFicha(memoria, filaJugador -1,columnaJugador-1,columnas);



    cout<<"tablero despues de eliminar: "<<endl;
    mostrarTablero(memoria,filas,columnas);

    //por acá vamos metiendo la deteccion y eliminacion de combinaciones
    bool *marcas=crearMarcas(filas,columnas);
    marcasHorizontales(memoria, filas,columnas,marcas);
    marcasVerticales(memoria,filas,columnas,marcas);

    if(hayCombinaciones(marcas, filas,columnas))
    {
        int eliminadas = eliminarMarcadas(memoria,filas,columnas,marcas);
        cout<<"se eliminaron "<<eliminadas << " fichas por combinacion. "<<endl;
        mostrarTablero(memoria,filas,columnas);
    }

    else
    {
        cout<<">>>No se generaron combinaciones."<<endl;
    }
    liberarMarcas(marcas);

    delete[] memoria;
    return 0;
}
