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

unsigned char leerFicha(unsigned char *memoria, int fila, int columna, int columnas)
{
    int byte= calcularByte(fila,columna,columnas);
    int pos = posicionEnByte(fila,columna,columnas);

    unsigned char valor;
    if(pos <= 5)
    {
        //caso ideal donde la ficha cabe perfectamente en un solo byte
        valor=(memoria[byte]>>(5-pos))&7;

    }
    else if (pos==6)
    {
        //caso con 2 bits en memoria[byte], 1 bit en memoria[byte+1]
        unsigned char parteAlta=memoria[byte]&3;        //los 2 bits menos significativos de este byte
        unsigned char parteBaja=(memoria[byte+1]>>7)&1; //el bit mas significativo del siguiente byte
        valor = (parteAlta<<1)|parteBaja;
    }
    else //pos ==7
    {
        //caso con 1 bit en memoria[byte], 2 bits en memoria[byte+1]
        unsigned char parteAlta=memoria[byte]&1;            //el bit menos significativo de este byte
        unsigned char parteBaja=(memoria[byte+1]>>6)&3;     //los 2 bits mas significativos del siguiente byte
        valor = (parteAlta<<2)| parteBaja;
    }

    return valor;
}

void escribirFicha(unsigned char *memoria, int fila, int columna, int columnas, unsigned char valor)
{
    int byte = calcularByte(fila, columna, columnas);
    int pos= posicionEnByte(fila, columna,columnas);

    if(pos<=5)
    {
        //caso ideal en el que la ficha cabe perfectamente en un solo byte
        unsigned char mascara = ~(7<<(5-pos));
        memoria[byte]=(memoria[byte]&mascara)|(valor<<(5-pos));

    }
    else if (pos ==6)
    {
        //caso con 2 bits en memoria[byte], 1 bit en memoria[byte+1]
        unsigned char parteAlta= (valor>>1)&3;  //los 2 bits mas significativos del valor.
        unsigned char parteBaja= valor&1;   //el bit menos significativo del valor
        memoria[byte] = memoria[byte]&~3 | parteAlta;
        memoria[byte+1]= (memoria[byte+1]& ~(1<<7)) | (parteBaja<<7);

    }
    else //pos ==7
    {
        //caso 1 bit en moemoria[byte] y 2 en memoria[byte+1]
        unsigned char parteAlta =(valor>>2)&1;        //el bit mas significativo
        unsigned char parteBaja = valor & 3;                    //los 2 bits menos significativos
        memoria[byte]=(memoria[byte]& ~1)|parteAlta;
        memoria[byte+1]=(memoria[byte+1]& ~(3<<6))|(parteBaja<<6);
    }
}
