#include "tablero.h"
#include "fichas.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int generarFichaAleatoria()
{
    return rand()%6;            //valores 0 a 5, distribución uniforme

}

void llenarTablero(unsigned char *memoria, int filas, int columnas)
{
    for (int f=0; f< filas; f++)
    {
        for(int c=0; c< columnas; c++)
        {
            escribirFicha(memoria, f,c,columnas, generarFichaAleatoria());
        }
    }

}

char fichasAcaracteres(unsigned char valor)
{
    switch(valor)
    {
    case 0: return 'A';
    case 1: return 'B';
    case 2: return 'C';
    case 3: return 'D';
    case 4: return 'E';
    case 5: return 'F';
    case 6: return '.'; // estado libre
    default: return '*'; // estado especial (7)
    }
}

void mostrarTablero(unsigned char *memoria, int filas, int columnas)
{
    for(int f=0; f<filas; f++)
    {
        for (int c=0; c<columnas; c++)
        {
            unsigned char valor= leerFicha(memoria, f,c,columnas);
            cout <<fichasAcaracteres(valor)<< " ";

        }
        cout <<endl;
    }
}

void reorganizarTablero(unsigned char *memoria, int filas, int columnas)
{
    for (int c=0; c<columnas; c++)
    {
        int destino = filas -1;         //inicia en la ultima fila (la mas baja)
        for (int f=filas-1; f>=0;f--)
        {
            unsigned char valor = leerFicha(memoria,f,c,columnas);

            if(valor<=5)    //fichas validas, no vacias
            {
                if(f!=destino)
                {
                    escribirFicha(memoria,destino,c,columnas,valor);
                    escribirFicha(memoria,f,c,columnas,6);  //va dejando vacio el lugar viejo
                }
                destino--;
            }
        }
        //va rewllenando con fichas nuevas todo lo que va quedando vacio arriba
        while (destino >=0)
        {
            escribirFicha(memoria, destino, c,columnas,generarFichaAleatoria());
            destino--;
        }
    }
}


void mostrarTableroBinario(unsigned char *memoria, int filas, int columnas)
{
    for (int f=0; f<filas; f++)
    {
        for(int c=0;c<columnas; c++)
        {
            unsigned char valor = leerFicha(memoria,f,c,columnas);
            for (int b=2; b>=0; b--)
                cout<< ((valor >>b)&1);
            cout<<" ";
        }

        cout<<endl;
    }
}
