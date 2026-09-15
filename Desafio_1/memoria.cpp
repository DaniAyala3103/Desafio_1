#include "memoria.h"
#include "fichas.h"
#include "tablero.h"

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

unsigned char* reservarMemoria(int filas, int columnas)
{
    int cantidadBytes = calcularbytes(filas, columnas);
    unsigned char* memoria = new unsigned char[cantidadBytes];

    return memoria;
}

unsigned char* agregarFila(unsigned char *memoria, int filas, int columnas, int filaInsertar, int *capacidadBytes)
{
    int nuevasFilas = filas +1;
    int bytesNecesarios = calcularbytes(nuevasFilas, columnas);

    unsigned char* temporal = new unsigned char[bytesNecesarios];
    for (int i=0; i<bytesNecesarios;i++)
        temporal[i]=0;
    int fOrigen = 0;
    for (int fDestino=0; fDestino<nuevasFilas; fDestino++)
    {
        if (fDestino == filaInsertar)
        {
            for(int c=0; c<columnas; c++)
            escribirFicha(temporal,fDestino,c,columnas,generarFichaAleatoria());

        }
        else
        {
            for(int c=0; c<columnas; c++)
            {
                unsigned char valor =leerFicha(memoria,fOrigen, c,columnas);
                escribirFicha(temporal,fDestino,c,columnas,valor);
            }
            fOrigen++;
        }
    }
    if(bytesNecesarios > *capacidadBytes)
    {
        delete[] memoria;
        *capacidadBytes = bytesNecesarios;
        return temporal;
    }
    else
    {
        for(int i=0; i<bytesNecesarios; i++)
            memoria[i]=temporal[i];
        delete []temporal;
        return memoria;
    }
}


unsigned char* eliminarFila(unsigned char *memoria, int filas, int columnas, int filaEliminar, int *capacidadBytes)
{
    int nuevasFilas=filas-1;
    int bytesNecesarios = calcularbytes(nuevasFilas,columnas);

    unsigned char* temporal =new unsigned char[bytesNecesarios];
    for(int i=0; i<bytesNecesarios; i++)
        temporal[i]=0;

    int fDestino=0;
        for(int fOrigen=0; fOrigen<filas;fOrigen++)
    {
        if (fOrigen ==filaEliminar)
            continue;
        for(int c=0; c<columnas ;c++)
        {
            unsigned char valor = leerFicha(memoria,  fOrigen, c, columnas);
            escribirFicha(temporal, fDestino, c, columnas, valor);
        }
        fDestino++;
    }
    double uso= (double)bytesNecesarios/(double)(*capacidadBytes);
    if(uso <0.65)       //regla del 65% que nos exige el desafio
    {
        delete[] memoria;
        *capacidadBytes = bytesNecesarios;
        return temporal;
    }
    else
    {
        for(int i=0; i< bytesNecesarios; i++)
            memoria[i]=temporal[i];
        delete[] temporal;
        return memoria;
    }
}

unsigned char* agregarColumna(unsigned char *memoria, int filas, int columnas, int columnaInsertar, int *capacidadBytes)
{
    int nuevasColumnas= columnas +1;
    int bytesNecesarios= calcularbytes(filas,nuevasColumnas);

    unsigned char* temporal =new unsigned char[bytesNecesarios];
    for(int i= 0; i<bytesNecesarios; i++)
        temporal[i]=0;

    for(int f=0; f<filas; f++)
    {
        int cOrigen =0;
        for(int cDestino=0; cDestino<nuevasColumnas;cDestino++)
        {
            if(cDestino==columnaInsertar)
            {
                escribirFicha(temporal,f,cDestino,nuevasColumnas, generarFichaAleatoria());

            }
            else
            {
                unsigned char valor=leerFicha(memoria, f,cOrigen,columnas);
                escribirFicha(temporal, f, cDestino, nuevasColumnas, valor);
                cOrigen++;
            }
        }
    }
    if(bytesNecesarios > *capacidadBytes)
    {
        delete[] memoria;
        *capacidadBytes = bytesNecesarios;
        return temporal;
    }
    else
    {
        for(int i=0; i<bytesNecesarios; i++)
            memoria[i]=temporal[i];
        delete[]temporal;
        return memoria;
    }
}

unsigned char* eliminarColumna(unsigned char *memoria, int filas, int columnas, int columnaEliminar, int *capacidadBytes)
{
    int nuevasColumnas = columnas -1;
    int bytesNecesarios = calcularbytes(filas, nuevasColumnas);

    unsigned char* temporal= new unsigned char[bytesNecesarios];
    for(int i=0; i<bytesNecesarios; i++)
        temporal[i]=0;
    for(int f=0;f<filas;f++)
    {
        int cDestino=0;
        for(int cOrigen=0; cOrigen<columnas;cOrigen++)
        {
            if (cOrigen ==columnaEliminar)
                continue;

            unsigned char valor=leerFicha(memoria, f, cOrigen, columnas);
            escribirFicha(temporal, f,cDestino, nuevasColumnas, valor);
            cDestino++;
        }
    }

    double uso=(double)bytesNecesarios/(double)(*capacidadBytes);
    if (uso<0.65)
    {
        delete[] memoria;
        *capacidadBytes = bytesNecesarios;
        return temporal;
    }
    else
    {
        for(int i=0; i<bytesNecesarios; i++)
            memoria[i]=temporal[i];
        delete[]temporal;
        return memoria;

    }
}
