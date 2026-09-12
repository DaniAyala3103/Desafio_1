#ifndef FICHAS_H
#define FICHAS_H

int calcularByte(int fila, int columna, int columnas);
int posicionEnByte(int fila, int columna, int columnas);

unsigned char leerFicha(unsigned char* memoria, int fila, int columna, int columnas);
void escribirFicha(unsigned char* memoria, int fila, int columna, int columnas, unsigned char valor);

#endif // FICHAS_H
