#include "combinaciones.h"
#include "fichas.h"

bool *crearMarcas(int filas, int columnas)
{
    bool *marcas =new bool[filas *columnas];
    for(int i=0; i<filas*columnas; i++)
        marcas[i]=false;
    return marcas;
}
void liberarMarcas(bool *marcas)
{
    delete[]marcas;
}

void marcasHorizontales(unsigned char *memoria, int filas, int columnas, bool *marcas)
{
    for(int f=0; f < filas; f++)
    {
        int c=0;
        while (c<columnas)
        {
            unsigned char valor =leerFicha(memoria, f, c, columnas);
            int inicio = c;

            while(c< columnas && leerFicha(memoria,f,c,columnas)==valor)
                c++;

            int largo =c-inicio;

            if(valor<= 5&& largo>=3)// solo fichas validas, no vacio ni especial.
            {
                for (int k=inicio; k<c; k++)
                    marcas[f*columnas+k]=true;

            }
        }
    }
}

bool hayCombinaciones(bool *marcas, int filas, int columnas)
{
    for(int i=0; i<filas*columnas; i++)
        if(marcas[i])
            return true;
    return false;
}

void marcasVerticales(unsigned char *memoria, int filas, int columnas, bool *marcas)
{
    for(int c=0; c<columnas; c++)
    {
        int f=0;
        while(f<filas)
        {
            unsigned char valor =leerFicha(memoria, f,c,columnas);
            int inicio = f;

            while(f<filas && leerFicha(memoria,f,c,columnas)==valor)
                f++;

            int largo = f-inicio;

            if(valor<= 5&& largo>=3)        //solo reciba fichas validas, nada de vacio o especiales.
            {
                for(int k=inicio; k<f; k++)
                    marcas[k*columnas+c]=true;
            }
        }
    }
}

